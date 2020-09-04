#include "Request.h"

#include <QDebug>

Request::Request(const QString& type) {
    mUuid = QUuid::createUuid();
    mType = type;
}

Request::Request(const QString& type, const RequestPayload& payload) {
    mUuid = QUuid::createUuid();
    mType = type;
    mPayload = payload;
}

QString Request::getType() const {
    return mType;
}

QUuid Request::getUuid() const {
    return mUuid;
}

QByteArray Request::toByteArray() const {
    QString uuidField = "\"uuid\":";
    QString typeField = "\"type\":";

    QString openBrackets = "{";
    QString closeBrackets = "}";
    QString comma = ",";
    QString doubleQuotes = "\"";
    QString CRLF = "\r\n";

    QString serializedRequest;
    if (mPayload.isEmpty()) {
        serializedRequest =
                    openBrackets +
                    uuidField + doubleQuotes + mUuid.toString(QUuid::WithoutBraces) + doubleQuotes + comma +
                    typeField + doubleQuotes + mType + doubleQuotes +
                    closeBrackets +
                    CRLF;
    } else {
        serializedRequest =
                    openBrackets +
                    uuidField + doubleQuotes + mUuid.toString(QUuid::WithoutBraces) + doubleQuotes + comma +
                    typeField + doubleQuotes + mType + doubleQuotes + comma +
                    QString(mPayload.toByteArrayNoCRLF()) +
                    closeBrackets +
                    CRLF;
    }

    return serializedRequest.toUtf8();
}
