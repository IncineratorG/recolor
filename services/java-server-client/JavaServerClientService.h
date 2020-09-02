#ifndef JAVASERVERCLIENTSERVICE_H
#define JAVASERVERCLIENTSERVICE_H

#include "common/libs/service/Service.h"
#include "bridge/Bridge.h";
#include "actions/ServerActions.h"

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class JavaServerClientService : public QObject, public Service
{
    Q_OBJECT

public:
    JavaServerClientService();

    void start();
    void stop();
    void send(const QString& data);
    void runLongRunningTask();

signals:
    void startBridge();
    void stopBridge();
    void sendData(const QByteArray& data);

private slots:
    void onDataReceived(const QString& data);

private:
//    QTcpSocket *socket;
    QThread mThread;

    Bridge* mBridge;

    ServerActions mServerActions;
};

#endif // JAVASERVERCLIENTSERVICE_H
