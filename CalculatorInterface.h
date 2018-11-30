#include <iostream>

#include "Instruction.h"

class CalculatorInterface {
  public:
    CalculatorInterface();
    void start();

  private:
    std::string input;
    Instruction instructions;


    void displayMessage();
    void command_i();
};
