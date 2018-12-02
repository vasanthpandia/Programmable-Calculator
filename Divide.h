#include "ArithmeticOperation.h"

class Divide : public ArithmeticOperation {
  public:
    Divide(double, double);
    double execute();
};
