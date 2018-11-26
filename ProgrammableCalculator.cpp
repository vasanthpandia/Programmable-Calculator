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

int ProgrammableCalculator::_execution_count() {
  return execution_count;
}

std::vector<std::string> ProgrammableCalculator::_instruction_set() {
  return instruction_set;
}

void ProgrammableCalculator::readInstructionsFromFile(char* filename) {
  std::cout << "Inside file read - " << filename << std::endl;
}