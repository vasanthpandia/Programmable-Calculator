#include "Add.h"

Add::Add(double x, double y) : ArithmeticOperation(x, y) {}

double Add::execute() {
  return (op1 + op2);
}
