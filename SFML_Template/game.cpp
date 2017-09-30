#include "stdafx.h"
#include "game.h"

void Game::init()
{
	
}

void Game::input()
{
	while (window->pollEvent( event ))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				window->close();
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
		break;
	}
}

void Game::update()
{
	float timeElapsed = clock.restart().asSeconds();

	//Fps counter
	frameTime += timeElapsed;
	if (frameTime > 1)
	{
		std::cout << "FPS: " << frameCounter << "\n";
		frameTime = 0;
		frameCounter = 0;
	}
	frameCounter++;

	//Add new stuff below this
}


void Game::draw()
{
	window->clear();

	//Draw code

	window->display();
}

void Game::renderingThread( sf::RenderWindow* window )
{
	// the rendering loop
	while (window->isOpen())
	{
		window->clear();
		// draw...

		// end the current frame
		window->display();
	}
}


Game::Game()
{
	//Init window and view
	window = new sf::RenderWindow( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "SFML", sf::Style::Close );
	view.setSize( CAMARA_WIDTH, CAMERA_HEIGHT );
	view.setCenter( GAME_WIDTH * 0.5f, GAME_HEIGHT * 0.5f );
	window->setView( view );
	clock.restart();
	srand( time( nullptr ) );
	rand();
}

Game::~Game()
{
	delete window;
}

void Game::run()
{
	window->setActive( false );
	init();

	while (window->isOpen())
	{
		input();
		update();
		draw();
	}
}
