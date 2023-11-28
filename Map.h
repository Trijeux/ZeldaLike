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
	piège = 2,
	piège_invisible = 3,
	clé = 4,
	exit_clé = 5,
	porte_fermé = 6,
	porte_ouverte = 7,
	exit_porte_fermé = 8,
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
	bool GetExitDoorClose(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == exit_porte_fermé; }
	bool GetDoorClose(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == porte_fermé; }
	bool GetWall(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == mur; }
	bool GetTrap(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == piège; }
	bool GetTrapInvisible(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == piège_invisible; }
	bool GetKey(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == clé; }
	bool GetExitKey(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == exit_clé; }
	void LoadMap(int level);
	//void SaveMap(int level);

private:

	sf::RectangleShape tile_map;
	sf::RectangleShape Sole;
	sf::RectangleShape Mur;
	sf::RectangleShape Piège;
	sf::RectangleShape Piège_Invisible;
	sf::RectangleShape Clé;
	sf::RectangleShape Exit_Clé;
	sf::RectangleShape Porte_Fermé;
	sf::RectangleShape Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Fermé;

	int tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };
};

