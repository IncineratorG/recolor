#include "Request.h"

Request::Request(const QString& type) {
    mUuid = QUuid::createUuid();
    mType = type;
}

Request::Request(const QString& type, const RequestPayload& payload) {
    mUuid = QUuid::createUuid();
    mType = type;

}

QString Request::getType() const {
    return mType;
}

QUuid Request::getUuid() const {
    return mUuid;
}

QByteArray Request::toByteArray() const {
    return "";
}
