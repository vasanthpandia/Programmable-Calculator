#include "ArithmeticOperation.h"
#include <math.h>

class Power : public ArithmeticOperation {
  public:
    Power(double, double);
    double execute();
};
