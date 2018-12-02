#include "Instruction.h"

Instruction::Instruction() {}

void Instruction::execute_all() {
  if(_instruction_set().size() == 0 ) {
    std::cout << "No instructions read - Use option i with file name" << std::endl;
    return;
  }
  if(_current_instruction() >= _instruction_set().size()) {
    std::cout << "All executions complete - Add new instructions with option i" << std::endl; 
  }
  while(_execution_count() < 100 && _current_instruction() < _instruction_set().size()) {
    execute(_instruction_set()[_current_instruction()]);
    _execution_count(_execution_count() + 1);
  }
}

void Instruction::execute(std::string cmd) {
  switch(cmd[2]) {
    case '=' : assign_to(cmd[0], cmd.substr(4));
      break;
    case '?' : conditional(cmd[0], cmd.substr(4));
      break;
    default: std::cout << "Invalid operation" << std::endl;
  }  
}

void Instruction::debug() {
  if(_execution_count() < 100 && _current_instruction() < _instruction_set().size()) {
    std::cout << "Instruction to be executed : " << _instruction_set()[_current_instruction()] << std::endl;
    execute(_instruction_set()[_current_instruction()]);
  }
  display_registers();
  std::cout << "Current Instruction executed - index : " << _current_instruction() << std::endl;
}

void Instruction::continue_execution() {
  if(_execution_count() == 100) {
    _execution_count(0);
  } else {
    std::cout << "Execution limit not reached" << std::endl;
  }
}

void Instruction::assign_to(char reg, std::string rhs) {
  switch(reg) {
    case 'w' : 
      _w(evaluate_rhs(rhs));
      std::cout << "W : " << _w() << std::endl;
      break;
    case 'x' : 
      _x(evaluate_rhs(rhs));
      std::cout << "X : " << _x() << std::endl;
      break;
    case 'y' : 
      std::cout << "Y : " << _y() << std::endl;
      _y(evaluate_rhs(rhs));
      break;
    case 'z' : 
      std::cout << "Z : " << _z()  << std::endl;
      _z(evaluate_rhs(rhs));
      break;
    default : std::cout << "Invalid operand" << std::endl;
  }
  int next_instruction_index = _current_instruction() + 1;
  _current_instruction(next_instruction_index);
}

double Instruction::evaluate_rhs(std::string rhs) {
  double result;
  std::vector<std::string> expression_tokens = split(rhs);

  if(expression_tokens.size() == 1) {
    std::stringstream ss(expression_tokens[0]);
    ss >> result;
  } else {
    double op1 = get_value(expression_tokens[0]);
    double op2 = get_value(expression_tokens[2]);
    std::string op = expression_tokens[1];
    if(op == "*") {
      Multiply m = Multiply(op1, op2);
      result = m.execute();
    } else if(op == "**") {
      Power p = Power(op1, op2);
      result = p.execute();
    } else if(op == "+") {
      Add a = Add(op1, op2);
      result = a.execute();
    } else if(op == "-") {
      Subtract s = Subtract(op1, op2);
      result = s.execute();
    } else if(op == "/") {
      Divide d = Divide(op1, op2);
      result = d.execute();
    } else {
      std::cout << "Invalid instruction" << std::endl;
    }
  }
  return result;
}

void Instruction::conditional(char reg1, std::string rhs) {
  double registerval;
  int next_instruction;
  std::stringstream ss(rhs);
  ss >> next_instruction;
  registerval = get_register_value(reg1);
  if(registerval != 0) {
    _current_instruction(next_instruction - 1);
  } else {
    int next_instruction_index = _current_instruction() + 1;
    _current_instruction(next_instruction_index);
  }
}

double Instruction::get_value(std::string str) {
  double result;
  if(str.length() == 1) {
    switch(str[0]) {
      case 'w' : result = _w();
        break;
      case 'x' : result = _x();
        break;
      case 'y' : result = _y();
        break;
      case 'z' : result = _z();
        break;
      default: {
        std::stringstream ss(str);
        ss >> result;
      }
    }

  }
  return result;
}

double Instruction::get_register_value(char reg) {
  double registerval;
  switch(reg) {
    case 'w' : registerval = _w();
      break;
    case 'x' : registerval = _x();
      break;
    case 'y' : registerval = _y();
      break;
    case 'z' : registerval = _z();
      break;
    default: std::cout << "Register not found" << std::endl;
  }
}

std::vector<std::string> Instruction::split(std::string rhs)
{
    std::vector<std::string> result;

    std::istringstream iss(rhs);
    std::copy(std::istream_iterator<std::string>(iss),
      std::istream_iterator<std::string>(),
        std::back_inserter(result));

    return result;
}
