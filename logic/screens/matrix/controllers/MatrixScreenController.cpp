#include "MatrixScreenController.h"

#include <QDateTime>
#include <QDebug>

MatrixScreenController::MatrixScreenController() {

}

void MatrixScreenController::test() {
    qDebug() << __PRETTY_FUNCTION__;

    std::vector<double> v;
    std::vector<std::vector<double>> vec;

//    QVector<double> v;
//    v.append(1.0);
//    v.append(2.0);

//    QVector<QVector<double>> vv;
//    vv.append(v);

//    const QVector<double>* vvData = vv.constData();
//    const double* vData = vvData->constData();

//    qDebug() << vData[0];

//    QVector<double> v;
//    v.append(1.0);
//    v.append(2.0);

//    const double* data = v.constData();
//    qDebug() << data[2];

    const int rows1 = 1000;
    const int cols1 = 1000;

    SimpleMatrix mat1(rows1, cols1);
    for (int row = 0; row < mat1.numRows(); ++row) {
        for (int col = 0; col < mat1.numCols(); ++col) {
            mat1.set(row, col, row * col * 0.123);
        }
    }
//    mat1.print();

    const int rows2 = 1000;
    const int cols2 = 1000;

    SimpleMatrix mat2(rows2, cols2);
    for (int row = 0; row < mat2.numRows(); ++row) {
        for (int col = 0; col < mat2.numCols(); ++col) {
            mat2.set(row, col, row * col * 0.123);
        }
    }
//    mat2.print();

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    SimpleMatrix mat3 = mat1.mul(mat2);
    qint64 endTime = QDateTime::currentMSecsSinceEpoch();

    qDebug() << "DONE: " << (endTime - startTime);

//    mat3.print();
}
