#include "FloatingMenu.h"



void FloatingMenu::draw(){
	renderer->setRenderColour(0.3f, 0.3f, 0.5f, 0.3f);
	int width = (int)(buttons.length * buttons[0]->width + buttons.length * 25.0f);
	int height = (int)(buttons[0]->height * 1.5);
	renderer->drawBox((float)(x + width / 2), (float)(y + height / 2), (float)width, (float)height);

	for (auto [button, index] : buttons) {
		renderer->setRenderColour((float)1, (float)1, (float)1, (float)(button->enabled ? 1 : 0.25));
		renderer->drawSprite(button->sprites[button->index + (char)button->state], (float)button->x, (float)button->y, (float)button->width, (float)button->height);
	}
}

void FloatingMenu::update(int mx, int my) {
	for (auto&[button, index] : buttons) {
		if(button->enabled)button->click(mx, my);
	}
}

void FloatingMenu::hold(int mx, int my) {
	for (auto&[button, index] : buttons) {
		if (button->enabled && button->isInRect(mx, my)){
			button->state = ButtonState::down;
		}else
			button->state = ButtonState::up;
	}
}

void FloatingMenu::addButton(Button* b)
{
	buttons.push(b);
	move();
}

void FloatingMenu::move(){
	for (auto&[button, index] : buttons) {
		button->x = x + (button->width / 2) + 12 + index * 25 + index * button->width;
		button->y = (int)(y + button->height * 0.75);
	}
}

FloatingMenu::FloatingMenu(render* r)
{
	renderer = r;
	x = y = 100;
	move();
}


FloatingMenu::~FloatingMenu(){
	for (Button* b : buttons) {
		delete b;
	}
}
