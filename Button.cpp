#include "Button.h"

Button::Button(char* a_name, std::initializer_list<aie::Texture*> a_sprites, std::function<void(Button*)> function, bool a_enabled)
{
	x = 0;
	y = 0;
	enabled = a_enabled;
	name = a_name;
	state = ButtonState::up;
	index = 0;
	sprites = a_sprites;
	width = sprites[0]->getWidth();
	height = sprites[0]->getHeight();
	func = function;
}

Button::~Button()
{
	for (aie::Texture* tex : sprites) {
		delete tex;
	}
}

bool Button::click(int mx, int my) {
	bool me = isInRect(mx, my);
	if (me && func)
		func(this);
	return me;
}

bool Button::isInRect(int px, int py) {
	int mw = width / 2;
	int mh = height / 2;
	return (px > x - mw && px < x + mw && py > y - mh && py < y + mh);
}