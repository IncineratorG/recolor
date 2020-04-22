#include "MatrixScreenController.h"

#include <random>

#include <QDateTime>
#include <QDebug>

MatrixScreenController::MatrixScreenController() {

}

void MatrixScreenController::test() {
    qDebug() << __PRETTY_FUNCTION__;

//    const int rows1 = 500;
//    const int cols1 = 500;

//    SimpleMatrix mat1(rows1, cols1);
//    for (int row = 0; row < mat1.numRows(); ++row) {
//        for (int col = 0; col < mat1.numCols(); ++col) {
//            mat1.set(row, col, row * col * 0.123);
//        }
//    }
////    mat1.print();

//    const int rows2 = 500;
//    const int cols2 = 500;

//    SimpleMatrix mat2(rows2, cols2);
//    for (int row = 0; row < mat2.numRows(); ++row) {
//        for (int col = 0; col < mat2.numCols(); ++col) {
//            mat2.set(row, col, row * col * 0.123);
//        }
//    }
////    mat2.print();

//    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
//    SimpleMatrix mat3 = mat1.mul(mat2);
//    qint64 endTime = QDateTime::currentMSecsSinceEpoch();

//    qDebug() << "DONE: " << (endTime - startTime);

////    mat3.print();

    SimpleMatrix mat1(3, 2);
    mat1.set(0, 0, 0);
    mat1.set(0, 1, 1);
    mat1.set(1, 0, 2);
    mat1.set(1, 1, 3);
    mat1.set(2, 0, 4);
    mat1.set(2, 1, 5);

    SimpleMatrix mat2(3, 2);
    mat2.set(0, 0, 0);
    mat2.set(0, 1, 1);
    mat2.set(1, 0, 2);
    mat2.set(1, 1, 3);
    mat2.set(2, 0, 4);
    mat2.set(2, 1, 5);

    auto sum = mat1.plus(mat2);
    auto subtracted = mat1.minus(mat2);
    auto mult = mat1.elementMult(mat2);

//    sum.print();
//    subtracted.print();
//    mult.print();

    SimpleMatrix copy(mult);
//    copy.print();

    copy = sum;
//    copy.print();
}
