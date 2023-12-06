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
	void KeyPressed();
	void Collision();
	void GraphicInGame(GameText life_player, GameText key_player, GameText exit_key_player);
	void GraphicEndGame(GameText gameover, GameText victory, GameText enter);
	


private:
	sf::RenderWindow window_;
	sf::View view_player_;
	sf::View view_HUD_map_;

	bool no_pressed_ = true;

	Player player_;
	Map map_;

	int level_ = 1;
	bool loading_ = true;
	bool endgame_ = false;
	bool zoom_ = true;
};

