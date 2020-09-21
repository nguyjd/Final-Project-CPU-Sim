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
        for (int i = 0; i < 10; i++){
                std::cout << std::showpos << std::setw(5) << std::setfill('0') << std::internal  << memory[i] << " ";
        }
        
		std::cout << std::endl;
        
		for (int s = 10; s < 100; s = s + 10){
                std::cout << std::noshowpos << s << " ";
                for (int i = 0; i < 10; i++){
                        std::cout << std::showpos << std::setw(5) << std::setfill('0') << std::internal  << memory[s+i] << " ";
                }
                std::cout << std::endl;
        }
}



Simpletron::Simpletron() {

	accumulator = 0;
	instructionCounter = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;
	fatalState = false;
	validInput = true;
	userInput = 0;

	for (int i = 0; i < SIZE; i++) {

		memory[i] = 0;

	}

}

void Simpletron::enterSML() {

	int i = 0;

	std::cout << "*** Welcome to Simpletron! *** " << std::endl;
	std::cout << "*** Please enter your program one instruction *** " << std::endl;
	std::cout << "*** (or data word) at a time into the input *** " << std::endl;
	std::cout << "*** text field. I will display the location *** " << std::endl;
	std::cout << "*** number and a question mark (?). You then ***" << std::endl;
	std::cout << "*** type the word for that location ***" << std::endl;
	std::cout << std::endl;
	while (true) {

		validInput = true;

		std::cout << std::setw(2) << std::setfill('0') << std::internal << i << " ? ";
		std::cin >> userInput;

		if (userInput == -99999) {

			std::cout << "*** Program loading completed ***" << std::endl;
			std::cout << " *** Program execution begins ***" << std::endl;
			break;

		}
		else if (i == SIZE) {

			error("nomemory");
			break;

		}
		else if (userInput > 9999) {

			error("invaliduserinput");
			validInput = false;

		}
		else if (userInput < -9999) {

			error("invaliduserinput");
			validInput = false;

		}
		else if (std::cin.fail()) {

			error("invaliduserinput");
			validInput = false;

		}
		else {

			memory[i] = userInput;

		}

		if (validInput) {

			i++;

		}

	}

	if (!fatalState) {

		userInput = 0;
		SML();

	}
	

}

void Simpletron::SML() {

	while (operationCode != 43 && !fatalState) {

		if (instructionCounter >= 100) {

			error("nomemory");
			break;

		}

		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;


		switch (operationCode)
		{
		case READ:
			while (true) {

				std::cin >> userInput;

				validInput = true;
				if (userInput > 9999) {

					error("invaliduserinput");
					validInput = false;

				}
				else if (userInput < -9999) {

					error("invaliduserinput");
					validInput = false;

				}
				else if (std::cin.fail()) {

					error("invaliduserinput");
					validInput = false;

				}

				if (validInput) {

					memory[operand] = userInput;
					break;

				}
			}

			break;
		case WRITE:
			std::cout << memory[operand] << std::endl;
			break;
		case LOAD:
			accumulator = memory[operand];

			if (accumulator > 9999) {

				error("overflow");

			}

			if (accumulator < -9999) {

				error("underflow");

			}

			break;
		case STORE:
			memory[operand] = accumulator;
			break;
		case ADD:
			accumulator += memory[operand];

			if (accumulator > 9999) {

				error("overflow");

			}

			break;
		case SUBTRACT:
			accumulator -= memory[operand];

			if (accumulator < -9999) {

				error("underflow");

			}

			break;
		case DIVIDE:
			if (memory[operand] == 0) {

				error("divide0");

			}
			else {

				accumulator /= memory[operand];

			}
			break;
		case MULTIPLY:
			accumulator *= memory[operand];

			if (accumulator > 9999) {

				error("overflow");

			}

			if (accumulator < -9999) {

				error("underflow");

			}

			break;
		case BRANCH:
			instructionCounter = operand;
			break;
		case BRANCHNEG:
			if (accumulator < 0) {

				instructionCounter = operand;

			}
			break;
		case BRANCHZERO:
			if (accumulator == 0) {

				instructionCounter = operand;

			}
			break;
		case HALT:
			std::cout << "*** Simpletron execution terminated ***" << std::endl;
			break;
		default:
			error("invalidopcode");
			break;
		}

		instructionCounter++;

	}

}

// The error method. The type of error is passed into the error function as a string to
// identify what type of error has occured.
void Simpletron::error(std::string s){
        
		if (s.compare("invaliduserinput") == 0){
                std::cout << "An invalid user input has occured." << std::endl;
				std::cin.clear();
				std::cin.ignore(999999999999999, '\n');
        }
		
		if (s.compare("overflow") == 0){
                std::cout << "An fatal overflow error has occured. The program will now exit..." << std::endl;
				fatalState = true;
                printmem();
        }
        
		if (s.compare("divide0") == 0){
                std::cout << "A fatal divide by zero error has occured. The program will now exit..." << std::endl;
				fatalState = true;
                printmem();
        }
		
		if (s.compare("underflow") == 0){
                std::cout << "An fatal overflow error has occured. The program will now exit..." << std::endl;
				fatalState = true;
                printmem();
        }
		
		if (s.compare("invalidopcode") == 0){
                std::cout << "An fatal invalid operation has occured. The program will now exit..." << std::endl;
				fatalState = true;
                printmem();
        }
		
		if (s.compare("nomemory") == 0){
                std::cout << "A fatal error has occoured, system has run out of memory. The program will now exit..." << std::endl;
				fatalState = true;
                printmem();
        }
		
}