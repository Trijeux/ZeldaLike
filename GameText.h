#pragma once

#include <SFML/Graphics.hpp>

class GameText
{
	sf::Text text_;
	sf::Font font_;
	bool to_display_ = true;

public:
	GameText(std::string str, int x, int y)
	{
		
		font_.loadFromFile("datas\\fonts\\Violin.otf");

		text_.setFont(font_);
		text_.setString(str);
		text_.setPosition(x, y);
		text_.setFillColor(sf::Color::White);
	}
	
	void Draw(sf::RenderWindow& window)
	{
		if (to_display_)
			window.draw(text_);
	}
	
	void On()
	{
		to_display_ = true;
	}

	void Off()
	{
		to_display_ = false;
	}

	void GetSize(float x, float y)
	{
		text_.setScale(x, y);
	}
};

