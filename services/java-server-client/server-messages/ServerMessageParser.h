#ifndef SERVERMESSAGEPARSER_H
#define SERVERMESSAGEPARSER_H

#include "ServerMessage.h"

#include <QString>

class ServerMessageParser
{
public:
    ServerMessageParser();

    ServerMessage parse(const QString& data);
};

#endif // SERVERMESSAGEPARSER_H
