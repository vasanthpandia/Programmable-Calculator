#include "Multiply.h"

Multiply::Multiply(double x, double y) : ArithmeticOperation(x, y) {}

double Multiply::execute() {
  return (op1 * op2);
}
