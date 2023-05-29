#pragma once
#include "settings.h"
#include "Player.h"
#include "roadManager.h"
#include <vector>
#include "Bonus.h"
#include "text.h"
#include "Enemy.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	RoadManager road;
	Bonus bonus;
	//Enemy enemy;
	sf::FloatRect bounds;
	std::vector<Bonus*> BonusSprites;
	//std::vector<Enemy*> EnemySprites;
	
	void checkEvents()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

public:
	enum GameState { PLAY, GAME_OVER, YOU_WIN };
	Game();
	void draw(sf::RenderWindow& window);
	void checkColisions();
	void play()
	{
		while (window.isOpen() )
		{
			checkEvents();
			update();
		}
	}
	void update()
	{
		road.update();
		player.update();
		for (auto Bonuss : BonusSprites)
		{
			Bonuss->update();
		}
		/*for (auto Enemy : EnemySprites)
		{
			Enemy->update();
		}*/

	}

};


Game::Game() {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	BonusSprites.reserve(BONUS_QTY);
	//EnemySprites.reserve(ENEMY_QTY);
	for (int i = 0; i < BONUS_QTY; i++)
	{
		BonusSprites.push_back(new Bonus());
	}
	/*for (int i = 0; i < ENEMY_QTY; i++)
	{
		EnemySprites.push_back(new Enemy());
	}*/
}



void Game::draw(sf::RenderWindow& window)
{
	window.clear();
	road.draw(window);
	player.draw(window);
	for (auto Bonus : BonusSprites)
	{
		window.draw(Bonus->getSprite());
	}
	/*for (auto Enemy : EnemySprites)
	{
		window.draw(Enemy->getSprite());
	}*/
	
	window.display();
}

void Game::checkColisions() {
	auto playerBounds = player.getHitBox();
	for (auto& bonus : BonusSprites) {
		auto bonusBounds = bonus->getHitBox();
		if (playerBounds.intersects(bonusBounds)) {
			bonus->spawn();
			player.increaseHp(bonus->getHeal());
		}
	}
	/*for (auto& enemy : EnemySprites) {
		auto enemyBounds = enemy->getHitBox();
		if (playerBounds.intersects(enemyBounds)) {
			enemy->spawn();
			player.decreaseHp(enemy->getDamage());
		}
	}*/
}


	
		
	
	