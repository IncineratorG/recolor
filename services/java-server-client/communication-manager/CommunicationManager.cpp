#include "CommunicationManager.h"

#include <QDebug>

CommunicationManager::CommunicationManager() {
    mIdsCounter = 1;

    mBridge = new Bridge();

    connect(this,
            SIGNAL(startBridge()),
            mBridge,
            SLOT(on()));
    connect(this,
            SIGNAL(stopBridge()),
            mBridge,
            SLOT(off()));
    connect(this,
            SIGNAL(sendData(const QByteArray&)),
            mBridge,
            SLOT(send(const QByteArray&)));
    connect(mBridge,
            SIGNAL(received(const QString&)),
            this,
            SLOT(onDataReceived(const QString&)));


    mBridge->moveToThread(&mThread);
    mThread.start();
}

void CommunicationManager::start() {
    emit startBridge();
}

void CommunicationManager::stop() {
    emit stopBridge();
}

void CommunicationManager::sendRequest(const Request& request) {
    qDebug() << __PRETTY_FUNCTION__;

    emit sendData(request.toByteArray());
}

QString CommunicationManager::onIncomingMessage(std::function<void (ServerMessage)> consumer) {
    mIdsCounter = mIdsCounter + 1;
    QString id = QString::number(mIdsCounter);

    mServerMessageConsumers.insert(id, consumer);

    return id;
}

void CommunicationManager::unsubscribe(const QString& consumerId) {
    mServerMessageConsumers.remove(consumerId);
}

void CommunicationManager::onDataReceived(const QString& data) {
    qDebug() << __PRETTY_FUNCTION__ << data;

    ServerMessage serverMessage = mServerMessageParser.parse(data);
}

void CommunicationManager::notifyMessageConsumers(const ServerMessage& serverMessage) {
    const QList<std::function<void (ServerMessage)>> messageConsumers = mServerMessageConsumers.values();
    for (int i = 0; i < messageConsumers.size(); ++i) {
        try {
            messageConsumers.at(i)(serverMessage);
        } catch (std::exception e) {
            qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION";
        }
    }
}
