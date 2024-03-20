#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
private:
	
	sf::RectangleShape player1;

	void initPLayer();

public:
	sf::Vector2f PlayerMovement;
	float Move_Speed = 20;
	Player();
	~Player();
	void renderPlayer(sf::RenderWindow& window);

	void movePlayer(const sf::Vector2f& PlayerMovement);
	sf::FloatRect getGlobBound() const;
	sf::Vector2f getPos();
};