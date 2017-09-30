#pragma once
#include "stdafx.h"

class Game
{

public:
	//Add new vars here

private:
	//Add new vars here

//
//TEMPLATE STUFF BELOW
//

public:
	//Template variables
	Game();
	~Game();
	void run();
	static const int GAME_WIDTH = 1920;
	static const int GAME_HEIGHT = 1080;
	static const int CAMARA_WIDTH = 1920;
	static const int CAMERA_HEIGHT = 1080;
	static const int WINDOW_WIDTH = 1280;
	static const int WINDOW_HEIGHT = 720;

private:
	//Template variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	sf::View view;
	void init();
	void input();
	void update();
	void draw();
	void renderingThread(sf::RenderWindow* window);
	float frameTime = 0;
	int frameCounter = 0;
};
