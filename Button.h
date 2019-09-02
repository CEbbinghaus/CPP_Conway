#pragma once
#include <functional>
#include <initializer_list>
#include "Texture.h"
#include "libary/Array.h"

enum class ButtonState {
	up,
	down
};

class Button
{
public:
	bool enabled;
	char* name;
	int x;
	int y;
	int height;
	int width;
	unsigned char index;
	ButtonState state;

	std::function<void(Button*)> func;

	atyp::Array<aie::Texture*> sprites;

	Button(char*, std::initializer_list<aie::Texture*>, std::function<void(Button*)> = nullptr, bool = true);
	
	bool isInRect(int a_x, int a_y);
	bool click(int a_x, int a_y);

	~Button();
};

