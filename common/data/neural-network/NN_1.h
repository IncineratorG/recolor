#ifndef NN_1_H
#define NN_1_H

#include "common/data/simple-matrix/SimpleMatrix.h"
#include "common/data/neural-network/activation-functions/sigmoid/Sigmoid.h"

#include <memory>

class NN_1
{
public:
    NN_1(const unsigned long inputNodes,
         const unsigned long hiddenNodes,
         const unsigned long outputNodes,
         const double learningRate);

private:
    unsigned long mInputNodes;
    unsigned long mHiddenNodes;
    unsigned long mOutputNodes;
    double mLearningRate;
    SimpleMatrix mWih;
    SimpleMatrix mWho;
    SimpleMatrix mWhh;
    SimpleMatrix mInputsMat;
    std::shared_ptr<ActivationFunction> sigmoid;
};

#endif // NN_1_H
