#include "NN_1.h"

NN_1::NN_1(const unsigned long inputNodes,
           const unsigned long hiddenNodes,
           const unsigned long outputNodes,
           const double learningRate)
 : mInputNodes(inputNodes),
   mHiddenNodes(hiddenNodes),
   mOutputNodes(outputNodes),
   mLearningRate(learningRate) {
    SimpleMatrix wihProto(mHiddenNodes, mInputNodes, true);
    mWih = wihProto;

    SimpleMatrix whoProto(mOutputNodes, mHiddenNodes);
    mWho = whoProto;

    SimpleMatrix whhProto(mHiddenNodes, mHiddenNodes);
    mWhh = whhProto;

    SimpleMatrix inputsMatProto(mInputNodes, 1);
    mInputsMat = inputsMatProto;

    sigmoid = std::make_shared<Sigmoid>();
}

