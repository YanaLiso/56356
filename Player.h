#pragma once
#include "settings.h"
#include "text.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speedx = 0.f;
	int hp = 50;
	TextObj text;
	sf::FloatRect bounds;
	void playerControl();
public:

	void draw(sf::RenderWindow& window);
	Player();

	void update() 
	{ 
		playerControl();
	    text.update("HP:" + std::to_string(hp));
	}

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	int getHp() { return hp; }

	bool isAlive() { return hp > 0; }

	void decreaseHp(int damage) { hp -= damage; }

	void increaseHp(int heal) { hp += heal; }
};

Player::Player() : text(std::to_string(hp))
{
	texture.loadFromFile(PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setPosition(PLAYER_START_POS);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	text.draw(window);
}
void Player::playerControl() {
	bounds = sprite.getGlobalBounds();
	speedx = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		speedx = -PLAYER_SPEEDX;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		speedx = PLAYER_SPEEDX;
	}
	sprite.move(speedx, 0.f);
	sf::Vector2f playerPos = sprite.getPosition();
	if (playerPos.x < BORDER) {
		sprite.setPosition(BORDER, playerPos.y);
	}
	else if (playerPos.x > WINDOW_WIDTH - bounds.width- BORDER) {
		sprite.setPosition(WINDOW_WIDTH - bounds.width - BORDER, playerPos.y);
	}
}

	