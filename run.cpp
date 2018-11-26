#include "ProgrammableCalculator.h"
// #include "CommandInterface.h"

void start();
void displayMessage();
void command_i(ProgrammableCalculator&, std::string);

int main() {
  start();
}

void start() {
  // Method to start the interactive terminal for application commands
  
  ProgrammableCalculator pCalc = ProgrammableCalculator(); //Instance of Programmable Calculator Created.

  std::cout << "Welcome to Programmable Calculator" << std::endl;
  
  int i = 1;

  std::string input;

  while(i == 1) {
    displayMessage();

    std::getline(std::cin, input);

    switch(input[0]) {
      case 'i' : {
          std::cout << "i pressed" << std::endl;
          command_i(pCalc, input);
        }
        break;
      case 'd' : std::cout << "d pressed" << std::endl;
        break;
      case 'r' : std::cout << "r pressed" << std::endl;
        break;
      case 'c' : std::cout << "c pressed" << std::endl; 
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

void displayMessage() {
  std::cout << "Enter 'i <filename>' to specify the input file with the instructions" << std::endl;
  std::cout << "Enter d to debug - Should have selected i and specified files earlier" << std::endl;
  std::cout << "Enter r to run the instructions" << std::endl;
  std::cout << "Enter c to run additional 100 instructions" << std::endl;
  std::cout << "Enter p print the values" << std::endl;
  std::cout << "Enter q to quit" << std::endl;
}

void command_i(ProgrammableCalculator& pcalc, std::string input) {
  char *filename = const_cast<char*> (input.substr(2).c_str());
  pcalc.readInstructionsFromFile(filename);
}
