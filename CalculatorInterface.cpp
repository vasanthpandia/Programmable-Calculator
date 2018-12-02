#include "CalculatorInterface.h"

CalculatorInterface::CalculatorInterface() {
  instructions = Instruction();
}

void CalculatorInterface::start() {
  // Method to start the interactive terminal for application commands

  std::cout << "Welcome to Programmable Calculator" << std::endl;
  
  int i = 1;

  while(i == 1) {
    displayMessage();

    std::getline(std::cin, input);

    switch(input[0]) {
      case 'i' : {
          std::cout << "i pressed" << std::endl;
          command_i();
        }
        break;
      case 'd' : std::cout << "d pressed" << std::endl;
        break;
      case 'r' : {
          std::cout << "r pressed" << std::endl;
          command_r();
        }
        break;
      case 'c' : std::cout << "c pressed" << std::endl; 
        break;
      case 'p' : {
        std::cout << "p pressed" << std::endl;
        command_p();
      }
        break;
      case 'q' : {
        std::cout << "Thank you" << std::endl;
        std::cout << "Created by Vasanth Pandiarajan - UIN 672498535" << std::endl;
        i = 0;
      }
        break;
      default:
        std::cout << "Invalid Input" << std::endl;
    }
  }
}

void CalculatorInterface::displayMessage() {
  std::cout << "Enter 'i <filename>' to specify the input file with the instructions" << std::endl;
  std::cout << "Enter d to debug - Should have selected i and specified files earlier" << std::endl;
  std::cout << "Enter r to run the instructions" << std::endl;
  std::cout << "Enter c to run additional 100 instructions" << std::endl;
  std::cout << "Enter p print the values" << std::endl;
  std::cout << "Enter q to quit" << std::endl;
}

void CalculatorInterface::command_i() {
  std::string filename = input.substr(2);
  std::cout << "Filename is : " << filename << std::endl;
  instructions.readInstructionsFromFile(filename);
  std::vector<std::string> vector1 = instructions._instruction_set();
  for(int i = 0 ; i < vector1.size(); i++) {
    std::cout << vector1[i] << std::endl;
  }
}

void CalculatorInterface::command_r() {
  instructions.execute_all();
}

void CalculatorInterface::command_d() {
  instructions.debug();
}

void CalculatorInterface::command_p() {
  instructions.print_instructions();
  instructions.display_registers();
}
