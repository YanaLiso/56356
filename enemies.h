#pragma once
#include "settings.h"
class Bonus {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string textureFileNames[];
	float speedy;
public:
	Bonus()
	{
		int index = rand() % 2;

		texture.loadFromFile(textureFileNames[index]);
		sprite.setTexture(texture);
		spawn();
	}
	void spawn()
	{
		float BonusWidth = sprite.getLocalBounds().width;
		float x = (float)(rand() % (int)(WINDOW_WIDTH - BonusWidth - BORDER));
		float y = (float)(rand() % (int)(WINDOW_HEIGHT / 2) -
			WINDOW_HEIGHT / 2);
		sprite.setPosition(x, y);
		
	}
	void update()
	{
		sprite.move(0, 2.0);
		sf::Vector2f pos = sprite.getPosition();
		float BonusWidth = sprite.getLocalBounds().width;
		if (pos.x < -BonusWidth || pos.y > WINDOW_HEIGHT ||
			pos.x > WINDOW_WIDTH)
		{
			spawn();
		}
	}
		sf::Sprite& getSprite() { return sprite; }

		sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

		sf::Vector2f getPosition() { return sprite.getPosition(); }

		
};
std::string Bonus::textureFileNames[] =
{
"tires_red_alt.png"
};
