#include "ServerMessage.h"

ServerMessage::ServerMessage() {

}

ServerMessage::ServerMessage(const QString& type, const QString& requestUuid)
    : mType(type),
      mRequestUuid(requestUuid) {

}

ServerMessage::ServerMessage(const ServerMessage& other)
    : mType(other.mType),
      mRequestUuid(other.mRequestUuid) {

}

bool ServerMessage::isEmpty() const {
    return mType.isEmpty();
}

QString ServerMessage::getType() const {
    return mType;
}

QString ServerMessage::getRequestUuid() const {
    return mRequestUuid;
}
