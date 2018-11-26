#include <iostream>
#include <string>
#include <vector>

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
    int _execution_count();
    std::vector<std::string> _instruction_set();
    void readInstructionsFromFile(char* filename);

  private:
    std::vector<std::string> instruction_set;
    double w, x, y, z;
    int current_instruction, execution_count;
};
