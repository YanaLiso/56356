#pragma once
#include <string>
#include "SFML/Graphics.hpp"
const float WINDOW_WIDTH{ 640.f };
const float WINDOW_HEIGHT{ 640.f };
const std::string WINDOW_TITLE{ "SFML Lesson3" };
const unsigned int FPS{ 60 };

const std::string PLAYER_FILE_NAME = "car.png";
float PLAYER_SPEEDX = 5.f;
const std::string LEFT_ROAD_FILE_NAME = "road_dirt20.png";
const std::string CENTER_ROAD_FILE_NAME = "road_dirt21.png";
const std::string RIGHT_ROAD_FILE_NAME = "road_dirt22.png";
const float PLAYER_WIDTH = 70.f;
const float PLAYER_HEIGHT = 126.f;
sf::Vector2f PLAYER_START_POS{ (WINDOW_WIDTH - PLAYER_WIDTH) / 2.f, WINDOW_HEIGHT - PLAYER_HEIGHT };
//float ROAD_SPEEDX = 5.f;
const sf::Vector2f ROAD_POS{ 0.f, 0.f };

const float BORDER{ 20.f };
const std::string Bonus_FILE_NAME = "image (5).png";

const unsigned int FONT_SIZE = 64;
const sf::Vector2f TEXT_POS{ 320.f, 10.f };
const std::string Bonus_TREE_FILE_NAME = "tree_small.png";
const int BONUS_QTY = 1;
const int ENEMY_QTY = 1;




