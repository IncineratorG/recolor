#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H


class ActivationFunction
{
public:
    virtual ~ActivationFunction() = 0;

    virtual double exec(const double arg) const = 0;
};

#endif // ACTIVATIONFUNCTION_H
