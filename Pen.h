#pragma once
#include "render.h"
#include "Field.h"
#include "./dependencies/mlk/mlkrng.h"

enum class DrawMode {
	Pen,
	Brush
};

class Pen
{
	unsigned int x;
	unsigned int y;
	unsigned int r;
	render& camera;
	Field& display;
	DrawMode mode;
public:
	Pen(render*);
	void calculatePosition(unsigned int, unsigned int);
	void draw(unsigned int, unsigned int);
	void erase(unsigned int, unsigned int);
	~Pen();
};

