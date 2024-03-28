#include "Obstacle.h"

void Obstacle::initObstacles()
{
	// size
	this->ObstacleShape.setSize(sf::Vector2f(150.0f, 150.0f));
	//this->ObstacleShape.setOrigin(this->ObstacleShape.getSize() / 2.0f);
	// Set the color of the rectangle
	this->ObstacleShape.setFillColor(sf::Color::Blue);

	// Obstacles
	for (int i = 0; i < 3; i++)
	{
		this->Obstacles.push_back(this->ObstacleShape);
		// Set the position of the obstacle
		this->Obstacles[i].setPosition( ((i + 2) * this->Obstacles[i].getSize().x), 
			((i + 2) * this->Obstacles[i].getSize().y)); // x, y
	}
}
Obstacle ::Obstacle()
{
	this->initObstacles();
}
Obstacle :: ~Obstacle() { std::cout << "Obstacle Destructor\n"; };
void Obstacle::renderObstacles(sf::RenderWindow& window)
{
	for (const auto& i : Obstacles)
		window.draw(i);
}
sf::FloatRect Obstacle::getGlobBound(const sf::RectangleShape& obtacle) const
{
	return obtacle.getGlobalBounds();
}
sf::Vector2f Obstacle::getPos(const sf::RectangleShape& obtacle) const
{
	return obtacle.getPosition();
}
sf::Vector2f Obstacle::getSize(const sf::RectangleShape& obtacle) const
{
	return obtacle.getSize();
}