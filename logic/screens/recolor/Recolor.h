#ifndef RECOLOR_H
#define RECOLOR_H

#include "common/libs/native-screen/NativeScreen.h"

class Recolor : public NativeScreen
{
public:
    Recolor();

    void registerScreen(QQmlContext* ctxt);
};

#endif // RECOLOR_H
