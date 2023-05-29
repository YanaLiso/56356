/*#pragma once
#include "settings.h"
class Enemy {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string textureFileNames[];
	static int arrDamage[];
	float speedy;
	int damage;
public:
	Enemy()
	{
		int index = rand() % 2;
		damage = arrDamage[index];
		texture.loadFromFile(textureFileNames[index]);
		sprite.setTexture(texture);
		spawn();
	}
	void spawn()
	{
		float EnemyWidth = sprite.getLocalBounds().width;
		float x = (float)(rand() % (int)(WINDOW_WIDTH - EnemyWidth - BORDER));
		float y = (float)(rand() % (int)(WINDOW_HEIGHT / 2) -
			WINDOW_HEIGHT / 2);
		sprite.setPosition(x, y);

	}
	void update()
	{
		sprite.move(0, 2.0);
		sf::Vector2f pos = sprite.getPosition();
		float EnemyWidth = sprite.getLocalBounds().width;
		if (pos.x < -EnemyWidth || pos.y > WINDOW_HEIGHT ||
			pos.x > WINDOW_WIDTH)
		{
			spawn();
		}
	}
	sf::Sprite& getSprite() { return sprite; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	int getDamage() { return damage; }

	sf::Vector2f getPosition() { return sprite.getPosition(); }

};

std::string Enemy::textureFileNames[] =
{
	"tree_small.png","image.png"
};
int Enemy::arrDamage[] = { 10,10 };*/