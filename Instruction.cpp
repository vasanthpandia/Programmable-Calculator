#include "Instruction.h"

Instruction::Instruction() {}

void Instruction::execute_all() {
  while(_current_instruction() < 100) {
    execute(_instruction_set()[_current_instruction()]);
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
  _current_instruction(_current_instruction() + 1);
}

// void Instruction::debug()

void Instruction::assign_to(char reg, std::string rhs) {
  //to-do
  std::cout << "Assign" << std::endl;
  switch(reg) {
    case 'w' : _w(evaluate_rhs(rhs));
      break;
    case 'x' : _x(evaluate_rhs(rhs));
      break;
    case 'y' : _y(evaluate_rhs(rhs));
      break;
    case 'z' : _z(evaluate_rhs(rhs));
      break;
    default : std::cout << "Invalid operand" << std::endl;
  }
}

double Instruction::evaluate_rhs(std::string rhs) {
  //to-do
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
      std::cout << "* called" << std::endl;
      //to-do
    } else if(op == "**") {
      std::cout << "** called" << std::endl;
      //to-do
    } else if(op == "+") {
      std::cout << "+ called" << std::endl;
      //to-do
    } else if(op == "-") {
      std::cout << "- called" << std::endl;
      //to-do
    } else if(op == "/") {
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
    _current_instruction(next_instruction);
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
    std::string st;

    for(int i = 0; i < rhs.length(); ++i) {
      if(rhs[i] != ' ')
        {
            st += std::string(1, rhs[i]);
        }
        else if(rhs[i] == ' ')
        {
            result.push_back(st);
            st.clear();
        }
    }

    return result;
}
