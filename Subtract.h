#include "ArithmeticOperation.h"

class Subtract : public ArithmeticOperation {
  public:
    Subtract(double, double);
    double execute();
};
