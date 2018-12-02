#include "Subtract.h"

Subtract::Subtract(double x, double y) : ArithmeticOperation(x, y) {}

double Subtract::execute() {
  return (op1 - op2);
}
