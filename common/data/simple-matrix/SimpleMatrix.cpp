#include "SimpleMatrix.h"

#include <QDebug>

SimpleMatrix::SimpleMatrix()
    : mRows(0), mCols(0) {

}

SimpleMatrix::SimpleMatrix(const unsigned long rows, const unsigned long cols)
    : mRows(rows), mCols(cols) {
    std::vector<std::vector<double>> mat(mRows, std::vector<double>(mCols));
    mMat = mat;
}

void SimpleMatrix::print() const {
    for (unsigned long row = 0; row < mRows; ++row) {
        QString colStr;
        for (unsigned long col = 0; col < mCols; ++col) {
            colStr.append(QString::number(mMat[row][col], 'f', 3));
            colStr.append(" ");
        }

        qDebug() << colStr;
    }

    qDebug() << "";
}

unsigned long SimpleMatrix::numRows() const {
    return mRows;
}

unsigned long SimpleMatrix::numCols() const {
    return mCols;
}

void SimpleMatrix::set(const unsigned long row, const unsigned long col, const double val) {
    if (row >= mRows || col >= mCols) {
        return;
    }

    mMat[row][col] = val;
}

double SimpleMatrix::get(const unsigned long row, const unsigned long col) const {
    if (row >= mRows || col >= mCols) {
        return std::numeric_limits<double>::lowest();
    }

    return mMat[row][col];
}

SimpleMatrix SimpleMatrix::plus(const SimpleMatrix& other) const {
    return SimpleMatrix();
}

SimpleMatrix SimpleMatrix::minus(const SimpleMatrix& other) const {
    return SimpleMatrix();
}

SimpleMatrix SimpleMatrix::mul(const SimpleMatrix& other) const {
    if (mCols != other.mRows) {
        return SimpleMatrix();
    }

    SimpleMatrix otherTransposed(other.mCols, other.mRows);
    for (unsigned long i = 0; i < other.mCols; ++i) {
        for (unsigned long j = 0; j < other.mRows; ++j) {
            otherTransposed.mMat[i][j] = other.mMat[j][i];
        }
    }

    SimpleMatrix result(mRows, other.mCols);
    for (unsigned long i = 0; i < mRows; ++i) {
        for (unsigned long j = 0; j < other.mCols; ++j) {
            result.mMat[i][j] = std::inner_product(mMat[i].begin(),
                                                   mMat[i].end(),
                                                   otherTransposed.mMat[j].begin(),
                                                   0.0);
        }
    }

    return result;
}

SimpleMatrix SimpleMatrix::transpose() {
    return SimpleMatrix();
}

//QVector<double> SimpleMatrix::getColumnValues(const int col) const {
//    QVector<double> columnValues(mRows);

//    for (int row = 0; row < mRows; ++row) {
//        columnValues[row] = get(row, col);
//    }

//    return columnValues;
//}

//QVector<double> SimpleMatrix::getRowValues(const int row) const {
//    QVector<double> rowValues(mCols);

//    for (int col = 0; col < mCols; ++col) {
//        rowValues[col] = get(row, col);
//    }

//    return rowValues;
//}
