#pragma once

#include "../dependencies/glfw/include/GLFW/glfw3.h"
#include "./dependencies/mlk/mlkrng.h"


typedef unsigned int uint;
typedef char cell;


class Field
{
	cell** m_buf1;
	cell** m_buf2;
	cell** m_cur;
public:
	uint f_width;
	uint f_height;
	cell** m_draw;

	void Update();
	cell CalculateKernel(uint x, uint y);
	void swap();
	Field(unsigned int width, unsigned int height);
	~Field();
};

