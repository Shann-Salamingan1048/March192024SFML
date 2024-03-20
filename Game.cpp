#include "Game.h"
void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1000;
	this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "Simple Game SFML", sf::Style::Titlebar | sf::Style::Close); // smart ptr
	this->window->setFramerateLimit(60);

}
Game::Game()
{
	this->initWindow();

}
Game::~Game() // destructor
{
	std::cout << "Game.h Destructor!\n";
}
const bool Game::isRunning() const
{
	return this->window->isOpen();
}
void Game::pollEvents()
{
	sf::Vector2f CurrPos = this->player1.getPos();
	while (this->window->pollEvent(event))  // movements of the player
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			
			std::cout << "Player Curr Pos X: " << CurrPos.x << "\nPlayer Curr Pos Y: " << CurrPos.y << "\n";
			switch (event.key.code)
			{
			case sf::Keyboard::A:
				this->player1.PlayerMovement.x = -(this->player1.Move_Speed);
				this->player1.PlayerMovement.y = 0.0f;
				break;
			case sf::Keyboard::D:
				this->player1.PlayerMovement.x = this->player1.Move_Speed;
				this->player1.PlayerMovement.y = 0.0f;
				break;
			case sf::Keyboard::W:
				this->player1.PlayerMovement.y = -(this->player1.Move_Speed);
				this->player1.PlayerMovement.x = 0.0f;
				break;
			case sf::Keyboard::S:
				this->player1.PlayerMovement.y = this->player1.Move_Speed;
				this->player1.PlayerMovement.x = 0.0f;
				break;
			}
			//this->player1.movePlayer(this->player1.PlayerMovement);
			if(!isCollisionX())
				this->player1.movePlayer(this->player1.PlayerMovement);
			break;
		default:
			break;
		}
	}
}
const bool Game::isCollisionX() const
{
	sf::FloatRect PlayerBounds = this->player1.getGlobBound();

	for (const sf::RectangleShape& oneObs : this->obstacle.Obstacles) 
	{
		sf::FloatRect obstacleBounds = obstacle.getGlobBound(oneObs);
		if (PlayerBounds.left + PlayerBounds.width + this->player1.PlayerMovement.x > obstacleBounds.left)
		{

			return true; // not yet finished
		}
		//if (PlayerBounds.left < PlayerBounds.left + obstacleBounds.width &&
		//	PlayerBounds.left + PlayerBounds.width > obstacleBounds.left)
		//{
		//	return true; // Collision detected with this obstacle
		//}
	}

	// Check for intersection using the bounds
	return false;
}
void Game::update()
{
	this->pollEvents();
}
void Game::render()
{
	this->window->clear();
	// render
	this->player1.renderPlayer(*this->window);
	this->obstacle.renderObstacles(*this->window);

	this->window->display();
}