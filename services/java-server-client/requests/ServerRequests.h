#ifndef SERVERREQUESTS_H
#define SERVERREQUESTS_H

#include "Request.h"

#include <QList>
#include <QString>

class ServerRequests
{
public:
    ServerRequests();

    Request runLongRunningTaskRequest(int a, int b, const QList<QString> list);
};

#endif // SERVERREQUESTS_H
