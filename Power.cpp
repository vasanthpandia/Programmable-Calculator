#include "Power.h"

Power::Power(double x, double y) : ArithmeticOperation(x, y) {}

double Power::execute() {
  return pow(op1, op2);
}
