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
	while (this->window->pollEvent(event))  // movements of the player
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
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
			this->player1.movePlayer(this->player1.PlayerMovement);
			break;
		default:
			break;
		}
	}
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


	this->window->display();
}