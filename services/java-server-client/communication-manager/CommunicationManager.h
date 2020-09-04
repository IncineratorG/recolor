#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include "../requests/Request.h"
#include "../bridge/Bridge.h"
#include "../server-messages/ServerMessageParser.h"

#include <QThread>
#include <QObject>
#include <QMap>

#include <functional>

class CommunicationManager : public QObject
{
    Q_OBJECT

public:
    CommunicationManager();

    void start();
    void stop();

    void sendRequest(const Request& request);
    QString onIncomingMessage(std::function<void(ServerMessage)> consumer);

    void unsubscribe(const QString& consumerId);

signals:
    void startBridge();
    void stopBridge();
    void sendData(const QByteArray& data);

private slots:
    void onDataReceived(const QString& data);

private:
    int mIdsCounter;

    QMap<QString, std::function<void(ServerMessage)>> mServerMessageConsumers;
    QThread mThread;

    Bridge* mBridge;

    ServerMessageParser mServerMessageParser;

    void notifyMessageConsumers(const ServerMessage& serverMessage);
};

#endif // COMMUNICATIONMANAGER_H
