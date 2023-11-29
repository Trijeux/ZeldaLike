#pragma once
#include <SFML/Graphics.hpp>

enum move
{
	kUp = 1,
	kDown = 2,
	kRight = 3,
	kLeft = 4,
	kSpawnMove = 5
};

class Player
{
public:
	Player() = default ;

	int GetLife() { return life_; }
	int GetKey() { return num_key_; }
	int GetExitKey() { return num_exit_key_; }
	sf::Sprite GetSprite() { return sprite_player_; }
	sf::Vector2i GetTilePlayerCoord() { return sprite_player_Coord_; }
	sf::Vector2i GetPrevPlayerCoords() { return prev_player_coords_; }
	void SetTilePlayerCoord(char axe, char PorN, int num);
	const sf::Vector2i GetSpawn() { sf::Vector2i spawn(5, 5); return spawn; }
	void SetKey(char PorN, int num);
	void SetExitKey(char PorN, int num);
	void SetLife(char PorN, int num);
	void SetShapePosition() { sprite_player_.setPosition(sprite_player_Coord_.x * 50 + 25, sprite_player_Coord_.y * 50 + 25); };
	void PrevCoordInCoord(){ prev_player_coords_ = sprite_player_Coord_; }
	void CoordInPrevCoord() { sprite_player_Coord_ = prev_player_coords_; }
	void GoSpawn() { sprite_player_Coord_ = spawn_; }
	void LoadPlayer();
	void MovePlayer(int num);

private:
	sf::Sprite sprite_player_;
	sf::Texture up_;
	sf::Texture down_;
	sf::Texture left_;
	sf::Texture right_;


	int life_ = 3;
	int num_key_ = 0;
	int num_exit_key_ = 0;

	sf::Vector2i sprite_player_Coord_ = sf::Vector2i(5, 5);
	const sf::Vector2i spawn_ = sf::Vector2i(5, 5);
	sf::Vector2i prev_player_coords_;
};

