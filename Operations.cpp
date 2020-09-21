#include "Operations.h"

void Operations::Read(const int address, int* arr){
	
	std::cin >> arr[address];

}

void Operations::Write(const int address, int* arr){
	
	std::cout << arr[address];
	
}

void Operations::Load(const int address, int* arr, int &accumulator){
	
	accumulator = arr[address];
	
}


void Operations::Store(const int address, int* arr, int &accumulator){
	
	arr[address] = accumulator;

}

void Operations::Add(const int address, int* arr, int &accumulator){
	
	accumulator += arr[address];
	
}

void Operations::Subtract(const int address, int* arr, int &accumulator){
	
	accumulator -= arr[address];

}

void Operations::Divide(const int address, int* arr, int &accumulator){
	
	accumulator /= arr[address];
	
}

void Operations::Multiply(const int address, int* arr, int &accumulator){
	
	accumulator *= arr[address];
	
}