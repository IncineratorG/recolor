#include "JavaServerClientService.h"

#include <QMap>

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
            SIGNAL(sendData(const QString&)),
            mBridge,
            SLOT(send(const QString&)));
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

    emit sendData(data);

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

void JavaServerClientService::onDataReceived(const QString& data) {
    qDebug() << __PRETTY_FUNCTION__ << "->DATA: " + data;
}
