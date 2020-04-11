#ifndef NATIVESCREEN_H
#define NATIVESCREEN_H

#include <QQmlContext>

class NativeScreen
{
public:
    virtual ~NativeScreen() = 0;

    virtual void registerScreen(QQmlContext* ctxt) = 0;
};

#endif // NATIVESCREEN_H
