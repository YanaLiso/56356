#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
class TextObj {

private:
	sf::Font font;
	sf::Text text;
	int score;
public:
	 TextObj(std::string str) {
		font.loadFromFile("DS-DIGIB.ttf");
		text.setFont(font);
		text.setString(str);
		text.setCharacterSize(FONT_SIZE);
		text.setPosition(TEXT_POS);
	}
	 void update(std::string str)
	 {
		 text.setString(str);
	 }
	void draw(sf::RenderWindow& window) {
		window.draw(text);
	}
};