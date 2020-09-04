#ifndef SERVERMESSAGEPARSER_H
#define SERVERMESSAGEPARSER_H

#include "ServerMessage.h"

#include <QString>

class ServerMessageParser
{
public:
    ServerMessageParser();

    ServerMessage parse(const QString& data);

private:
    QString TYPE_FIELD;
    QString REQUEST_UUID_FIELD;
};

#endif // SERVERMESSAGEPARSER_H
