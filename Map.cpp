#include "Map.h"
#include "Game.h"

Map::Map()
{
	Sole.setSize(sf::Vector2f(50, 50));
	Mur.setSize(sf::Vector2f(50, 50));
	Piège.setSize(sf::Vector2f(50, 50));
	Piège_Invisible.setSize(sf::Vector2f(50, 50));
	Clé.setSize(sf::Vector2f(50, 50));
	Exit_Clé.setSize(sf::Vector2f(50, 50));
	Porte_Fermé.setSize(sf::Vector2f(50, 50));
	Porte_Ouverte.setSize(sf::Vector2f(50, 50));
	Exit_Porte_Ouverte.setSize(sf::Vector2f(50, 50));
	Exit_Porte_Fermé.setSize(sf::Vector2f(50, 50));

	Sole.setFillColor(sf::Color::Black);
	Sole.setOutlineColor(sf::Color::White);
	Sole.setOutlineThickness(1);

	Mur.setFillColor(sf::Color::Blue);
	Mur.setOutlineColor(sf::Color::White);
	Mur.setOutlineThickness(1);

	Piège.setFillColor(sf::Color::Red);
	Piège.setOutlineColor(sf::Color::White);
	Piège.setOutlineThickness(1);

	Piège_Invisible.setFillColor(sf::Color::White);
	Piège_Invisible.setOutlineColor(sf::Color::White);
	Piège_Invisible.setOutlineThickness(1);

	Clé.setFillColor(sf::Color::Yellow);
	Clé.setOutlineColor(sf::Color::White);
	Clé.setOutlineThickness(1);

	Exit_Clé.setFillColor(sf::Color::Cyan);
	Exit_Clé.setOutlineColor(sf::Color::White);
	Exit_Clé.setOutlineThickness(1);

	Porte_Fermé.setFillColor(sf::Color::Magenta);
	Porte_Fermé.setOutlineColor(sf::Color::White);
	Porte_Fermé.setOutlineThickness(1);

	Porte_Ouverte.setFillColor(sf::Color::Green);
	Porte_Ouverte.setOutlineColor(sf::Color::White);
	Porte_Ouverte.setOutlineThickness(1);

	Exit_Porte_Ouverte.setFillColor(sf::Color{ 0, 255, 0, 127 });
	Exit_Porte_Ouverte.setOutlineColor(sf::Color::White);
	Exit_Porte_Ouverte.setOutlineThickness(1);

	Exit_Porte_Fermé.setFillColor(sf::Color{ 255, 0, 0, 127 });
	Exit_Porte_Fermé.setOutlineColor(sf::Color::White);
	Exit_Porte_Fermé.setOutlineThickness(1);

	tile_map.setFillColor(sf::Color::Transparent);
	tile_map.setOutlineColor(sf::Color::White);
	tile_map.setOutlineThickness(1);
}

void Map::ObjectInGame(sf::RenderWindow& window)
{
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
			else if (tilemap[x + y * TILEMAP_WIDTH] == piège)
			{
				Piège.setPosition(50 * x, 50 * y);
				window.draw(Piège);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == piège_invisible)
			{
				Piège_Invisible.setPosition(50 * x, 50 * y);
				window.draw(Piège_Invisible);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == clé)
			{
				Clé.setPosition(50 * x, 50 * y);
				window.draw(Clé);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_clé)
			{
				Exit_Clé.setPosition(50 * x, 50 * y);
				window.draw(Exit_Clé);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == porte_fermé)
			{
				Porte_Fermé.setPosition(50 * x, 50 * y);
				window.draw(Porte_Fermé);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == porte_ouverte)
			{
				Porte_Ouverte.setPosition(50 * x, 50 * y);
				window.draw(Porte_Ouverte);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_porte_fermé)
			{
				Exit_Porte_Fermé.setPosition(50 * x, 50 * y);
				window.draw(Exit_Porte_Fermé);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_porte_ouverte)
			{
				Exit_Porte_Ouverte.setPosition(50 * x, 50 * y);
				window.draw(Exit_Porte_Ouverte);
			}
		}
	}
}

void Map::ResteMap()
{
	for (int y = 0; y < TILEMAP_HEIGHT; y++)
	{
		for (int x = 0; x < TILEMAP_WIDTH; x++)
		{
			tilemap[y * TILEMAP_WIDTH + x] = sole;
		}
	}
}

void Map::TurnsKeyIntoSoil(Player& player)
{
	tilemap[player.GetTilePlayerCoord().y * TILEMAP_WIDTH + player.GetTilePlayerCoord().x] = sole;
}

void Map::TurnsIntoOpenDoor(int x, int y)
{
	tilemap[y * TILEMAP_WIDTH + x] = porte_ouverte;
}

void Map::TurnsIntoExitOpenDoor(int x, int y)
{
	tilemap[y * TILEMAP_WIDTH + x] = exit_porte_ouverte;
}

//void Map::SaveMap(int level)
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

void Map::TurnsIntoSoil(int x, int y)
{
	tilemap[y * TILEMAP_WIDTH + x] = sole;
}

void Map::TurnsExitKeyIntoSoil(Player& player)
{
	tilemap[player.GetTilePlayerCoord().y * TILEMAP_WIDTH + player.GetTilePlayerCoord().x] = sole;
}

void Map::LoadMap(int level)
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