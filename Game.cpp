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
			
			std::cout << "Player Curr Pos X: " << CurrPos.x << "\n";
				//"Player Curr Pos Y: " << CurrPos.y << "\n";
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
			if (!isCollisionX())
			{
				this->player1.movePlayer(this->player1.PlayerMovement);
			}
			
			// kuyang pa ng isCollionY
			break;
		default:
			break;
		}
	}
}
 bool Game::isCollisionX() 
{
	//sf::FloatRect PlayerBounds = this->player1.getGlobBound();
	sf::Vector2f PlayerPositions = this->player1.getPos();
	float Player_Left = PlayerPositions.x;
	sf::Vector2f PlayerSizes = this->player1.getSize();
	float Player_Right = PlayerPositions.x + PlayerSizes.x;
	float Player_Top = PlayerPositions.y;
	float Player_Bot = PlayerPositions.y + PlayerSizes.y;
	for (const sf::RectangleShape& oneObs : this->obstacle.Obstacles) 
	{
		sf::Vector2f ObstaclePos = this->obstacle.getPos(oneObs);
		sf::Vector2f ObstacleSizes = this->obstacle.getSize(oneObs);
		float Obs_Left = ObstaclePos.x;
		float Obs_Right = ObstaclePos.x + ObstacleSizes.x;
		float Obs_Top = ObstaclePos.y;
		float Obs_Bot = ObstaclePos.y + ObstacleSizes.y;
		//sf::FloatRect obstacleBounds = obstacle.getGlobBound(oneObs);
		if ( (Player_Right + this->player1.PlayerMovement.x > Obs_Left) && (Player_Left + this->player1.PlayerMovement.x < Obs_Right)
			&& (Player_Bot >=  Obs_Top && Player_Top <= Obs_Bot))
		{
			this->player1.PlayerMovement.x = (this->player1.PlayerMovement.x + Player_Right) - Obs_Left;
			std::cout << "Player X Motion: " << this->player1.PlayerMovement.x << "\n";
			std::cout << "Player Right: " << Player_Right << "\n";
			std::cout << "Obstacle Left: " << Obs_Left << "\n";
			return true; // not yet finished
		}
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