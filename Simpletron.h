#include <iostream>
//#include <Bridges.h>
//#include <SymbolCollection.h>

using namespace std;

const int READ = 10;
const int WRITE = 11;
const int LOAD = 20;
const int STORE = 21;
const int ADD = 30;
const int SUBTRACT = 31;
const int DIVIDE = 32;
const int MULTIPLY = 33;
const int BRANCH = 40;
const int BRANCHNEG = 41;
const int BRANCHZERO = 42;
const int HALT = 43;

const int SIZE = 16;

// The main class header for the Simpletron class.
class Simpletron
{
public:
        // declares the public functions
        Simpletron(); 
        void enterSML(); //User input of program
      //  void execute(bridges::Bridges* br);
        void SML(); // Part 2
       // bridges::SymbolCollection* getState(int pos);


private:
        // declares the member variables
        void error(string); // Implementation given below
        void printmem(); // Implementation given below
        int accumulator;
        int instructionCounter;
        int operationCode;
        int operand;
        int instructionRegister;
        int memory[SIZE];
};