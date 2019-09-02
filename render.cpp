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
	//for from (cameraX - width * scale * 0.5) to (cameraX + width * scale * 0.5)
	//float tmpScale = scale;
	//tmpScale = 1;


	//int xoB = (screenWidth * (1.0f - tmpScale) * 0.5);
	//int yoB = (screenHeight * (1.0f - tmpScale) * 0.5);


	//int xoE = screenWidth -  xoB;
	//int yoE = screenWidth - yoB;
	//for (int x = m_cameraX + xoB; x < m_cameraX + xoE; x++) {
	//	for (int y = m_cameraY + yoB; y < m_cameraY + yoE; y++) {
	//		if (x >= drawField->f_width || y >= drawField->f_height)
	//			continue;

	//		bool isActive = drawField->m_draw[y][x] & 1;
	//		if(isActive)
	//			drawBox(xScreenOffset + (x * xScreenScale), yScreenOffset + (y * yScreenScale), xScreenScale, yScreenScale);
	//	}
	//}
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