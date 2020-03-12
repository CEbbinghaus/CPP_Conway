#include "Game.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <glm/ext.hpp>
#include <cmath>
#include "libary/Array.h"
#include "libary/List.h"
#include "../dependencies/glfw/include/GLFW/glfw3.h"

Game::Game() {
	m_timer = 0.0f;
	cursor = nullptr;
	menu = nullptr;
	gameField = nullptr;
	fieldRenderer = nullptr;
	m_font = nullptr;
}

Game::~Game() {

}

bool Game::startup() {

	gameField = new Field(FieldWidth, FieldHeight);

	fieldRenderer = new render(gameField, getWindowPtr());

	cursor = new Pen(fieldRenderer);

	m_font = new aie::Font("C:/Users/s171715/Desktop/Projects/Semester Two/Game/bin/font/consolas.ttf", 32);

	m_timer = 0;

	menu = new FloatingMenu(fieldRenderer);

	//aie::Texture* test = new aie::Texture();

	menu->addButton(
		new Button("Eraser", {
			new aie::Texture("./bin/images/EraseUp.png"),
			new aie::Texture("./bin/images/EraseDown.png")
			}, [&](Button* b){
				for (int i = 0; i < 2; i++) {
					for (int x = 0; (unsigned)x < gameField->f_width; ++x) {
						memset(gameField->m_draw[x], 0, gameField->f_height);
					}
					gameField->swap();
				}
			},
			false
		)
	);
	menu->addButton(
		new Button("Shuffle", {
			new aie::Texture("./bin/images/ShuffleUp.png"),
			new aie::Texture("./bin/images/ShuffleDown.png")
		}, [&](Button* b) {
			generation = 0;
			for (int i = 0; i < 2; i++) {
				for (int x = 1; (unsigned)x < gameField->f_width - 2; ++x) {
					for (int y = 1; (unsigned)y < gameField->f_height - 2; ++y) {
						
						gameField->m_draw[x][y] = rand() & 1;
					}
				}
				gameField->swap();
			}
			//start();
		},false
		)
	);
	//menu->addButton(
	//	new Button("Draw", {
	//		new aie::Texture("./bin/images/PenUp.png"),
	//		new aie::Texture("./bin/images/PenDown.png"),
	//		new aie::Texture("./bin/images/BrushUp.png"),
	//		new aie::Texture("./bin/images/BrushDown.png")
	//		}, [&](Button* b){
	//			generation = 0;
	//		},
	//		false
	//	));
	menu->addButton(
		new Button("Play", {
			new aie::Texture("./bin/images/PauseUp.png"),
			new aie::Texture("./bin/images/PauseDown.png"),
			new aie::Texture("./bin/images/PlayUp.png"),
			new aie::Texture("./bin/images/PlayDown.png")
		}, [&](Button* b) {
			if (running)stop();
			else start();
			}
		));

	setVSync(false);

	auto mon = glfwGetWindowMonitor(getWindowPtr()) ? glfwGetWindowMonitor(getWindowPtr()) : glfwGetPrimaryMonitor();
	auto win = glfwGetVideoMode(mon);
	int x, y;
	glfwGetMonitorPos(mon, &x, &y);
	glfwSetWindowPos(getWindowPtr(), x, y);
	glfwSetWindowSize(getWindowPtr(), win->width, win->height);

	return true;
}

void Game::shutdown() {

	delete m_font;
	delete fieldRenderer;
}

void Game::start(){
	for (int i = 0; i < menu->buttons.length - 1; i++) {
		menu->buttons[i]->enabled = false;
	}
	menu->buttons[menu->buttons.length - 1]->index = 0;
	running = true;
}

void Game::stop(){
	for(int i = 0; i < menu->buttons.length - 1; i++){
		menu->buttons[i]->enabled = true;
	}
	menu->buttons[menu->buttons.length - 1]->index = 2;
	running = false;
}

void Game::update(float deltaTime) {
	float realDelta = (deltaTime * 60);
	aie::Input& input = *aie::Input::getInstance();

	if(running)m_timer += deltaTime;
	if (m_timer > tickTime) {
		++generation;
		gameField->Update();
		m_timer = fmod(m_timer, tickTime);
	}

	if (input.wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT)){
		menu->update(input.getMouseX(), input.getMouseY());
	}
	if (input.isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT)) {
		menu->hold(input.getMouseX(), input.getMouseY());
		cursor->draw(input.getMouseX(), input.getMouseY());
	}

	if (input.isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT)) {
		cursor->erase(input.getMouseX(), input.getMouseY());
	}

	if (input.isMouseButtonUp(aie::INPUT_MOUSE_BUTTON_LEFT)) {
		menu->hold(-10000, -100000);
	}

	if (input.wasKeyPressed(aie::INPUT_KEY_SPACE)) {
		if (running)stop();
		else start();
	}

	if (input.isKeyDown(aie::INPUT_KEY_EQUAL)) {
		tickTime += 0.001f * realDelta;
		tickTime = tickTime > 1 ? 1 : tickTime;
	}
	
	if (input.isKeyDown(aie::INPUT_KEY_MINUS)) {
		tickTime -= 0.001f * realDelta;
		tickTime = (float)(tickTime < 0.001 ? 0.001 : tickTime);
	}

	//if (input.isKeyDown(aie::INPUT_KEY_LEFT_CONTROL)) {
		fieldRenderer->scale = ((-input.getMouseScroll() + 100) / 100);
		fieldRenderer->scale = fieldRenderer->scale < 0.01 ? 0.01 : (fieldRenderer->scale > 1 ? 1 : fieldRenderer->scale);
		fieldRenderer->setCameraScale((float)fieldRenderer->scale);
	//}

	fieldRenderer->scale = fieldRenderer->scale < 0.01f ? 0.01f : (fieldRenderer->scale > 1.0f ? 1.0f : fieldRenderer->scale);
	if (input.isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_MIDDLE)) {
		int& x = (fieldRenderer->x);
		int& y = (fieldRenderer->y);

		x -= (int)(input.getMouseDeltaX() * 0.05);// *(1 - (fieldRenderer->scale * 0.5));
		y -= (int)(input.getMouseDeltaY() * 0.05);// *(1 - (fieldRenderer->scale * 0.5));

		//float l, b, r, t;
		//fieldRenderer->getCameraExtents(l, b, r, t);

		//int windowWidth = 0;
		//int windowHeight = 0;
		//glfwGetWindowSize(getWindowPtr(), &windowWidth, &windowHeight);

		//float xso = windowHeight / gameField->f_height;
		//float yso = windowWidth / gameField->f_width;

		//t *= yso;
		//b *= yso;
		//l *= xso;
		//r *= xso;

		//x = x < 0 ? 0 : ((x > l) ? l : x);
		//y = y < 0 ? 0 : ((y > b) ? b : y);

		/*unsigned int windowWidth = gameField->f_width;
		unsigned int windowHeight = gameField->f_height;

		int XScaleBuffer = windowWidth * ((1 - fieldRenderer->scale) * 0.5);
		int YScaleBuffer = windowHeight * ((1 - fieldRenderer->scale) * 0.5);

		x = x < 0 ? 0 : ((x > XScaleBuffer) ? XScaleBuffer : x);
		y = y < 0 ? 0 : ((y > YScaleBuffer) ? YScaleBuffer : y);*/

		fieldRenderer->setCameraPos((float)x, (float)y);
	}
	if (input.isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	
}

void Game::draw() {

	/*renderer->draw();*/
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	fieldRenderer->setCameraScale((float)fieldRenderer->scale);
	fieldRenderer->begin();

	fieldRenderer->draw();
	fieldRenderer->end();

	fieldRenderer->setCameraScale(1.0f);
	int x = (int)fieldRenderer->m_cameraX;
	int y = (int)fieldRenderer->m_cameraY;
	fieldRenderer->setCameraPos(0, 0);
	fieldRenderer->begin();


	menu->draw();

	fieldRenderer->setRenderColour(1, 1, 1);
	char fps[32];
	sprintf_s(fps, 32, "Generation: %i", generation);
	fieldRenderer->drawText(m_font, fps, 0.0f, (float)(getWindowHeight() - 32));

	//// Projection matricies
	////glm::mat4 ortho = glm::ortho();
	////glm::mat4 projection = glm::lookAt(from, to, World Up);

	////glm::mat4 pos = glm::mat4(1);
	////glm::mat4 view = glm::inverse(pos);

	////glm::vec3 finalPos = projec tion * view * model;

	fieldRenderer->end();
	fieldRenderer->setCameraPos((float)x, (float)y);
}