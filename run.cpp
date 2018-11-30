#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include "CalculatorInterface.h"

int main() {
  CalculatorInterface calc = CalculatorInterface();
  calc.start();
}

