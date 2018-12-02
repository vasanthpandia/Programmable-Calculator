#ifndef ARITHMETICOPERATION_H
#define ARITHMETICOPERATION_H

class ArithmeticOperation {
  protected:
    double op1, op2;
  public:
    ArithmeticOperation(double, double);
    virtual double execute() = 0; //Pure Virtual Function - Implemented by individual classes for each operation 
};

#endif