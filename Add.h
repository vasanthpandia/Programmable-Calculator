#include "ArithmeticOperation.h"

class Add : public ArithmeticOperation {
  public:
    Add(double, double);
    double execute();
};
