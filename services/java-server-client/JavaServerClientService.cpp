#include "JavaServerClientService.h"

JavaServerClientService::JavaServerClientService() {
    socket = new QTcpSocket(this);
}

void JavaServerClientService::start() {
    qDebug() << __PRETTY_FUNCTION__;

    socket->connectToHost("localhost", 9991);
    if(socket->waitForConnected(3000)) {
        qDebug() << "Connected!";

        // send
        socket->write("hello server\r\n\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();

        qDebug() << socket->readAll();

//        socket->close();
    } else {
        qDebug() << "Not connected!";
    }
}
