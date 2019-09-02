#include "Pen.h"
#include <math.h>


Pen::Pen(render* ptr) : camera(*ptr), display(*(ptr->drawField)) {
	mode = DrawMode::Pen;
	x = y = 0;
	r = 10;
}

void Pen::calculatePosition(unsigned int a_x, unsigned int a_y) {

	int camScale = (int)roundf((float)(1 - camera.scale));

	float nXPos = (float)(a_x - ((1 - camera.scale) * 10)) / (float)camera.screenWidth;
	float nYPos = (float)(a_y + ((1 - camera.scale) * 10)) / (float)camera.screenHeight;

	float tSX = (float)(camera.screenWidth * camera.scale);
	float tSY = (float)(camera.screenHeight * camera.scale);

	int xOffset = (int)((camera.screenWidth - tSX) * 0.5);
	int yOffset = (int)((camera.screenHeight - tSY) * 0.5);

	int actualX = (int)(xOffset + (tSX * nXPos));
	int actualY = (int)(yOffset + (tSY * nYPos));

	int absX = (int)(camera.x + actualX - camera.getXOffset() + (camera.pixelScale) / 2 + camScale);
	int absY = (int)(camera.y + actualY - camera.getYOffset() + (camera.pixelScale) / 2 + camScale);

	if (absX < 0 || absY < 0)return;
	int Xindex = (int)((float)absX / camera.pixelScale);
	int Yindex = (int)((float)absY / camera.pixelScale);
	if ((unsigned)Xindex >= display.f_width || (unsigned)Yindex >= display.f_height)return;

	x = Xindex;
	y = Yindex;
}

void Pen::draw(unsigned int a_x, unsigned int a_y) {
	calculatePosition(a_x, a_y);
	display.m_draw[x][y] = true;
}

void Pen::erase(unsigned int a_x, unsigned int a_y) {
	calculatePosition(a_x, a_y);
	display.m_draw[x][y] = false;
}

Pen::~Pen(){}
