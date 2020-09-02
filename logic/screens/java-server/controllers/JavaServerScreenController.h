#ifndef JAVASERVERSCREENCONTROLLER_H
#define JAVASERVERSCREENCONTROLLER_H

#include "stores/java-server-client/JSCStore.h"

#include <QObject>

class JavaServerScreenController : public QObject
{
    Q_OBJECT

public:
    JavaServerScreenController();

    Q_INVOKABLE void test();

    Q_INVOKABLE void startService();
    Q_INVOKABLE void stopService();
    Q_INVOKABLE void sendData();
    Q_INVOKABLE void runLongRunningServerTask();

private:
    std::shared_ptr<JSCStore> mJSCStore;
};

#endif // JAVASERVERSCREENCONTROLLER_H
