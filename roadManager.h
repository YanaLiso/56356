#pragma once
#include "settings.h"
#include "Road.h"
#include <vector>

class RoadManager {
private:
	std::vector<Road*> roadSprites;
public:
	RoadManager();
	void update();
	void draw(sf::RenderWindow& window);
};
RoadManager::RoadManager() {
	roadSprites.reserve(30);
	float x = 0;
	float y = -128;
	for (int i = 0; i < 6; i++) {
		Road* road = new Road(sf::Vector2f{ x,y }, LEFT_ROAD_FILE_NAME);
		y += 128;
		roadSprites.push_back(road);
	}
	for (int i = 0; i < 3; i++)
	{
		x += 128.f;
		y = -128.f;
		for (int j = 0; j < 6; j++) {
			Road* road = new Road(sf::Vector2f{ x,y }, CENTER_ROAD_FILE_NAME);
			y += 128;
			roadSprites.push_back(road);
		}
	}
	x += 128.f;
	y = -128.f;
	for (int i = 0; i < 6; i++) {
		Road* road = new Road(sf::Vector2f{ x,y }, RIGHT_ROAD_FILE_NAME);
		y += 128;
		roadSprites.push_back(road);
	}
}
void RoadManager::update() {
	for (auto& road : roadSprites) {
		road->update();
	}
}
void RoadManager::draw(sf::RenderWindow& window) {
	for (const auto& road : roadSprites) {
		road->draw(window);
	}
}

