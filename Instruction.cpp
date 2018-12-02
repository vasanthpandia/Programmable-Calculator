#include "Instruction.h"

Instruction::Instruction() {}

void Instruction::execute_all() {
  std::cout << "Inside execute all" << std::endl;
  while(_execution_count() < 100 && _current_instruction() < _instruction_set().size()) {
    execute(_instruction_set()[_current_instruction()]);
    _execution_count(_execution_count() + 1);
  }
}

void Instruction::execute(std::string cmd) {
  std::cout << "Inside execute" << std::endl;
  switch(cmd[2]) {
    case '=' : assign_to(cmd[0], cmd.substr(4));
      break;
    case '?' : conditional(cmd[0], cmd.substr(4));
      break;
    default: std::cout << "Invalid operation" << std::endl;
  }
  
  std::cout << "Next instruction evaluated" << std::endl;
}

void Instruction::debug() {
  if(_current_instruction() < 100) {
    std::cout << "Instruction to be executed : " << _instruction_set()[_current_instruction()] << std::endl;
    execute(_instruction_set()[_current_instruction()]);
  }
  display_registers();
  std::cout << "Current Instruction executed - index : " << _current_instruction() << std::endl;
}

void Instruction::assign_to(char reg, std::string rhs) {
  //to-do
  std::cout << "Assign" << std::endl;
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
  //to-do
  double result;
  std::vector<std::string> expression_tokens = split(rhs);

  std::cout << "Inside evaluate RHS" << std::endl;

  if(expression_tokens.size() == 1) {
    std::stringstream ss(expression_tokens[0]);
    ss >> result;
    std::cout << "Result is : " << result << std::endl;
  } else {
    double op1 = get_value(expression_tokens[0]);
    double op2 = get_value(expression_tokens[2]);
    std::string op = expression_tokens[1];
    if(op == "*") {
      std::cout << "* called" << std::endl;
      result = (op1 * op2);
      //to-do
    } else if(op == "**") {
      result = pow(op1, op2);
      std::cout << "** called" << std::endl;
      //to-do
    } else if(op == "+") {
      result = (op1 + op2);
      std::cout << "+ called" << std::endl;
      //to-do
    } else if(op == "-") {
      result = (op1 - op2);
      std::cout << "- called" << std::endl;
      //to-do
    } else if(op == "/") {
      result = (op1 / op2);
      std::cout << "/ called" << std::endl;
      //to-do
    } else {
      std::cout << "Hello" << std::endl;
      //to-do
    }
  }
  std::cout << "Conditional" << std::endl;
  return result;
}

void Instruction::conditional(char reg1, std::string rhs) {
  double registerval;
  int next_instruction;
    // std::string price = str.substr(2);
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
    
    for(int i = 0 ; i < result.size(); i++ ) {
      std::cout << "result - " << result[i] << std::endl;
    }

    return result;
}
