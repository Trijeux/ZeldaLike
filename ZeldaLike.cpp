#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>

#define TILEMAP_WIDTH 20
#define TILEMAP_HEIGHT 20

static  bool tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };
constexpr int kHorizontalMaxSpeed = 1;

void save()
{
	FILE* f = _fsopen("level.data", "wb", _SH_DENYWR);
	fwrite(tilemap, sizeof(tilemap), 1, f);
	fclose(f);
}

void load()
{
	FILE* f = _fsopen("level.data", "rb", _SH_DENYRD);
	fread(tilemap, sizeof(tilemap), 1, f);
	fclose(f);
}

int main()
{
	/*tilemap[0] = true;
	tilemap[TILEMAP_WIDTH - 1] = true;
	tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT - 1] = true;
	int x = 5;
	int y = 1;
	tilemap[x + TILEMAP_WIDTH * y] = true;*/


	//for (int i = 0; i < TILEMAP_WIDTH * TILEMAP_HEIGHT; i++)
	//{
	//	std::cout << "cell idx " << i << " = " << tilemap[i] << std::endl;
	//}

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::RectangleShape tile_shape(sf::Vector2f(50, 50));
	//sf::RectangleShape tile_cursor(sf::Vector2f(50, 50));
	sf::RectangleShape tile_map(sf::Vector2f(50, 50));
	sf::CircleShape tile_player(15);


	tile_shape.setFillColor(sf::Color::Blue);
	tile_shape.setOutlineColor(sf::Color::White);
	tile_shape.setOutlineThickness(2);
	//tile_shape.setOrigin(tile_shape.getSize().x, tile_shape.getSize().y);

	/*tile_cursor.setFillColor(sf::Color::Transparent);
	tile_cursor.setOutlineColor(sf::Color::White);
	tile_cursor.setOutlineThickness(2);*/
	//tile_cursor.setOrigin(tile_cursor.getSize().x, tile_cursor.getSize().y);

	tile_map.setFillColor(sf::Color::Transparent);
	tile_map.setOutlineColor(sf::Color::White);
	tile_map.setOutlineThickness(1);
	//tile_map.setOrigin(tile_map.getSize().x, tile_map.getSize().y);

	tile_player.setFillColor(sf::Color::Red);
	tile_player.setOutlineColor(sf::Color::Green);
	tile_player.setOutlineThickness(1);
	tile_player.setOrigin(tile_player.getRadius(), tile_player.getRadius());
	sf::Vector2i tile_player_Coord(1, 1);

	//std::cout << "Clique gauche mettre un mur clique droit enlever un mur" << std::endl << "F5 sauvgarder / F9 Charger / W Haut / S Bas / A Gauche / D Droite";

	load();

	bool no_pressed = true;

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);

		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
		sf::Vector2i mouse_tile_Coord(mouse_pos.x / 50, mouse_pos.y / 50);

		tile_player.setPosition(tile_player_Coord.x * 50 + 25, tile_player_Coord.y * 50 + 25);

#pragma region Edit Level
		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (mouse_tile_Coord.x < 0 || mouse_tile_Coord.x + 1 > TILEMAP_WIDTH || mouse_tile_Coord.y < 0 || mouse_tile_Coord.y + 1 > TILEMAP_HEIGHT)
			{
				std::cout << "No" << std::endl;
			}
			else
			{
				tilemap[mouse_tile_Coord.y * TILEMAP_WIDTH + mouse_tile_Coord.x] = true;
			}
		}*/

		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (mouse_tile_Coord.x < 0 || mouse_tile_Coord.x + 1 > TILEMAP_WIDTH || mouse_tile_Coord.y < 0 || mouse_tile_Coord.y + 1 > TILEMAP_HEIGHT)
			{
				std::cout << "No" << std::endl;
			}
			else
			{
				tilemap[mouse_tile_Coord.y * TILEMAP_WIDTH + mouse_tile_Coord.x] = false;
			}
		}*/
#pragma endregion

		sf::Vector2i prev_player_coords = tile_player_Coord;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (no_pressed)
			{
				tile_player_Coord.x += 1;
				no_pressed = false;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (no_pressed)
			{
				tile_player_Coord.x -= 1;
				no_pressed = false;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (no_pressed)
			{
				tile_player_Coord.y -= 1;
				no_pressed = false;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (no_pressed)
			{
				tile_player_Coord.y += 1;
				no_pressed = false;
			}
		}
		else
		{
			no_pressed = true;
		}
		if (tile_player_Coord.x < 0 || tile_player_Coord.x + 1 > TILEMAP_WIDTH || tile_player_Coord.y < 0 || tile_player_Coord.y + 1 > TILEMAP_HEIGHT || tilemap[tile_player_Coord.x + tile_player_Coord.y * TILEMAP_WIDTH] == true)
		{
			tile_player_Coord = prev_player_coords;
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		/*tile_cursor.setPosition(50 * mouse_tile_Coord.x, 50 * mouse_tile_Coord.y);
		window.draw(tile_cursor);*/

		for (int y = 0; y < TILEMAP_HEIGHT; y++)
		{
			for (int x = 0; x < TILEMAP_WIDTH; x++)
			{
				if (tilemap[x + y * TILEMAP_WIDTH])
				{
					tile_shape.setPosition(50 * x, 50 * y);
					window.draw(tile_shape);
				}

				/*tile_map.setPosition(50 * x, 50 * y);
				window.draw(tile_map);*/
			}
		}

		window.draw(tile_player);

		window.display();


	}
}
