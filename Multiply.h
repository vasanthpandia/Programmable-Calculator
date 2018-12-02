#include "ArithmeticOperation.h"

class Multiply : public ArithmeticOperation {
  public:
    Multiply(double, double);
    double execute();
};
