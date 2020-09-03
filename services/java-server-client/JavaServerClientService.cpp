#include "JavaServerClientService.h"
#include "requests/RequestPayload.h"

#include <QMap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <functional>

JavaServerClientService::JavaServerClientService() {
//    socket = new QTcpSocket(this);

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

void JavaServerClientService::start() {
    qDebug() << __PRETTY_FUNCTION__;

    emit startBridge();

//    socket->connectToHost("localhost", 9991);
//    if(socket->waitForConnected(3000)) {
//        qDebug() << "Connected!";

//        // send
//        socket->write("hello server\r\n\r\n\r\n\r\n");
//        socket->waitForBytesWritten(1000);
//        socket->waitForReadyRead(3000);
//        qDebug() << "Reading: " << socket->bytesAvailable();

//        qDebug() << socket->readAll();

////        socket->close();
//    } else {
//        qDebug() << "Not connected!";
//    }
}

void JavaServerClientService::stop() {
    qDebug() << __PRETTY_FUNCTION__;

    emit stopBridge();
}

void JavaServerClientService::send(const QString& data) {
    qDebug() << __PRETTY_FUNCTION__;

    // ===
    QMap<QString, std::any> values;
    values.insert("a", 1);
    values.insert("b", 2);

    QString serializedValues =
            "\"a\":\"" + QString::number(std::any_cast<int>(values.value("a"))) + "\","
            "\"b\":\"" + QString::number(std::any_cast<int>(values.value("a"))) + "\"" ;

    RequestPayload payload(values, serializedValues);

    QByteArray ba(payload.toByteArrayNoCRLF());

    qDebug() << __PRETTY_FUNCTION__ << QString(ba);
    // ===

//    emit sendData(data.toUtf8());

//    std::function<void(const QString&)> f1 = [] (const QString& s) {
//        qDebug() << __PRETTY_FUNCTION__ << "->FROM_F1";
//    };
//    std::function<void(const QString&)> f2 = [] (const QString& s) {
//        qDebug() << __PRETTY_FUNCTION__ << "->FROM_F2";
//    };
//    std::function<void(const QString&)> f3 = [] (const QString& s) {
//        qDebug() << __PRETTY_FUNCTION__ << "->FROM_F3";
//    };

//    QMap<int, std::function<void(const QString&)>> map;
//    map.insert(1, f1);
//    map.insert(2, f2);
//    map.insert(3, f3);

//    QList<std::function<void(const QString&)>> list = map.values();
//    for (int i = 0; i < list.length(); ++i) {
//        list.at(i)("STR");
//    }
//    qDebug() << "";

//    map.remove(2);

//    list = map.values();
//    for (int i = 0; i < list.length(); ++i) {
//        list.at(i)("STR");
//    }
//    qDebug() << "";
}

void JavaServerClientService::runLongRunningTask() {
    qDebug() << __PRETTY_FUNCTION__;

    emit sendData(mServerActions.runLongRunningTaskAction());
}

void JavaServerClientService::onDataReceived(const QString& data) {
    qDebug() << __PRETTY_FUNCTION__ << "->DATA: " + data;

    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    if (doc.isNull()) {
        qDebug() << __PRETTY_FUNCTION__ << "->DOC_IS_NULL";
    } else {
        qDebug() << __PRETTY_FUNCTION__ << "->DOC_NOT_NULL";

        if (doc.isObject()) {
            QJsonObject object = doc.object();

            QJsonValue type = object.value("type");
            QJsonValue values = object.value("values");

            QString typeString = type.toString();

            QJsonObject valuesObject = values.toObject();

            QString aValue = valuesObject.value("a").toString();
            QString bValue = valuesObject.value("b").toString();

            qDebug() << __PRETTY_FUNCTION__ << ": " << typeString << aValue << bValue;
        } else {
            qDebug() << __PRETTY_FUNCTION__ << "DOC_NOT_OBJECT";
        }
    }
}
