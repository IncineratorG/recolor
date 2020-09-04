#ifndef SERVERMESSAGE_H
#define SERVERMESSAGE_H

#include <QString>

class ServerMessage
{
public:
    ServerMessage();
    ServerMessage(const QString& type, const QString& requestUuid);
    ServerMessage(const ServerMessage& other);

    bool isEmpty() const;

    QString getType() const;
    QString getRequestUuid() const;

private:
    QString mType;
    QString mRequestUuid;
};

#endif // SERVERMESSAGE_H
