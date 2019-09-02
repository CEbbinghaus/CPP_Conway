#pragma once
#include "Button.h"
#include "Texture.h"
#include "libary/Array.h"
#include "render.h"


class FloatingMenu
{
	int x;
	int y;
	render* renderer;

public:
	atyp::Array<Button*> buttons;
	void draw();
	void update(int mx, int my);
	void addButton(Button*);
	void hold(int mx, int my);
	void move();
	FloatingMenu(render*);
	~FloatingMenu();
};

