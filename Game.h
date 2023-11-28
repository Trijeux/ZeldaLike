#pragma once
#include <SFML/Graphics.hpp>
#include "GameText.h"
#include "Map.h"
#include "Player.h"






class Game
{
public:
	Game();

	void GameLoop();
	void Move();
	void Collision();
	void GraphicInGame(GameText vie_player, GameText clé_player, GameText exit_clé_player);
	void GraphicEndGame(GameText gameover, GameText victory, GameText Enter);
	


private:
	sf::RenderWindow window;

	bool no_pressed = true;

	Player player;
	Map map;

	int level = 1;
	bool chargement = true;
	bool endgame = false;
};

