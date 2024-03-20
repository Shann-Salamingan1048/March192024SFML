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
	Obstacle();
	~Obstacle();
};