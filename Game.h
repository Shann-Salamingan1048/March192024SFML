#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include "Player.h"
#include "Obstacle.h"
class Game
{
private:
	std::unique_ptr<sf::RenderWindow> window; // use smart pointers
	sf::Event event;
	sf::VideoMode videoMode;
	Player player1;
	Obstacle obstacle;
	void initWindow();
	bool isCollisionX();
	bool isCollisionY();
	float addY;
public:
	Game();
	~Game();
	const bool isRunning() const;
	void pollEvents();

	void update();
	void render();
};