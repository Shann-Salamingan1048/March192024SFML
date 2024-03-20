#include "Player.h"

void Player::initPLayer()
{
	// size
	this->player1.setSize(sf::Vector2f(100.0f, 50.0f));
	// Set the position of the rectangle
	this->player1.setPosition(50.0f, 50.0f); // x, y

	// Set the color of the rectangle
	this->player1.setFillColor(sf::Color::Red);
}
Player::Player()
{
	this->initPLayer();

}
Player :: ~Player() { std::cout << "Player Destructor!\n"; }

void Player::renderPlayer(sf::RenderWindow& window)
{
	window.draw(this->player1);
}
void Player::movePlayer(const sf::Vector2f& PlayerMovement)
{
	this->player1.move(PlayerMovement);
}
sf::Vector2f Player::getPos()
{
	return this->player1.getPosition();
}
sf::FloatRect Player::getGlobBound() const
{
	return this->player1.getGlobalBounds();
}