#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"

#define TILEMAP_WIDTH 20
#define TILEMAP_HEIGHT 20

class Player;
class GameText;

enum block
{
	sole = 0,
	mur = 1,
	pi�ge = 2,
	pi�ge_invisible = 3,
	cl� = 4,
	exit_cl� = 5,
	porte_ferm� = 6,
	porte_ouverte = 7,
	exit_porte_ferm� = 8,
	exit_porte_ouverte = 9
};

class Map
{
public:
	Map();

	void ObjectInGame(sf::RenderWindow& window);
	void ResteMap();
	void TurnsKeyIntoSoil(Player& player);
	void TurnsIntoOpenDoor(int x, int y);
	void TurnsIntoSoil(int x, int y);
	void TurnsExitKeyIntoSoil(Player& player);
	void TurnsIntoExitOpenDoor(int x, int y);
	bool GetExitDoorClose(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == exit_porte_ferm�; }
	bool GetDoorClose(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == porte_ferm�; }
	bool GetWall(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == mur; }
	bool GetTrap(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == pi�ge; }
	bool GetTrapInvisible(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == pi�ge_invisible; }
	bool GetKey(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == cl�; }
	bool GetExitKey(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == exit_cl�; }
	void LoadMap(int level);
	//void SaveMap(int level);

private:

	sf::RectangleShape tile_map;
	sf::RectangleShape Sole;
	sf::RectangleShape Mur;
	sf::RectangleShape Pi�ge;
	sf::RectangleShape Pi�ge_Invisible;
	sf::RectangleShape Cl�;
	sf::RectangleShape Exit_Cl�;
	sf::RectangleShape Porte_Ferm�;
	sf::RectangleShape Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Ferm�;

	int tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };
};

