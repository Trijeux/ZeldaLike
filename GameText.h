#pragma once

#include <SFML/Graphics.hpp>

class GameText
{
	sf::Text text_;
	sf::Font font_;
	bool toDisplay_ = true;

public:
	GameText(std::string str, int x, int y)
	{
		
		font_.loadFromFile("datas\\fonts\\Violin.otf");

		text_.setFont(font_);
		text_.setString(str);
		text_.setPosition(x, y);
		text_.setFillColor(sf::Color::White);
	}
	
	void Draw(sf::RenderWindow& window_)
	{
		if (toDisplay_)
			window_.draw(text_);
	}
	
	void On()
	{
		toDisplay_ = true;
	}

	void Off()
	{
		toDisplay_ = false;
	}

	void getSize(float x, float y)
	{
		text_.setScale(x, y);
	}
};

