#pragma once

#include "Application.h"
#include "render.h"
#include "Field.h"
#include "FloatingMenu.h"
#include "Pen.h"

#define FieldWidth 1920
#define FieldHeight 1080
#define FullScreen true

class Game : public aie::Application {
public:
	Game();
	virtual ~Game();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void start();
	void stop();

	float updateTime = 1.0f;
	float tickTime = 0.1f;
	unsigned int generation = 0;

	bool running = true; 
protected:
	double x = 0.0f;
	double y = 0.0f;

	Pen*				cursor;
	FloatingMenu*		menu;
	Field*				gameField;
	render*				fieldRenderer;
	aie::Font*			m_font;

	float m_timer;
};