#include "myserver.h"
#include <ctime>

MyServer::MyServer(QWidget *widget, QObject *parent) :QTcpServer(parent)
{
    srand(time(0));
    _widget = widget;
}

bool MyServer::doStartServer(QHostAddress addr, qint16 port)
{
    if (!listen(addr, port))
    {
        qDebug() << "Server not started at" << addr << ":" << port;
        return false;
    }
    qDebug() << "Server started at" << addr << ":" << port;
    return true;
}

void MyServer::doSendToAllUserJoin(QString name)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    //����������� ����� ��� ������ �����
    out << (quint16)0 << MyClient::comUserJoin << name;
    //����� �� ����������������� ����� ������ �����
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    //���������� ���� ��������������, ����� ����, ��� �����
    for (int i = 0; i < _clients.length(); ++i)
        if (_clients.at(i)->getName() != name && _clients.at(i)->getAutched())
            _clients.at(i)->_sok->write(block);
}

void MyServer::doSendToAllUserLeft(QString name)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << MyClient::comUserLeft << name;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    for (int i = 0; i < _clients.length(); ++i)
        if (_clients.at(i)->getName() != name && _clients.at(i)->getAutched())
            _clients.at(i)->_sok->write(block);
}

void MyServer::doSendToAllMessage(QString message, QString fromUsername)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << MyClient::comMessageToAll << fromUsername << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    for (int i = 0; i < _clients.length(); ++i)
        if (_clients.at(i)->getAutched())
            _clients.at(i)->_sok->write(block);
}

void MyServer::doSendToAllServerMessage(QString message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << MyClient::comPublicServerMessage << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    for (int i = 0; i < _clients.length(); ++i)
        if (_clients.at(i)->getAutched())
            _clients.at(i)->_sok->write(block);
}

void MyServer::doSendServerMessageToUsers(QString message, const QStringList &users)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << MyClient::comPrivateServerMessage << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    for (int j = 0; j < _clients.length(); ++j)
        if (users.contains(_clients.at(j)->getName()))
            _clients.at(j)->_sok->write(block);
}

void MyServer::doSendServerMessageToUsers(QString message, MyClient* client)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << MyClient::comPrivateServerMessage << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    client->_sok->write(block);
}

void MyServer::doSendMessageToUsers(QString message, const QStringList &users, QString fromUsername)
{
    QByteArray block, blockToSender;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0 << MyClient::comMessageToUsers << fromUsername << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    //����, ��� �������� ����� ��������� �� ��� ���, � ������ ���, ���� �� ��������
    QDataStream outToSender(&blockToSender, QIODevice::WriteOnly);
    outToSender << (quint16)0 << MyClient::comMessageToUsers << users.join(",") << message;
    outToSender.device()->seek(0);
    outToSender << (quint16)(blockToSender.size() - sizeof(quint16));
    for (int j = 0; j < _clients.length(); ++j)
        if (users.contains(_clients.at(j)->getName()))
            _clients.at(j)->_sok->write(block);
        else if (_clients.at(j)->getName() == fromUsername)
            _clients.at(j)->_sok->write(blockToSender);
}

QStringList MyServer::getUsersOnline() const
{
    QStringList l;
    foreach (MyClient * c, _clients)
        if (c->getAutched())
            l << c->getName();
    return l;
}

bool MyServer::isNameValid(QString name) const
{
    if (name.length() > 20 || name.length() < 1)
        return false;
    QRegularExpression r("[A-Za-z0-9_]+");
    return r.match(name).hasMatch();
}

bool MyServer::isNameUsed(QString name) const
{
    for (int i = 0; i < _clients.length(); ++i)
        if (_clients.at(i)->getName() == name)
            return true;
    return false;
}

void MyServer::incomingConnection(qintptr handle)
{
    MyClient *client = new MyClient(handle, this, this);
    /*if (_widget != 0)
    {
        connect(client, SIGNAL(addUserToGui(QString)), _widget, SLOT(onAddUserToGui(QString)));
        connect(client, SIGNAL(removeUserFromGui(QString)), _widget, SLOT(onRemoveUserFromGui(QString)));
        connect(client, SIGNAL(messageToGui(QString,QString,QStringList)), _widget, SLOT(onMessageToGui(QString,QString,QStringList)));
    }*/
    connect(client, SIGNAL(removeUser(MyClient*)), this, SLOT(onRemoveUser(MyClient*)));
    _clients.append(client);
    if(_clients.size() > 0 && _clients.size() % 2 == 0)
    {
        bool color = rand() % 2;
        _clients[_clients.size() - 2]->set_interlocutor(_clients.back());
        _clients[_clients.size() - 2]->set_color(color);
        _clients.back()->set_interlocutor(_clients[_clients.size() - 2]);
        _clients.back()->set_color(!color);
    }
}

void MyServer::onRemoveUser(MyClient *client)
{
    if(client->_interlocutor != nullptr)
        client->_interlocutor->_interlocutor = nullptr;
    _clients.removeAt(_clients.indexOf(client));
}

void MyServer::onMessageFromGui(QString message, const QStringList &users)
{
    if (users.isEmpty())
        doSendToAllServerMessage(message);
    else
        doSendServerMessageToUsers(message, users);
}
