#include "Game.h"

Game::Game()
{
	window.create(sf::VideoMode(1000, 1000), "SFML works!");


	Sole.setSize(sf::Vector2f(50, 50));
	Mur.setSize(sf::Vector2f(50, 50));
	Pi�ge.setSize(sf::Vector2f(50, 50));
	Pi�ge_Invisible.setSize(sf::Vector2f(50, 50));
	Cl�.setSize(sf::Vector2f(50, 50));
	Exit_Cl�.setSize(sf::Vector2f(50, 50));
	Porte_Ferm�.setSize(sf::Vector2f(50, 50));
	Porte_Ouverte.setSize(sf::Vector2f(50, 50));
	Exit_Porte_Ouverte.setSize(sf::Vector2f(50, 50));
	Exit_Porte_Ferm�.setSize(sf::Vector2f(50, 50));

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	Sole.setFillColor(sf::Color::Black);
	Sole.setOutlineColor(sf::Color::White);
	Sole.setOutlineThickness(1);

	Mur.setFillColor(sf::Color::Blue);
	Mur.setOutlineColor(sf::Color::White);
	Mur.setOutlineThickness(1);

	Pi�ge.setFillColor(sf::Color::Red);
	Pi�ge.setOutlineColor(sf::Color::White);
	Pi�ge.setOutlineThickness(1);

	Pi�ge_Invisible.setFillColor(sf::Color::White);
	Pi�ge_Invisible.setOutlineColor(sf::Color::White);
	Pi�ge_Invisible.setOutlineThickness(1);

	Cl�.setFillColor(sf::Color::Yellow);
	Cl�.setOutlineColor(sf::Color::White);
	Cl�.setOutlineThickness(1);

	Exit_Cl�.setFillColor(sf::Color::Cyan);
	Exit_Cl�.setOutlineColor(sf::Color::White);
	Exit_Cl�.setOutlineThickness(1);

	Porte_Ferm�.setFillColor(sf::Color::Magenta);
	Porte_Ferm�.setOutlineColor(sf::Color::White);
	Porte_Ferm�.setOutlineThickness(1);

	Porte_Ouverte.setFillColor(sf::Color::Green);
	Porte_Ouverte.setOutlineColor(sf::Color::White);
	Porte_Ouverte.setOutlineThickness(1);

	Exit_Porte_Ouverte.setFillColor(sf::Color{ 0, 255, 0, 127 });
	Exit_Porte_Ouverte.setOutlineColor(sf::Color::White);
	Exit_Porte_Ouverte.setOutlineThickness(1);

	Exit_Porte_Ferm�.setFillColor(sf::Color{ 255, 0, 0, 127 });
	Exit_Porte_Ferm�.setOutlineColor(sf::Color::White);
	Exit_Porte_Ferm�.setOutlineThickness(1);

	tile_map.setFillColor(sf::Color::Transparent);
	tile_map.setOutlineColor(sf::Color::White);
	tile_map.setOutlineThickness(1);
}

void Game::GameLoop()
{


	while (window.isOpen())
	{
		if (chargement)
		{
			for (int y = 0; y < TILEMAP_HEIGHT; y++)
			{
				for (int x = 0; x < TILEMAP_WIDTH; x++)
				{
					tilemap[y * TILEMAP_WIDTH + x] = sole;
				}
			}
			load(level);
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

		player.GetPrevPlayerCoords() = player.GetTilePlayerCoord();

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
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == mur || tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == porte_ferm� || tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == exit_porte_ferm�)
	{
		player.GetTilePlayerCoord() = player.GetPrevPlayerCoords();
	}
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == pi�ge || tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == pi�ge_invisible)
	{
		level = 1;
		player.SetCl�('=', 0);
		player.SetExitCl�('=', 0);
		player.SetVie('-', 1);
		player.GetTilePlayerCoord() = player.GetSpawn();
		chargement = true;
	}
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == cl�)
	{
		player.SetCl�('+', 1);
		tilemap[player.GetTilePlayerCoord().y * TILEMAP_WIDTH + player.GetTilePlayerCoord().x] = sole;
	}
	if (player.GetCl�() == 1 && level == 2)
	{
		tilemap[9 * TILEMAP_WIDTH + 19] = porte_ouverte;
		tilemap[10 * TILEMAP_WIDTH + 19] = porte_ouverte;
		tilemap[7 * TILEMAP_WIDTH + 1] = sole;
	}
	if (player.GetTilePlayerCoord().x < 0 || player.GetTilePlayerCoord().x + 1 > TILEMAP_WIDTH || player.GetTilePlayerCoord().y < 0 || player.GetTilePlayerCoord().y + 1 > TILEMAP_HEIGHT || tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == exit_cl�)
	{
		player.SetExitCl�('+', 1);
		tilemap[player.GetTilePlayerCoord().y * TILEMAP_WIDTH + player.GetTilePlayerCoord().x] = sole;
	}
	if (player.GetExitCl�() == 1 && level == 3)
	{
		tilemap[7 * TILEMAP_WIDTH + 1] = sole;
	}
	if (player.GetExitCl�() == 1 && level == 1)
	{
		tilemap[9 * TILEMAP_WIDTH + 0] = exit_porte_ouverte;
		tilemap[10 * TILEMAP_WIDTH + 0] = exit_porte_ouverte;
	}
}

void Game::GraphicInGame(GameText vie_player, GameText cl�_player, GameText exit_cl�_player)
{
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

	for (int y = 0; y < TILEMAP_HEIGHT; y++)
	{

		for (int x = 0; x < TILEMAP_WIDTH; x++)
		{
			Sole.setPosition(50 * x, 50 * y);
			window.draw(Sole);

			if (tilemap[x + y * TILEMAP_WIDTH] == mur)
			{
				Mur.setPosition(50 * x, 50 * y);
				window.draw(Mur);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == pi�ge)
			{
				Pi�ge.setPosition(50 * x, 50 * y);
				window.draw(Pi�ge);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == pi�ge_invisible)
			{
				Pi�ge_Invisible.setPosition(50 * x, 50 * y);
				window.draw(Pi�ge_Invisible);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == cl�)
			{
				Cl�.setPosition(50 * x, 50 * y);
				window.draw(Cl�);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_cl�)
			{
				Exit_Cl�.setPosition(50 * x, 50 * y);
				window.draw(Exit_Cl�);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == porte_ferm�)
			{
				Porte_Ferm�.setPosition(50 * x, 50 * y);
				window.draw(Porte_Ferm�);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == porte_ouverte)
			{
				Porte_Ouverte.setPosition(50 * x, 50 * y);
				window.draw(Porte_Ouverte);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_porte_ferm�)
			{
				Exit_Porte_Ferm�.setPosition(50 * x, 50 * y);
				window.draw(Exit_Porte_Ferm�);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_porte_ouverte)
			{
				Exit_Porte_Ouverte.setPosition(50 * x, 50 * y);
				window.draw(Exit_Porte_Ouverte);
			}
		}
	}

	window.draw(player.GetShape());

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

void Game::load(int level)
{
	if (level == 1)
	{
		FILE* f = _fsopen("level.data", "rb", _SH_DENYRD);
		fread(tilemap, sizeof(tilemap), 1, f);
		fclose(f);
	}
	else if (level == 2)
	{
		FILE* f = _fsopen("level2.data", "rb", _SH_DENYRD);
		fread(tilemap, sizeof(tilemap), 1, f);
		fclose(f);
	}
	else if (level == 3)
	{
		FILE* f = _fsopen("level3.data", "rb", _SH_DENYRD);
		fread(tilemap, sizeof(tilemap), 1, f);
		fclose(f);
	}
}

//void Game::save(int level)
//{
//	if (level == 1)
//	{
//		FILE* f = _fsopen("level.data", "wb", _SH_DENYWR);
//		fwrite(tilemap, sizeof(tilemap), 1, f);
//		fclose(f);
//	}
//	else if (level == 2)
//	{
//		FILE* f = _fsopen("level2.data", "wb", _SH_DENYWR);
//		fwrite(tilemap, sizeof(tilemap), 1, f);
//		fclose(f);
//	}
//	else if (level == 3)
//	{
//		FILE* f = _fsopen("level3.data", "wb", _SH_DENYWR);
//		fwrite(tilemap, sizeof(tilemap), 1, f);
//		fclose(f);
//	}
//}
