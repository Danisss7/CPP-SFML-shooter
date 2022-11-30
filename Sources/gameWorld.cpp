#include "gameWorld.h"

using namespace sf;
using namespace std;

GameWorld::GameWorld() {
	gridLength = 8;
	setUpInitialState();
}

void GameWorld::setUpInitialState() {
	exitPos = sf::Vector2i(1, 0);
	playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
	setUpEnemyPositions();
	setUpTiles();
}

void GameWorld::setUpEnemyPositions() {
	enemyPositions.clear();
	enemmyPositions.push_back(sf::vector2i(0, 2));
	enemmyPositions.push_back(sf::vector2i(6, 0));
	enemmyPositions.push_back(sf::vector2i(2, 7));
}

void GameWorld::setUpTiles() {
	tiles.clear();
	std::vector<GameTile*> firstRow;
	firstRow.push_back(new GameTile("Resources/Map.png", 0, 0, false, false));
	firstRow.push_back(new GameTile("Resources/door.png", 50, 0, true, true));
	firstRow.push_back(new GameTile("Resources/Map.png", 100, 0, false, false));
	firstRow.push_back(new GameTile("Resources/Map.png", 150, 0, false, false));
	firstRow.push_back(new GameTile("Resources/Map.png", 200, 0, false, false));
	firstRow.push_back(new GameTile("Resources/Map.png", 250, 0, false, false));
	firstRow.push_back(new GameTile("Resources/Goomba.png", 300, 0, true, false));
	firstRow.push_back(new GameTile("Resources/Map.png", 350, 0, false, false));
	tiles.push_back(firstRow);

	std::vector<GameTile*> secondRow;
	secondRow.push_back(new GameTile("Resources/Map.png", 0, 50, false, false));
	secondRow.push_back(new GameTile("Resources/ground.png", 50, 50, true, false));
	secondRow.push_back(new GameTile("Resources/ground.png", 100, 50, true, false));
	secondRow.push_back(new GameTile("Resources/ground.png", 150, 50, true, false));
	secondRow.push_back(new GameTile("Resources/ground.png", 200, 50, true, false));
	secondRow.push_back(new GameTile("Resources/ground.png", 250, 50, true, false));
	secondRow.push_back(new GameTile("Resources/ground.png", 300, 50, true, false));
	secondRow.push_back(new GameTile("Resources/ground.png", 350, 50, true, false));
	tiles.push_back(secondRow);
}