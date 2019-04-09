// Simpletron's print memory function to print out everything in the registers and memory.
void Simpletron::printmem(){
        cout << "REGISTERS:" << endl;
        cout << "accumulator:             " << showpos << setw(5) << setfill('0') << internal << accumulator << endl;
        cout << "instructionCounter:        " << showpos << setw(2) << setfill('0') << internal << instructionCounter << endl;
        cout << "instructionRegister:     " << showpos << setw(5) << setfill('0') << internal << instructionRegister << endl;
        cout << "operationCode:             " << showpos << setw(2) << setfill('0') << internal << operationCode << endl;
        cout << "operand:                   " << showpos << setw(2) << setfill('0') << internal << operand << endl;
        cout << "" << endl;
        cout << "MEMORY:" << endl;
        cout << "   0     1     2     3     4     5     6     7     8     9" << endl;
        // Print out the memory block.
        cout << "00 ";
        for (int i=0; i<10 ; i++){
                cout << showpos << setw(5) << setfill('0') << internal  << memory[i] << " ";
        }
        cout << endl;
        for (int s=10; s<100; s=s+10){
                cout << noshowpos << s << " ";
                for (int i=0; i<10; i++){
                        cout << showpos << setw(5) << setfill('0') << internal  << memory[s+i] << " ";
                }
                cout << endl;
        }
}


// The error method. The type of error is passed into the error function as a string to
// identify what type of error has occured.
void Simpletron::error(string s){
        if (s.compare("overflow") == 0){
                cout << "An overflow error has occured. The program will now exit..." << endl;
                instructionCounter = 100;
                printmem();
        }
        if (s.compare("divide0") == 0){
                cout << "A divide by zero error has occured. The program will now exit..." << endl;
                instructionCounter = 100;
                printmem();
        }



}