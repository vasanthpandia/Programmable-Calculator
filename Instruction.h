#include "ProgrammableCalculator.h"

#include <sstream>

class Instruction : public ProgrammableCalculator {
  public:
    Instruction();
    void execute_all();
    void execute(std::string);
    void assign_to(char, std::string);
    void conditional(char, std::string);
    double get_register_value(char);
    double get_value(std::string);
    double evaluate_rhs(std::string);
    std::vector<std::string> split(std::string);
    // void debug();
    // void execute_add();
    // void execute_subtract();
    // void execute_multiply();
    // void execute_divide();
    // void execute_modulo();
    // void execute_exponent();
    // void execute_questionmark();
  
  // private:
  //   void get_instruction_method();
  //   void get_operand(std::string);
  //   void get_lhs();
  //   void get_rhs();
};
