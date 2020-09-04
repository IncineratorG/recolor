#include "Bridge.h"
#include "../actions/ServerActions.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

Bridge::Bridge() {
    counter = 0;

//    mTimer = new QTimer(this);

//    connect(mTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    mSocket = new QTcpSocket(this);

    connect(mSocket, SIGNAL(connected()),this, SLOT(connected()));
    connect(mSocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(mSocket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(mSocket, SIGNAL(readyRead()),this, SLOT(readyRead()));
}

//Bridge::~Bridge() {

//}

void Bridge::on() {
    qDebug() << __PRETTY_FUNCTION__;
//    mTimer->start(1000);

    mSocket->connectToHost("localhost", 9991);
    if(!mSocket->waitForConnected(3000))
    {
        qDebug() << "Error: " << mSocket->errorString();
    }
}

void Bridge::off() {
    qDebug() << __PRETTY_FUNCTION__;
//    mTimer->stop();

//    mSocket->close();

    QString s("bye\r\n");
    QByteArray ba = s.toUtf8();

//    ServerActions serverActions;

    mSocket->write(ba);

    bool result = mSocket->waitForBytesWritten();
    qDebug() << __PRETTY_FUNCTION__ << "->WRITE_RESULT: " << result;

    mSocket->disconnect();
    mSocket->disconnectFromHost();
}

void Bridge::send(const QByteArray& data) {
    qDebug() << __PRETTY_FUNCTION__;

//    ServerActions serverActions;

    mSocket->write(data);
    mSocket->flush();

////    QString s("MY_TEST_STRING\r\n");
//    QString s("\"TYPE: FIRST_ACTION\"\r\n");
//    QString ss("{\"a\":11,\"s\":\"string\",\"list\":[\"A\",\"B\",\"C\"]}\r\n");
//    QByteArray ba = ss.toUtf8();

//    mSocket->write(ba);
//    mSocket->flush();

//    mSocket->write("\r\n");

//    bool result = mSocket->waitForBytesWritten();
//    qDebug() << __PRETTY_FUNCTION__ << "->WRITE_RESULT_1: " << result;

//    mSocket->write("\r\n");

//    result = mSocket->waitForBytesWritten();
//    qDebug() << __PRETTY_FUNCTION__ << "->WRITE_RESULT_2: " << result;
}
// ===
// =====
//void Bridge::send(const QString& data) {
//    qDebug() << __PRETTY_FUNCTION__ << "->DATA: " + data;

//    sendJson();
//}

void Bridge::sendJson() {
//    QString ("{TYPE: FIRST_ACTION}");

    QJsonObject object;
    object.insert("\"TYPE\"", QJsonValue::fromVariant("\"FIRST_ACTION\""));

    QJsonDocument doc(object);
    QByteArray ba = doc.toBinaryData();

    qDebug() << ba;

    mSocket->write(ba);
    mSocket->flush();

    QString s("\r\n");
    ba = s.toUtf8();

    mSocket->write(ba);
    mSocket->flush();
}
// =====
// ===

void Bridge::onTimeout() {
    qDebug() << __PRETTY_FUNCTION__;
    emit received(QString::number(++counter));
}

void Bridge::connected() {
    qDebug() << __PRETTY_FUNCTION__;
}

void Bridge::disconnected() {
    qDebug() << __PRETTY_FUNCTION__;
}

void Bridge::bytesWritten(qint64 bytes) {
    qDebug() << __PRETTY_FUNCTION__ << QString::number(bytes);
}

void Bridge::readyRead() {
    qDebug() << __PRETTY_FUNCTION__;

    QString data = mSocket->readAll();

//    qDebug() << __PRETTY_FUNCTION__ << data;
////    data = data.trimmed();
//    // ===
//    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

////    qDebug() << __PRETTY_FUNCTION__ << doc.isNull();

//    if (!doc.isNull()) {
//        if (doc.isObject()) {
//            QJsonObject obj = doc.object();

//            QJsonValue val = obj.value("list");
//            QJsonArray arr = val.toArray();
//            for (int i = 0; i < arr.size(); ++i) {
//                QString v = arr.at(i).toString();
//                qDebug() << "ARR_VAL: " << v;
//            }
//        } else {
//            qDebug() << __PRETTY_FUNCTION__ << "->DOC_IS_NOT_OBJECT";
//        }
//    }
//     ===

    emit received(data);
}
