#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	//circle 1
	circle.setRadius(25);
	circle.setPosition(100, 100);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Green);
	circle.setOutlineThickness(2.f);
	//speed
	speed = 300.f;

	//circle 2
	circle2.setRadius(25);
	circle2.setPosition(100, 100);
	circle2.setFillColor(sf::Color::Green);
	circle2.setOutlineColor(sf::Color::Blue);
	circle2.setOutlineThickness(2.f);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//Up
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		input->setKeyUp(sf::Keyboard::Up);
		speedY = 300.f;

	}
	//Left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		input->setKeyUp(sf::Keyboard::Left);
		speedX = -300.f;

	}
	//Down
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		input->setKeyUp(sf::Keyboard::Down);
		speedY = -300.f;

	}
	//Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		input->setKeyUp(sf::Keyboard::Right);
		speedX = 300.f;

	}
	
}

// Update game objects
void Level::update(float dt)
{
	//Move Circle
	circle.move(speed * dt, 0);

	sf::Vector2u pos = window->getSize();

	float windX, circX, circX2;

	windX = window->getSize().x;
	circX = circle.getPosition().x;
	circX = circX + 50;
	circX2 = circX - 50;

	if (circX >= windX)
	{
		speed = -300.f;

	}
	if (circX2 <= 0)
	{
		speed = 300.f;
	}

	circle2.move(speedX * dt, speedY * dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(circle2);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}