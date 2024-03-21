#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
class Obstacle
{
private:
	void initObstacles();
	sf::RectangleShape ObstacleShape;
	

public:
	void renderObstacles(sf::RenderWindow& window);
	std::vector<sf::RectangleShape> Obstacles;
	sf::FloatRect getGlobBound(const sf::RectangleShape& obtacle) const;
	sf::Vector2f getPos(const sf::RectangleShape& obstacle) const;
	sf::Vector2f getSize(const sf::RectangleShape& obstacle) const;
	Obstacle();
	~Obstacle();
};