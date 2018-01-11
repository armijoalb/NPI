#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <serverthread.h>

class tcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit tcpServer(QObject *parent = nullptr);
    void StartServer();

signals:

public slots:
    void incomingConnection(int socketDescriptor);
private:
    QTcpServer * mServer;
    int serverPort = 4000;

};

#endif // TCPSERVER_H
