#ifndef SERVERACTIONS_H
#define SERVERACTIONS_H

#include <QByteArray>

class ServerActions
{
public:
    ServerActions();

    QByteArray getDataAction();
    QByteArray getOffAction();
    QByteArray runLongRunningTaskAction();
};

#endif // SERVERACTIONS_H
