#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H

#include <QList>
#include <QVector>

class SimpleMatrix
{
public:
    SimpleMatrix();
    SimpleMatrix(const unsigned long rows, const unsigned long cols, bool randInit = false);
    SimpleMatrix(const SimpleMatrix& other);

    bool valid() const;

    void print() const;

    unsigned long numRows() const;
    unsigned long numCols() const;

    void set(const unsigned long row, const unsigned long col, const double val);
    double get(const unsigned long row, const unsigned long col) const;

    SimpleMatrix plus(const SimpleMatrix& other) const;
    SimpleMatrix minus(const SimpleMatrix& other) const;
    SimpleMatrix mul(const SimpleMatrix& other) const;
    SimpleMatrix elementMult(const SimpleMatrix& other) const;

    SimpleMatrix transpose();

private:
    unsigned long mRows;
    unsigned long mCols;

    std::vector<std::vector<double>> mMat;
};

#endif // SIMPLEMATRIX_H
