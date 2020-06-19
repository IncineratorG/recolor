#ifndef JAVASERVER_H
#define JAVASERVER_H

#include "common/libs/native-screen/NativeScreen.h"

class JavaServer : public NativeScreen
{
public:
    JavaServer();

    void registerScreen(QQmlContext* ctxt);
};

#endif // JAVASERVER_H
