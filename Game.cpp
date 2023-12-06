#include "Game.h"

#include <iostream>
#include <valarray>

#include "Map.h"

Game::Game()
{
	window_.create(sf::VideoMode(1000, 1000), "SFML works!");
	window_.setVerticalSyncEnabled(true);
	window_.setFramerateLimit(30);
	player_.LoadPlayer();
	view_player_.setSize(window_.getSize().x, window_.getSize().y);
	view_player_.zoom(0.2f);
	view_HUD_map_.setSize(window_.getSize().x, window_.getSize().y);
	window_.setView(view_player_);
}

void Game::GameLoop()
{
	while (window_.isOpen())
	{
		if (loading_)
		{
			map_.ResetMap();
			map_.LoadMap(level_);
			loading_ = false;
		}


		std::string num_life = std::to_string(player_.GetLife());
		std::string num_key = std::to_string(player_.GetKey());
		std::string nom_exit_key = std::to_string(player_.GetExitKey());
		GameText life_player("Vie : " + num_life, 5, 5);
		GameText key_player("Clé : " + num_key, 5, 35);
		GameText exit_key_player("Exit Clé : " + nom_exit_key, 5, 65);
		GameText gameover("Game Over vous avez perdu", 320, 400);
		gameover.GetSize(1.5, 1.5);
		GameText victory("Félicitations vous avez gagné", 320, 400);
		victory.GetSize(1.5, 1.5);
		GameText Enter("Appuyez sur Enter pour quitter", 320, 450);
		Enter.GetSize(1.5, 1.5);


		player_.SetShapePosition();

		if ((!endgame_ || !(player_.GetLife() >= 0)) && zoom_)
		{
			view_player_.setCenter(player_.GetTilePlayerCoord().x * 50 + 25, player_.GetTilePlayerCoord().y * 50 + 25);
			window_.setView(view_player_);
		}

		player_.PrevCoordInCoord();

		KeyPressed();

		Collision();

		sf::Event event;
		while (window_.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				window_.close();
				break;

			default:
				break;
			}
		}

		GraphicInGame(life_player, key_player, exit_key_player);

		GraphicEndGame(gameover, victory, Enter);

		window_.display();
	}
}

void Game::KeyPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (no_pressed_)
		{
			player_.SetTilePlayerCoord('x', '+', 1);
			no_pressed_ = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (no_pressed_)
		{
			player_.SetTilePlayerCoord('x', '-', 1);
			no_pressed_ = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (no_pressed_)
		{
			player_.SetTilePlayerCoord('y', '-', 1);
			no_pressed_ = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (no_pressed_)
		{
			player_.SetTilePlayerCoord('y', '+', 1);
			no_pressed_ = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (no_pressed_)
		{
			window_.setView(view_HUD_map_);
			zoom_ = false;
			no_pressed_ = false;
		}
	}
	else
	{
		no_pressed_ = true;
		if (!zoom_)
		{
			zoom_ = true;
		}
	}
}

void Game::Collision()
{
	if (player_.GetTilePlayerCoord().x < 0 || player_.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player_.GetTilePlayerCoord().y < 0 || player_.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map_.GetWall(player_) || map_.GetCloseDoor(player_) || map_.GetCloseExitDoor(player_))
	{
		player_.CoordInPrevCoord();
	}
	if (player_.GetTilePlayerCoord().x < 0 || player_.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player_.GetTilePlayerCoord().y < 0 || player_.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map_.GetTrap(player_) || map_.GetInvisibleTrap(player_))
	{
		level_ = 1;
		player_.SetKey('=', 0);
		player_.SetExitKey('=', 0);
		player_.SetLife('-', 1);
		player_.GoSpawn();
		player_.MovePlayer(kSpawnMove);
		loading_ = true;
	}
	if (player_.GetTilePlayerCoord().x < 0 || player_.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player_.GetTilePlayerCoord().y < 0 || player_.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map_.GetKey(player_))
	{
		player_.SetKey('+', 1);
		map_.TurnsKeyIntoSoil(player_);
	}
	if (player_.GetKey() == 1 && level_ == 2)
	{
		map_.TurnsIntoOpenDoor(19, 9);
		map_.TurnsIntoOpenDoor(19, 10);
		map_.TurnsIntoSoil(1, 7);
	}
	if (player_.GetTilePlayerCoord().x < 0 || player_.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player_.GetTilePlayerCoord().y < 0 || player_.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map_.GetExitKey(player_))
	{
		player_.SetExitKey('+', 1);
		map_.TurnsExitKeyIntoSoil(player_);
	}
	if (player_.GetExitKey() == 1 && level_ == 3)
	{
		map_.TurnsIntoSoil(1, 7);
	}
	if (player_.GetExitKey() == 1 && level_ == 1)
	{
		map_.TurnsIntoExitOpenDoor(0, 9);
		map_.TurnsIntoExitOpenDoor(0, 10);
	}



	if ((player_.GetTilePlayerCoord().x == 19 && player_.GetTilePlayerCoord().y == 9) || (player_.GetTilePlayerCoord().x == 19 && player_.GetTilePlayerCoord().y == 10))
	{
		player_.SetTilePlayerCoord('x', '=', 1);
		level_ += 1;
		loading_ = true;
	}

	else if (((player_.GetTilePlayerCoord().x == 0 && player_.GetTilePlayerCoord().y == 9) || (player_.GetTilePlayerCoord().x == 0 && player_.GetTilePlayerCoord().y == 10)) && level_ != 1)
	{
		player_.SetTilePlayerCoord('x', '=', 18);
		level_ -= 1;
		loading_ = true;
	}
	else if ((player_.GetTilePlayerCoord().x == 0 && player_.GetTilePlayerCoord().y == 9 || player_.GetTilePlayerCoord().x == 0 && player_.GetTilePlayerCoord().y == 10) && level_ == 1)
	{
		endgame_ = true;
	}
}

void Game::GraphicInGame(GameText life_player, GameText key_player, GameText exit_key_player)
{
	window_.clear(sf::Color::Black);

	map_.ObjectInGame(window_);

	window_.draw(player_.GetSprite());

	life_player.Draw(window_);
	key_player.Draw(window_);
	exit_key_player.Draw(window_);
}

void Game::GraphicEndGame(GameText gameover, GameText victory, GameText enter)
{
	if (player_.GetLife() <= 0 || endgame_)
	{
		window_.clear(sf::Color::Black);
		if (player_.GetLife() <= 0)
		{
			gameover.Draw(window_);
			endgame_ = true;
		}
		else
		{
			victory.Draw(window_);
		}
		enter.Draw(window_);
		window_.setView(view_HUD_map_);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (no_pressed_)
			{
				window_.close();
			}
		}
	}
}
