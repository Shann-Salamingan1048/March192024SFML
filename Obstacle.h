#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Obstacle
{
private:
	void initObstacles();
	sf::RectangleShape ObstacleShape;
	std::vector<sf::RectangleShape> Obstacles;

private:
	void renderObstacles(const sf::RenderWindow& window);
	Obstacle();
	~Obstacle();
};