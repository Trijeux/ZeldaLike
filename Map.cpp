#include "Map.h"
#include "Game.h"

Map::Map()
{
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