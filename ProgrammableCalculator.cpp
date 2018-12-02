#include "ProgrammableCalculator.h"

ProgrammableCalculator::ProgrammableCalculator() {
  w = 0;
  x = 0;
  y = 0;
  z = 0;
  execution_count = 0;
  current_instruction = 0;
}

void ProgrammableCalculator::_x(double num) {
  x = num;
}

double ProgrammableCalculator::_x() {
  return x;
}

void ProgrammableCalculator::_y(double num) {
  y = num;
}

double ProgrammableCalculator::_y() {
  return y;
}

void ProgrammableCalculator::_z(double num) {
  z = num;
}

double ProgrammableCalculator::_z() {
  return z;
}

void ProgrammableCalculator::_w(double num) {
  w = num;
}

double ProgrammableCalculator::_w() {
  return w;
}

int ProgrammableCalculator::_current_instruction() {
  return current_instruction;
}

void ProgrammableCalculator::_current_instruction(int x) {
  current_instruction = x;
}

int ProgrammableCalculator::_execution_count() {
  return execution_count;
}

void ProgrammableCalculator::_execution_count(int x) {
  execution_count = x;
}

std::vector<std::string> ProgrammableCalculator::_instruction_set() {
  return instruction_set;
}

void ProgrammableCalculator::readInstructionsFromFile(std::string filename) {
  char* file = const_cast<char*> (filename.c_str());

  std::ifstream clipfile(file);
  std::cout << "File name is : " << filename << std::endl;
  std::string line;

  if (clipfile.is_open())
  {
    while ( getline (clipfile,line) )
    {
      std::cout << line;
      line.erase(line.size() - 2);
      instruction_set.push_back(line.substr(3));
      line.clear();
    }
    clipfile.close();
    std::cout << "Instructions read from file : " << filename << std::endl;
  } else {
    std::cout <<"File not opened" << std::endl;
  }
}

void ProgrammableCalculator::print_instructions() {
  for(int i = 0; i < instruction_set.size(); i++) {
    std::cout << i+1 << ": " << instruction_set[i] << std::endl;
  }
}

void ProgrammableCalculator::display_registers() {
  std::cout << "W : " << w << std::endl;
  std::cout << "X : " << x << std::endl;
  std::cout << "Y : " << y << std::endl;
  std::cout << "Z : " << z << std::endl;
}
