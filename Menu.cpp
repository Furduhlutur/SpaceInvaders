#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
	// Images
	background.loadFromFile("Images/background.jpg");
	ship1.loadFromFile("Images/ship1.png");
	ship2.loadFromFile("Images/ship2.png");
	ship3.loadFromFile("Images/ship3.png");
	mothership.loadFromFile("Images/mothership.png");

	backgroundSprite.setTexture(background);
	ship1Sprite.setTexture(ship1);
	ship2Sprite.setTexture(ship2);
	ship3Sprite.setTexture(ship3);
	mothershipSprite.setTexture(mothership);

	ship1Sprite.setColor(sf::Color(0, 254, 0));
	ship2Sprite.setColor(sf::Color(0, 175, 255));
	ship3Sprite.setColor(sf::Color(160, 40, 253));
	mothershipSprite.setColor(sf::Color(220, 0, 0));

	ship1Sprite.setScale(1.5, 1.5);
	ship2Sprite.setScale(1.5, 1.5);
	ship3Sprite.setScale(1.5, 1.5);
	mothershipSprite.setScale(1.5, 1.5);

	ship1Sprite.setPosition(480, 245);
	ship2Sprite.setPosition(480, 325);
	ship3Sprite.setPosition(490, 425);
	mothershipSprite.setPosition(465, 520);

	// Font and strings
	font.loadFromFile("Pixeled.ttf");

	name.setFont(font);
	instruction.setFont(font);
	points1.setFont(font);
	points2.setFont(font);
	points3.setFont(font);
	points4.setFont(font);

	name.setCharacterSize(80);
	instruction.setCharacterSize(40);
	points1.setCharacterSize(40);
	points2.setCharacterSize(40);
	points3.setCharacterSize(40);
	points4.setCharacterSize(40);

	points1.setFillColor(sf::Color(0, 254, 0));
	points2.setFillColor(sf::Color(0, 175, 255));
	points3.setFillColor(sf::Color(160, 40, 253));
	points4.setFillColor(sf::Color(220, 0, 0));

	name.setString("SPACE INVADERS");
	instruction.setString("PRESS ANY KEY TO CONTINUE");
	points1.setString("= 10 PTS");
	points2.setString("= 20 PTS");
	points3.setString("= 30 PTS");
	points4.setString("= ?????");

	sf::FloatRect nameRect = name.getLocalBounds();
	sf::FloatRect instructionRect = instruction.getLocalBounds();
	sf::FloatRect points1Rect = points1.getLocalBounds();
	sf::FloatRect points2Rect = points2.getLocalBounds();
	sf::FloatRect points3Rect = points3.getLocalBounds();
	sf::FloatRect points4Rect = points4.getLocalBounds();

	name.setOrigin(nameRect.left + nameRect.width / 2.0f, nameRect.top + nameRect.height / 2.0f);
	instruction.setOrigin(instructionRect.left + instructionRect.width / 2.0f, instructionRect.top + instructionRect.height / 2.0f);
	points1.setOrigin(points1Rect.left + points1Rect.width / 2.0f, points1Rect.top + points1Rect.height / 2.0f);
	points2.setOrigin(points2Rect.left + points2Rect.width / 2.0f, points2Rect.top + points2Rect.height / 2.0f);
	points3.setOrigin(points3Rect.left + points3Rect.width / 2.0f, points3Rect.top + points3Rect.height / 2.0f);
	points4.setOrigin(points4Rect.left + points4Rect.width / 2.0f, points4Rect.top + points4Rect.height / 2.0f);
	
	name.setPosition(windowWidth / 2.0f, 100);
	instruction.setPosition(windowWidth / 2.0f, 190);
	points1.setPosition(windowWidth / 2.0f + 70, 270);
	points2.setPosition(windowWidth / 2.0f + 80, 360);
	points3.setPosition(windowWidth / 2.0f + 80, 450);
	points4.setPosition(windowWidth / 2.0f + 88, 540);
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(ship1Sprite);
	window.draw(ship2Sprite);
	window.draw(ship3Sprite);
	window.draw(mothershipSprite);
	window.draw(name);
	window.draw(instruction);
	window.draw(points1);
	window.draw(points2);
	window.draw(points3);
	window.draw(points4);
}
