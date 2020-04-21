#ifndef MATRIX_H
#define MATRIX_H

#include "common/libs/native-screen/NativeScreen.h"

class Matrix : public NativeScreen
{
public:
    Matrix();

    void registerScreen(QQmlContext* ctxt);
};

#endif // MATRIX_H
