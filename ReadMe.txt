This is the C++ implementation of Programmable Calculator that supports the following functionalities.
Supports normal arithmetic operations +, -, *, / and exponent(**).
Assignment done through = and ? works as conditional.
Run the application on Linux environment with g++, by using the following command.
'g++ run.cpp Instruction.cpp CalculatorInterface.cpp ProgrammableCalculator.cpp ArithmeticOperation.cpp Add.cpp Subtract.cpp Multiply.cpp Divide.cpp Power.cpp'
This starts the interactive terminal with instructions for each command.
Save the input instructions to be executed in a file with .inp format.
Each line is numbered to keep track of the index of the instructions.
The app has implemented ProgrammableCalculator as an abstract class and class Instruction derives from ProgrammableCalculator, implements virtual method execute_all().
Command Pattern:
  - Arithmetic Operations are implemented with Command Pattern.
  - Base Arithmetic class is abstract and has a pure virtual function execute that accepts 2 operands.
  - Classes Add, Subtract, Multiply, Divide and Power inherit from ArithmeticOperation and implement the execute() method.
  