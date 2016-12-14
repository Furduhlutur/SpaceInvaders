#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Menu
{
private:
	sf::Text name, instruction, points1, points2, points3, points4;
	sf::Font font;
	sf::Texture background, ship1, ship2, ship3, mothership;
	sf::Sprite backgroundSprite, ship1Sprite, ship2Sprite, ship3Sprite, mothershipSprite;

	float windowWidth = 1280;
	float windowHeight = 720;

public:
	Menu();

	void draw(sf::RenderWindow& window);
};

