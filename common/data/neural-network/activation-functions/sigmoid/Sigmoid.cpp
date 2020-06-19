#include "Sigmoid.h"

#include <math.h>

Sigmoid::Sigmoid() {

}

double Sigmoid::exec(const double arg) const {
//    return 1 / (1 + pow(M_E, (-1 * arg)));
     return 1 / (1 + abs(arg));
}
