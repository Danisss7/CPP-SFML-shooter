#pragma once

#include "Player.h"

/*Class that acts as the game engine.
Wrapper.class.*/

class Game
{
private:
	sf::RenderWindow* window;
	
	//Player
	Player* player;

	//Private functions
	void initWindow();
	void initPlayer();
public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void update();
	void render();
};
