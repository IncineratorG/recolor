#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H

#include <QList>
#include <QVector>

class SimpleMatrix
{
public:
    SimpleMatrix();
    SimpleMatrix(const unsigned long rows, const unsigned long cols);

    void print() const;

    unsigned long numRows() const;
    unsigned long numCols() const;

    void set(const unsigned long row, const unsigned long col, const double val);
    double get(const unsigned long row, const unsigned long col) const;

    SimpleMatrix plus(const SimpleMatrix& other) const;
    SimpleMatrix minus(const SimpleMatrix& other) const;
    SimpleMatrix mul(const SimpleMatrix& other) const;

    SimpleMatrix transpose();

private:
    unsigned long mRows;
    unsigned long mCols;

    std::vector<std::vector<double>> mMat;
};

#endif // SIMPLEMATRIX_H
