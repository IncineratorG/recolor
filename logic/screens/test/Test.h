#ifndef TEST_H
#define TEST_H

#include "common/libs/native-screen/NativeScreen.h"

class Test : public NativeScreen
{
public:
    Test();

    void registerScreen(QQmlContext* ctxt);
};

#endif // TEST_H
