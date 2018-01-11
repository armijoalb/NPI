#include "tcpserver.h"

tcpServer::tcpServer(QObject *parent) : QTcpServer(parent)
{
    if(!this->listen(QHostAddress::Any,serverPort))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening...";
    }

}

void tcpServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    serverThread *thread = new serverThread(socketDescriptor,this);
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start();
}
