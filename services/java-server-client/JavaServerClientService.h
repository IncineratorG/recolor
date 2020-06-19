#ifndef JAVASERVERCLIENTSERVICE_H
#define JAVASERVERCLIENTSERVICE_H

#include "common/libs/service/Service.h"

#include <QObject>
#include <QTcpSocket>

class JavaServerClientService : public QObject, public Service
{
    Q_OBJECT

public:
    JavaServerClientService();

    void start();

private:
    QTcpSocket *socket;
};

#endif // JAVASERVERCLIENTSERVICE_H
