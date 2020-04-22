#include "SimpleMatrix.h"

#include <random>

#include <QDebug>

SimpleMatrix::SimpleMatrix()
    : mRows(0), mCols(0) {

}

SimpleMatrix::SimpleMatrix(const unsigned long rows, const unsigned long cols, bool randInit)
    : mRows(rows), mCols(cols) {
    std::vector<std::vector<double>> mat(mRows, std::vector<double>(mCols));
    mMat = mat;

    if (randInit) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (unsigned long i = 0; i < mRows; ++i) {
            for (unsigned long j = 0; j < mCols; ++j) {
                mMat[i][j] = dis(gen);
            }
        }
    }
}

SimpleMatrix::SimpleMatrix(const SimpleMatrix& other)
    : mRows(other.mRows), mCols(other.mCols), mMat(other.mMat) {

}

bool SimpleMatrix::valid() const {
    return mRows != 0 || mCols != 0;
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
    if (mRows != other.mRows || mCols != other.mCols) {
        return SimpleMatrix();
    }

    SimpleMatrix sum(mRows, mCols);
    for (unsigned long i = 0; i < mRows; ++i) {
        for (unsigned long j = 0; j < mCols; ++j) {
            sum.set(i, j, mMat[i][j] + other.mMat[i][j]);
        }
    }

    return sum;
}

SimpleMatrix SimpleMatrix::minus(const SimpleMatrix& other) const {
    if (mRows != other.mRows || mCols != other.mCols) {
        return SimpleMatrix();
    }

    SimpleMatrix subtracted(mRows, mCols);
    for (unsigned long i = 0; i < mRows; ++i) {
        for (unsigned long j = 0; j < mCols; ++j) {
            subtracted.set(i, j, mMat[i][j] - other.mMat[i][j]);
        }
    }

    return subtracted;
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

SimpleMatrix SimpleMatrix::elementMult(const SimpleMatrix& other) const {
    if (mRows != other.mRows || mCols != other.mCols) {
        return SimpleMatrix();
    }

    SimpleMatrix multiplied(mRows, mCols);
    for (unsigned long i = 0; i < mRows; ++i) {
        for (unsigned long j = 0; j < mCols; ++j) {
            multiplied.set(i, j, mMat[i][j] * other.mMat[i][j]);
        }
    }

    return multiplied;
}

SimpleMatrix SimpleMatrix::transpose() {
    SimpleMatrix transposed(mCols, mRows);
    for (unsigned long i = 0; i < mCols; ++i) {
        for (unsigned long j = 0; j < mRows; ++j) {
            transposed.mMat[i][j] = mMat[j][i];
        }
    }

    return transposed;
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
