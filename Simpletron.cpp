#include "Simpletron.h"

// Simpletron's print memory function to print out everything in the registers and memory.
void Simpletron::printmem(){
        
		std::cout << "REGISTERS:" << std::endl;
        std::cout << "accumulator:             " << std::showpos << std::setw(5) << std::setfill('0') << std::internal << accumulator << std::endl;
        std::cout << "instructionCounter:        " << std::showpos << std::setw(2) << std::setfill('0') << std::internal << instructionCounter << std::endl;
        std::cout << "instructionRegister:     " << std::showpos << std::setw(5) << std::setfill('0') << std::internal << instructionRegister << std::endl;
        std::cout << "operationCode:             " << std::showpos << std::setw(2) << std::setfill('0') << std::internal << operationCode << std::endl;
        std::cout << "operand:                   " << std::showpos << std::setw(2) << std::setfill('0') << std::internal << operand << std::endl;
        std::cout << "" << std::endl;
        std::cout << "MEMORY:" << std::endl;
        std::cout << "   0     1     2     3     4     5     6     7     8     9" << std::endl;
        
		// Print out the memory block.
        std::cout << "00 ";
        for (int i=0; i<10 ; i++){
                std::cout << std::showpos << std::setw(5) << std::setfill('0') << std::internal  << memory[i] << " ";
        }
        
		std::cout << std::endl;
        
		for (int s=10; s<100; s=s+10){
                std::cout << std::noshowpos << s << " ";
                for (int i=0; i<10; i++){
                        std::cout << std::showpos << std::setw(5) << std::setfill('0') << std::internal  << memory[s+i] << " ";
                }
                std::cout << std::endl;
        }
}


// The error method. The type of error is passed into the error function as a string to
// identify what type of error has occured.
void Simpletron::error(std::string s){
        
		if (s.compare("overflow") == 0){
                std::cout << "An overflow error has occured. The program will now exit..." << std::endl;
                instructionCounter = 100;
                printmem();
        }
        
		if (s.compare("divide0") == 0){
                std::cout << "A divide by zero error has occured. The program will now exit..." << std::endl;
                instructionCounter = 100;
                printmem();
        }
}