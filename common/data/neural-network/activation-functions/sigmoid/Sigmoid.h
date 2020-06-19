#ifndef SIGMOID_H
#define SIGMOID_H

#include "common/data/neural-network/activation-functions/abstract/ActivationFunction.h"

class Sigmoid : public ActivationFunction
{
public:
    Sigmoid();

    double exec(const double arg) const;
};

#endif // SIGMOID_H
