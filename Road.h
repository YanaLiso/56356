#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
class Road {
private:
		sf::Texture texture;
		sf::Sprite sprite;
		
public:
	Road(sf::Vector2f pos, std::string roadFileName) {
		texture.loadFromFile(roadFileName);
		sprite.setTexture(texture);
		sprite.setPosition(pos);
		

	}
	void update() {
		sprite.move(0, 2.0);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(sprite.getPosition().x, -128.f);
		}
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};
