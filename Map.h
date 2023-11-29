#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"

#define TILEMAP_WIDTH 20
#define TILEMAP_HEIGHT 20

class Player;
class GameText;

enum Block
{
	kSole = 0,
	kMur = 1,
	kTrap = 2,
	kInvisibleTrap = 3,
	kKey = 4,
	kExitKey = 5,
	kCloseDoor = 6,
	kOpenDoor = 7,
	kCloseExitDoor = 8,
	kOpenExitDoor = 9
};

class Map
{
public:
	Map() = default;

	void ObjectInGame(sf::RenderWindow& window);
	void ResetMap();
	void TurnsKeyIntoSoil(Player& player);
	void TurnsIntoOpenDoor(int x, int y);
	void TurnsIntoSoil(int x, int y);
	void TurnsExitKeyIntoSoil(Player& player);
	void TurnsIntoExitOpenDoor(int x, int y);
	bool GetCloseExitDoor(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == kCloseExitDoor; }
	bool GetCloseDoor(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == kCloseDoor; }
	bool GetWall(Player& player) { return tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == kMur; }
	bool GetTrap(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == kTrap; }
	bool GetInvisibleTrap(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == kInvisibleTrap; }
	bool GetKey(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == kKey; }
	bool GetExitKey(Player& player) { return  tilemap[player.GetTilePlayerCoord().x + player.GetTilePlayerCoord().y * TILEMAP_WIDTH] == kExitKey; }
	void LoadMap(int level);
	//void SaveMap(int level_);

private:

	sf::Sprite ground_sprite_;
	sf::Sprite wall_sprite_;
	sf::Sprite trap_sprite_;
	sf::Sprite invisible_trap_sprite_;
	sf::Sprite key_sprite_;
	sf::Sprite exit_key_sprite_;
	sf::Sprite close_door_sprite_;
	sf::Sprite open_door_sprite_;
	sf::Sprite open_exit_door_sprite_;
	sf::Sprite close_exit_door_sprite_;


	sf::Texture ground_texture_;
	sf::Texture wall_texture_;
	sf::Texture trap_texture_;
	sf::Texture key_texture_;
	sf::Texture exit_key_texture_;
	sf::Texture close_door_texture_;
	sf::Texture close_exit_door_texture_;

	int tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };
};

