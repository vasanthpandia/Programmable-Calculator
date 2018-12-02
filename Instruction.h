#include "ProgrammableCalculator.h"

#include <sstream>
#include <string>
#include <math.h>
#include <iterator>

#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Power.h"

class Instruction : public ProgrammableCalculator {
  public:
    Instruction();
    void execute_all();
    void execute(std::string);
    void assign_to(char, std::string);
    void conditional(char, std::string);
    void debug();
    double get_register_value(char);
    double get_value(std::string);
    double evaluate_rhs(std::string);
    std::vector<std::string> split(std::string);
    void continue_execution();
};
