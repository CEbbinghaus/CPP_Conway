#pragma once

#include "Renderer2D.h"
#include "Application.h"
#include "Field.h"
#include <glm/ext.hpp>
#include <iostream>

class Game;
class Pen;

class render :	public aie::Renderer2D
{
	friend Game;
	friend Pen;

	Field* drawField;

	uint screenWidth;
	uint screenHeight;

public:
	int x = 0;
	int y = 0;
	double scale = getCameraScale();
	float pixelScale = 1.0f;
	GLFWwindow* gameWindow;
	render(Field* a_field, GLFWwindow* window);

	
	unsigned int getXOffset();
	unsigned int getYOffset();
	float getPixelScale();
	~render();
	
	void draw();
};

