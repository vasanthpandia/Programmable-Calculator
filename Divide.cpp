#include "Divide.h"

Divide::Divide(double x, double y) : ArithmeticOperation(x, y) {}

double Divide::execute() {
  return (op1 / op2);
}
