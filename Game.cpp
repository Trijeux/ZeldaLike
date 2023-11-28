#include "Game.h"

#include "Map.h"

Game::Game()
{
	window.create(sf::VideoMode(1000, 1000), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	player.LoadPlayer();
}

void Game::GameLoop()
{
	while (window.isOpen())
	{
		if (chargement)
		{
			map.ResteMap();
			map.LoadMap(level);
			chargement = false;
		}



		std::string nomber_vie = std::to_string(player.GetVie());
		std::string nomber_cl� = std::to_string(player.GetCl�());
		std::string nomber_exit_cl� = std::to_string(player.GetExitCl�());
		GameText vie_player("Vie : " + nomber_vie, 5, 5);
		GameText cl�_player("Cl� : " + nomber_cl�, 5, 35);
		GameText exit_cl�_player("Exit Cl� : " + nomber_exit_cl�, 5, 65);
		GameText gameover("Game Over vous avez perdu", 320, 400);
		gameover.getSize(1.5, 1.5);
		GameText victory("F�licitations vous avez gagn�", 320, 400);
		victory.getSize(1.5, 1.5);
		GameText Enter("Appuyez sur Enter pour quitter", 320, 450);
		Enter.getSize(1.5, 1.5);

		//Met la position du joueur sur le plateau
		player.SetShapePosition();

		player.PrevCoordAndCoord();

		Move();

		Collision();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				window.close();
				break;

			default:
				break;
			}
		}

		map.ObjectInGame(window);

		GraphicInGame(vie_player, cl�_player, exit_cl�_player);

		GraphicEndGame(gameover, victory, Enter);

		window.display();
	}
}

void Game::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (no_pressed)
		{
			player.SetTilePlayerCoord('x', '+', 1);
			no_pressed = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (no_pressed)
		{
			player.SetTilePlayerCoord('x', '-', 1);
			no_pressed = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (no_pressed)
		{
			player.SetTilePlayerCoord('y', '-', 1);
			no_pressed = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (no_pressed)
		{
			player.SetTilePlayerCoord('y', '+', 1);
			no_pressed = false;
		}
	}
	else
	{
		no_pressed = true;
	}
}

void Game::Collision()
{
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map.GetWall(player) || map.GetDoorClose(player) || map.GetExitDoorClose(player))
	{
		player.CoordAndPrevCoord();
	}
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map.GetTrap(player) || map.GetTrapInvisible(player))
	{
		level = 1;
		player.SetCl�('=', 0);
		player.SetExitCl�('=', 0);
		player.SetVie('-', 1);
		player.GoSpawn();
		player.MovePlayer(spawnMove);
		chargement = true;
	}
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map.GetKey(player))
	{
		player.SetCl�('+', 1);
		map.TurnsKeyIntoSoil(player);
	}
	if (player.GetCl�() == 1 && level == 2)
	{
		map.TurnsIntoOpenDoor(19, 9);
		map.TurnsIntoOpenDoor(19, 10);
		map.TurnsIntoSoil(1, 7);
	}
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || map.GetExitKey(player))
	{
		player.SetExitCl�('+', 1);
		map.TurnsExitKeyIntoSoil(player);
	}
	if (player.GetExitCl�() == 1 && level == 3)
	{
		map.TurnsIntoSoil(1, 7);
	}
	if (player.GetExitCl�() == 1 && level == 1)
	{
		map.TurnsIntoExitOpenDoor(0, 9);
		map.TurnsIntoExitOpenDoor(0, 10);
	}

	window.clear(sf::Color::Black);

	if ((player.GetTilePlayerCoord().x == 19 && player.GetTilePlayerCoord().y == 9) || (player.GetTilePlayerCoord().x == 19 && player.GetTilePlayerCoord().y == 10))
	{
		player.SetTilePlayerCoord('x', '=', 1);
		level += 1;
		chargement = true;
	}

	else if (((player.GetTilePlayerCoord().x == 0 && player.GetTilePlayerCoord().y == 9) || (player.GetTilePlayerCoord().x == 0 && player.GetTilePlayerCoord().y == 10)) && level != 1)
	{
		player.SetTilePlayerCoord('x', '=', 18);
		level -= 1;
		chargement = true;
	}
	else if ((player.GetTilePlayerCoord().x == 0 && player.GetTilePlayerCoord().y == 9 || player.GetTilePlayerCoord().x == 0 && player.GetTilePlayerCoord().y == 10) && level == 1)
	{
		endgame = true;
	}
}

void Game::GraphicInGame(GameText vie_player, GameText cl�_player, GameText exit_cl�_player)
{
	window.draw(player.GetSprite());

	vie_player.Draw(window);
	cl�_player.Draw(window);
	exit_cl�_player.Draw(window);
}

void Game::GraphicEndGame(GameText gameover, GameText victory, GameText Enter)
{
	if (player.GetVie() <= 0)
	{
		window.clear(sf::Color::Black);
		gameover.Draw(window);
		Enter.Draw(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (no_pressed)
			{
				window.close();
			}
		}
	}
	else if (endgame)
	{
		window.clear(sf::Color::Black);
		victory.Draw(window);
		Enter.Draw(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (no_pressed)
			{
				window.close();
			}
		}
	}
}