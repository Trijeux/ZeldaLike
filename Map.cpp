#include "Map.h"
#include "Game.h"

void Map::ObjectInGame(sf::RenderWindow& window)
{
	for (int y = 0; y < TILEMAP_HEIGHT; y++)
	{

		for (int x = 0; x < TILEMAP_WIDTH; x++)
		{
			ground_sprite_.setPosition(50 * x, 50 * y);
			ground_sprite_.setTexture(ground_texture_);
			window.draw(ground_sprite_);

			if (tilemap[x + y * TILEMAP_WIDTH] == kMur)
			{
				wall_sprite_.setPosition(50 * x, 50 * y);
				wall_sprite_.setTexture(wall_texture_);
				window.draw(wall_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kTrap)
			{
				trap_sprite_.setPosition(50 * x, 50 * y);
				trap_sprite_.setTexture(trap_texture_);
				window.draw(trap_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kInvisibleTrap)
			{
				invisible_trap_sprite_.setPosition(50 * x, 50 * y);
				invisible_trap_sprite_.setTexture(ground_texture_);
				window.draw(invisible_trap_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kKey)
			{
				key_sprite_.setPosition(50 * x, 50 * y);
				key_sprite_.setTexture(key_texture_);
				window.draw(key_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kExitKey)
			{
				exit_key_sprite_.setPosition(50 * x, 50 * y);
				exit_key_sprite_.setTexture(exit_key_texture_);
				window.draw(exit_key_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kCloseDoor)
			{
				close_door_sprite_.setPosition(50 * x, 50 * y);
				close_door_sprite_.setTexture(close_door_texture_);
				window.draw(close_door_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kOpenDoor)
			{
				open_door_sprite_.setPosition(50 * x, 50 * y);
				open_door_sprite_.setTexture(ground_texture_);
				window.draw(open_door_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kCloseExitDoor)
			{
				close_exit_door_sprite_.setPosition(50 * x, 50 * y);
				close_exit_door_sprite_.setTexture(close_exit_door_texture_);
				window.draw(close_exit_door_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == kOpenExitDoor)
			{
				open_exit_door_sprite_.setPosition(50 * x, 50 * y);
				open_exit_door_sprite_.setTexture(ground_texture_);
				window.draw(open_exit_door_sprite_);
			}
		}
	}
}

void Map::ResetMap()
{
	for (int y = 0; y < TILEMAP_HEIGHT; y++)
	{
		for (int x = 0; x < TILEMAP_WIDTH; x++)
		{
			tilemap[y * TILEMAP_WIDTH + x] = kSole;
		}
	}
}

void Map::TurnsKeyIntoSoil(Player& player)
{
	tilemap[player.GetTilePlayerCoord().y * TILEMAP_WIDTH + player.GetTilePlayerCoord().x] = kSole;
}

void Map::TurnsIntoOpenDoor(int x, int y)
{
	tilemap[y * TILEMAP_WIDTH + x] = kOpenDoor;
}

void Map::TurnsIntoExitOpenDoor(int x, int y)
{
	tilemap[y * TILEMAP_WIDTH + x] = kOpenExitDoor;
}

void Map::TurnsIntoSoil(int x, int y)
{
	tilemap[y * TILEMAP_WIDTH + x] = kSole;
}

void Map::TurnsExitKeyIntoSoil(Player& player)
{
	tilemap[player.GetTilePlayerCoord().y * TILEMAP_WIDTH + player.GetTilePlayerCoord().x] = kSole;
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
	
	ground_texture_.loadFromFile("Sprite\\Map\\Ground.png");
	wall_texture_.loadFromFile("Sprite\\Map\\Wall.png");
	trap_texture_.loadFromFile("Sprite\\Map\\Trap.png");
	key_texture_.loadFromFile("Sprite\\Map\\Key.png");
	exit_key_texture_.loadFromFile("Sprite\\Map\\Master-Key.png");
	close_door_texture_.loadFromFile("Sprite\\Map\\Close-Door.png");
	close_exit_door_texture_.loadFromFile("Sprite\\Map\\Close-Exit-Door.png");
}