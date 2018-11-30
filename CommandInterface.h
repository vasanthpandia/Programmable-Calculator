#include "ProgrammableCalculator.h"

class CommandInterface {
  private:
    ProgrammableCalculator& pCalc;

  public:
    // CommandInterface (int &x) : t(x) {}
    CommandInterface(ProgrammableCalculator& pCalc) : pCalc(x) {};
    void run_commands();
};