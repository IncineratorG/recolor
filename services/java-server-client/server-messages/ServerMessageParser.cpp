#include "ServerMessageParser.h"

#include <QMap>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

ServerMessageParser::ServerMessageParser()
    : TYPE_FIELD("type"),
      REQUEST_UUID_FIELD("requestUuid") {

}

ServerMessage ServerMessageParser::parse(const QString& data) {
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    if (doc.isNull()) {
        qDebug() << __PRETTY_FUNCTION__ << "->JSON_DOC_IS_NULL";
        return ServerMessage();
    }

    if (!doc.isObject()) {
        qDebug() << __PRETTY_FUNCTION__ << "->JSON_DOC_IS_NOT_OBJECT";
        return ServerMessage();
    }

    QJsonObject object = doc.object();

    QJsonValue typeField = object.value(TYPE_FIELD);
    QJsonValue requestUuidField = object.value(REQUEST_UUID_FIELD);

    QString typeValue = typeField.toString();
    QString requestUuidValue = requestUuidField.toString();

    ServerMessage serverMessage(typeValue, requestUuidValue);

    return serverMessage;
}
