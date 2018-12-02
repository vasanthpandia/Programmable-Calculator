#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class ProgrammableCalculator {
  public:
    ProgrammableCalculator(); 
    double _w();
    void _w(double);
    double _x();
    void _x(double);
    double _y();
    void _y(double);
    double _z();
    void _z(double);
    int _current_instruction();
    void _current_instruction(int x);
    int _execution_count();
    void _execution_count(int x);
    std::vector<std::string> _instruction_set();
    void readInstructionsFromFile(std::string filename);
    void display_registers();
    void print_instructions();
    virtual void execute_all() = 0; // Pure virtual function, makes ProgrammableCalculator abstract. Implementation done in class Instruction.

  private:
    std::vector<std::string> instruction_set;
    double w, x, y, z;
    int current_instruction, execution_count;
};
