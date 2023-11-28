#pragma once
#include <SFML/Graphics.hpp>

enum move
{
	up = 1,
	down = 2,
	right = 3,
	left = 4,
	spawnMove = 5
};

class Player
{
public:
	Player() = default ;

	int GetVie() { return vie; }
	int GetClé() { return num_clé; }
	int GetExitClé() { return num_exit_clé; }
	sf::Sprite GetSprite() { return tile_player; }
	sf::Vector2i GetTilePlayerCoord() { return tile_player_Coord; }
	sf::Vector2i GetPrevPlayerCoords() { return prev_player_coords; }
	void SetTilePlayerCoord(char axe, char PorN, int num);
	const sf::Vector2i GetSpawn() { sf::Vector2i spawn(5, 5); return spawn; }
	void SetClé(char PorN, int num);
	void SetExitClé(char PorN, int num);
	void SetVie(char PorN, int num);
	void SetShapePosition() { tile_player.setPosition(tile_player_Coord.x * 50 + 25, tile_player_Coord.y * 50 + 25); };
	void PrevCoordAndCoord(){ prev_player_coords = tile_player_Coord; }
	void CoordAndPrevCoord() { tile_player_Coord = prev_player_coords; }
	void GoSpawn() { tile_player_Coord = spawn; }
	void LoadPlayer();
	void MovePlayer(int num);

private:
	sf::Sprite tile_player;
	sf::Texture up_;
	sf::Texture down_;
	sf::Texture left_;
	sf::Texture right_;


	int vie = 3;
	int num_clé = 0;
	int num_exit_clé = 0;

	sf::Vector2i tile_player_Coord = sf::Vector2i(5, 5);
	const sf::Vector2i spawn = sf::Vector2i(5, 5);
	sf::Vector2i prev_player_coords;
};

