#include "Game.h"
#include <iostream>

// Could be improved without case statement - replace with meta templates that detect size.
//template <typename T>
//void print_binary(T& value)
//{
//	size_t size = sizeof(T) * 8; // bytes to bits
//	
//	char* mem = (char*)malloc(size);
//
//	for (int i = size; i >= 0; i--)
//	{
//		std::cout << (bool(*data & (1 << i)));
//	}
//	std::cout << std::endl;
//}

int main() {
	
	// allocation
	auto app = new Game();

	// initialise and loop
	app->run("Conways Game of Life", FieldWidth, FieldHeight, FullScreen);

	// deallocation
	delete app;


	//unsigned int x = 4294967295;
	//std::cout << x << std::endl;
	//int b = 0;
	//b = x ^ 0x80000000;
	//b--;
	//std::cout << b;
	//system("pause");
	return 0;
}