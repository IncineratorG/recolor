#ifndef MATRIXSCREENCONTROLLER_H
#define MATRIXSCREENCONTROLLER_H

#include "common/data/simple-matrix/SimpleMatrix.h"

#include <QObject>

class MatrixScreenController : public QObject
{
    Q_OBJECT

public:
    MatrixScreenController();

    Q_INVOKABLE void test();
};

#endif // MATRIXSCREENCONTROLLER_H
