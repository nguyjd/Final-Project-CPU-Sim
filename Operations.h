#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include <iostream>


class Operations{
	
public:
		void Read(const int address, int* arr);
		void Write(const int address, int* arr);
		
		void Load(const int address, int* arr, int &accumulator);
		void Store(const int address, int* arr, int &accumulator);
		
		void Add(const int address, int* arr, int &accumulator);
		void Subtract(const int address, int* arr, int &accumulator);
		void Divide(const int address, int* arr, int &accumulator);
		void Multiply(const int address, int* arr, int &accumulator);

		void Branch();
		void Branchneg(const int address, int &accumulator, int &instructionCounter);
		void Branchzero(const int address, int &accumulator, int &instructionCounter);
	
	
};

#endif