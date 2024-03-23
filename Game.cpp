#include "Game.h"
void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1000;
	this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "Simple Game SFML", sf::Style::Titlebar | sf::Style::Close); // smart ptr
	this->window->setFramerateLimit(60);

	this->addY = 0.0f;
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
			
			std::cout << "Player Move Y: " << this->player1.getPos().y + this->player1.getSize().y << "\n";
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
			this->addY = 0.0f;
			//this->player1.movePlayer(this->player1.PlayerMovement);
			this->player1.movePlayer(this->player1.PlayerMovement);
			if (!isCollisionY())
			{
				CurrPos.y += this->addY;
				this->player1.setPos(CurrPos);
			}

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
		if ( (Player_Right > Obs_Left) && (Player_Left  < Obs_Right)
			&& (Player_Bot >=  Obs_Top && Player_Top <= Obs_Bot))
		{
			return true; // not yet finished
		}
	}

	// Check for intersection using the bounds
	return false;
}
 bool Game::isCollisionY()
 {
	 //sf::FloatRect PlayerBounds = this->player1.getGlobBound();
	 sf::Vector2f PlayerPositions = this->player1.getPos();
	 float Player_Left = PlayerPositions.x;
	 sf::Vector2f PlayerSizes = this->player1.getSize();
	 float Player_Right = PlayerPositions.x + PlayerSizes.x;
	 float Player_Top = PlayerPositions.y;
	 float Player_Bot = PlayerPositions.y + PlayerSizes.y;
	 int count = 1;
	 for (const sf::RectangleShape& oneObs : this->obstacle.Obstacles)
	 {
		 sf::Vector2f ObstaclePos = this->obstacle.getPos(oneObs);
		 sf::Vector2f ObstacleSizes = this->obstacle.getSize(oneObs);
		 float Obs_Left = ObstaclePos.x;
		 float Obs_Right = ObstaclePos.x + ObstacleSizes.x;
		 float Obs_Top = ObstaclePos.y;
		 float Obs_Bot = ObstaclePos.y + ObstacleSizes.y;
		 //sf::FloatRect obstacleBounds = obstacle.getGlobBound(oneObs);
		 if ((Player_Bot  > Obs_Top) && (Player_Top < Obs_Bot)
			 && (Player_Right >= Obs_Left && Player_Left <= Obs_Right))
		 {
			 std::cout << count << " na obstacle\n";
			 std::cout << "Obs Top: " << Obs_Top << ", Obs Top % 20: " << static_cast<int>(Obs_Top) % 20 << 
				 ", Player Bot % 20: " << static_cast<int>(Player_Bot) % 20 << "\n";
			 /*
			 this if and else if statement is to add 10 or -10 position in y axis of the player. 
			 example: the player bot is at 440 and the head of the obstacle is 450, the player will not exceed 440
			 but in this if and else if function it will go 450 and it will not exceed 450, so that it is properly
			 bump by the logic just like in real life bump in the concrete wall.
			 this is vice versa to the obstacle bot and player top
			 |
			 v <- player bot
			 --- <- bump (Obstacle head or top )
			 
			 ______   <- bump (obstacle bot)
			 ^ <- player top
			 |
			 */
			 if ((static_cast<int>(Obs_Top) % 20 == 10 && static_cast<int>(Player_Bot) % 20 == 0)
				 || (static_cast<int>(Obs_Top) % 20 == 0 && static_cast<int>(Player_Bot) % 20 == 10))
			 {
				 this->addY = 10.0f;
			 }
			 else if ((static_cast<int>(Obs_Bot) % 20 == 10 && static_cast<int>(Player_Top) % 20 == 0)
				 || (static_cast<int>(Obs_Bot) % 20 == 0 && static_cast<int>(Player_Top) % 20 == 10))
			 {
				 this->addY = -10.0f;
			 }
			 std::cout << "Add y : " << this->addY << "\n";
			 return false; // not yet finished
		 }
		 count++;
	 }

	 // Check for intersection using the bounds
	 return true;
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