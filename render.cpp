#include "render.h"


render::render(Field* a_field, GLFWwindow* window)
{
	gameWindow = window;
	drawField = a_field;
	screenWidth = aie::Application::instance->getWindowWidth();
	screenHeight = aie::Application::instance->getWindowHeight();
}


render::~render(){}

unsigned int render::getXOffset(){
	screenWidth = aie::Application::instance->getWindowWidth();
	return (unsigned int)((screenWidth - (drawField->f_width * pixelScale)) * 0.5);
}

unsigned int render::getYOffset(){
	screenHeight = aie::Application::instance->getWindowHeight();
	return (unsigned int)((screenHeight - (drawField->f_height * pixelScale)) * 0.5);
}

float render::getPixelScale(){
	float xPixelScale = (float)((float)screenWidth / (float)drawField->f_width);
	float yPixelScale = (float)((float)screenHeight / (float)drawField->f_height);
	pixelScale = xPixelScale < yPixelScale ? xPixelScale : yPixelScale;
	pixelScale = pixelScale < 1 ? 1.0f : pixelScale;
	return pixelScale;
}

void render::draw(){
	getPixelScale();
	int xoffset = getXOffset();
	int yoffset = getYOffset();

	for (int x = 0; x < (signed)drawField->f_width; x++) {
		for (int y = 0; y < (signed)drawField->f_height; y++) {
			bool isActive = drawField->m_draw[x][y] & 1;
			if (isActive)
				drawBox(xoffset + (x * pixelScale), yoffset + (y * pixelScale), pixelScale, pixelScale);
		}
	}
}