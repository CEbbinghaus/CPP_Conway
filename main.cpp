#include "Game.h"
#include <iostream>


int main() {
	
	// allocation
	auto app = new Game();

	// initialise and loop
	app->run("Conways Game of Life", FieldWidth, FieldHeight, FullScreen);

	// deallocation
	delete app;

	return 0;
}