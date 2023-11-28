#include "Map.h"
#include "Game.h"

void Map::ObjectInGame(sf::RenderWindow& window)
{
	for (int y = 0; y < TILEMAP_HEIGHT; y++)
	{

		for (int x = 0; x < TILEMAP_WIDTH; x++)
		{
			sole_sprite_.setPosition(50 * x, 50 * y);
			sole_sprite_.setTexture(sole_texture_);
			window.draw(sole_sprite_);

			if (tilemap[x + y * TILEMAP_WIDTH] == mur)
			{
				mur_sprite_.setPosition(50 * x, 50 * y);
				mur_sprite_.setTexture(mur_texture_);
				window.draw(mur_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == pi�ge)
			{
				pi�ge_sprite_.setPosition(50 * x, 50 * y);
				pi�ge_sprite_.setTexture(pi�ge_texture_);
				window.draw(pi�ge_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == pi�ge_invisible)
			{
				pi�ge_invisible_sprite_.setPosition(50 * x, 50 * y);
				pi�ge_invisible_sprite_.setTexture(sole_texture_);
				window.draw(pi�ge_invisible_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == cl�)
			{
				cl�_sprite_.setPosition(50 * x, 50 * y);
				cl�_sprite_.setTexture(cl�_texture_);
				window.draw(cl�_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_cl�)
			{
				exit_cl�_sprite_.setPosition(50 * x, 50 * y);
				exit_cl�_sprite_.setTexture(exit_cl�_texture_);
				window.draw(exit_cl�_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == porte_ferm�)
			{
				porte_ferm�_sprite_.setPosition(50 * x, 50 * y);
				porte_ferm�_sprite_.setTexture(porte_ferm�_texture_);
				window.draw(porte_ferm�_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == porte_ouverte)
			{
				porte_ouverte_sprite_.setPosition(50 * x, 50 * y);
				porte_ouverte_sprite_.setTexture(sole_texture_);
				window.draw(porte_ouverte_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_porte_ferm�)
			{
				exit_porte_ferm�_sprite_.setPosition(50 * x, 50 * y);
				exit_porte_ferm�_sprite_.setTexture(exit_porte_ferm�_texture_);
				window.draw(exit_porte_ferm�_sprite_);
			}
			else if (tilemap[x + y * TILEMAP_WIDTH] == exit_porte_ouverte)
			{
				exit_porte_ouverte_sprite_.setPosition(50 * x, 50 * y);
				exit_porte_ouverte_sprite_.setTexture(sole_texture_);
				window.draw(exit_porte_ouverte_sprite_);
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
	
	sole_texture_.loadFromFile("Sprite\\Map\\Ground.png");
	mur_texture_.loadFromFile("Sprite\\Map\\Wall.png");
	pi�ge_texture_.loadFromFile("Sprite\\Map\\Trap.png");
	cl�_texture_.loadFromFile("Sprite\\Map\\Key.png");
	exit_cl�_texture_.loadFromFile("Sprite\\Map\\Master-Key.png");
	porte_ferm�_texture_.loadFromFile("Sprite\\Map\\Close-Door.png");
	exit_porte_ferm�_texture_.loadFromFile("Sprite\\Map\\Close-Exit-Door.png");
}