#include "stdafx.h"
#include "Game.h"

using namespace sf;

/*
TODO LIST:
1: Figure out how to make enemies shoot
2: Make it so that the mothership appears at random moments
*/
Game::Game()
{
	background.loadFromFile("Images/background.jpg");
	enemy1.loadFromFile("Images/ship1.png");
	enemy2.loadFromFile("Images/ship2.png");
	enemy3.loadFromFile("Images/ship3.png");
	enemy1Move.loadFromFile("Images/ship1Move.png");
	enemy2Move.loadFromFile("Images/ship2Move.png");
	enemy3Move.loadFromFile("Images/ship3Move.png");
	ship.loadFromFile("Images/player.png");
	death.loadFromFile("Images/death.png");
	backgroundSprite.setTexture(background);

	utilities.initializeShield(shields);
	utilities.initializeEnemies(enemies, enemy1, enemy2, enemy3, enemy1Move, enemy2Move, enemy3Move);
	utilities.initializeLives(ships, ship);

	font.loadFromFile("Pixeled.ttf");

	score.setFont(font);
	lives.setFont(font);
	gameOverText.setFont(font);
	nextRoundText.setFont(font);

	score.setCharacterSize(15);
	lives.setCharacterSize(15);
	gameOverText.setCharacterSize(80);
	nextRoundText.setCharacterSize(80);

	gameOverText.setString("GAME OVER!");
	FloatRect overRect = gameOverText.getLocalBounds();
	gameOverText.setOrigin(overRect.left + overRect.width / 2.0f, overRect.top + overRect.height / 2.0f);
	gameOverText.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);

	nextRoundText.setString("NEXT ROUND!");
	FloatRect nextRoundRect = nextRoundText.getLocalBounds();
	nextRoundText.setOrigin(nextRoundRect.left + nextRoundRect.width / 2.0f, nextRoundRect.top + nextRoundRect.height / 2.0f);
	nextRoundText.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);

	score.setPosition(10, 10);
	lives.setPosition(1100, 10);
	lives.setString("LIVES: ");
}

void Game::restart()
{
	play = false;
	points = 0;

	shields.clear();
	enemies.clear();
	ships.clear();

	utilities.initializeShield(shields);
	utilities.initializeEnemies(enemies, enemy1, enemy2, enemy3, enemy1Move, enemy2Move, enemy3Move);
	utilities.initializeLives(ships, ship);
}

void Game::gameOver(RenderWindow& window)
{
	restart();
	window.draw(backgroundSprite);

	if (times == 8)
	{
		play = false;
		isGameOver = false;
	}

	else if (time.asMilliseconds() > 700)
	{
		times++;
		clock.restart();
		drawGameOver = !drawGameOver;
	}

	else if (drawGameOver)
	{
		window.draw(gameOverText);
	}
}

void Game::nextRound(RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(score);
	window.draw(lives);

	for (auto& s : ships)
	{
		window.draw(s);
	}

	if (times == 8)
	{
		utilities.initializeShield(shields);
		utilities.initializeEnemies(enemies, enemy1, enemy2, enemy3, enemy1Move, enemy2Move, enemy3Move);
		isNextRound = false;
		play = true;
	}

	else if (time.asMilliseconds() > 700)
	{
		times++;
		clock.restart();
		drawNextRound = !drawNextRound;
	}

	else if (drawNextRound)
	{
		window.draw(nextRoundText);
	}
}

void Game::playing(RenderWindow& window, Player& player)
{
	window.draw(backgroundSprite);
	window.draw(player.getSprite());
	window.draw(score);
	window.draw(lives);
	drawDeath(window);

	if (bullets.size())
	{
		enemyCollision(bullets, enemies, shields, window, points);
	}

	for (auto& e : enemies)
	{
		e.update(time, clock, window, furthestRight, furthestLeft);
	}

	for (auto& c : shields)
	{
		window.draw(c);
	}

	for (auto& x : ships)
	{
		window.draw(x);
	}
}

void Game::updateGame()
{
	time = clock.getElapsedTime();
	deathTime = deathClock.getElapsedTime();

	std::stringstream s;
	s << points;
	score.setString("SCORE: " + s.str());

	furthestRight = utilities.furthestRight(enemies);
	furthestLeft = utilities.furthestLeft(enemies);
}

void Game::enemyCollision(std::vector<Bullet>& bullets, std::vector<Enemy>& enemies, std::vector<RectangleShape>& shields, RenderWindow& window, int& points)
{
	bool drawBullet = true;
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (!bullets[i].onScreen())
		{
			bullets.erase(bullets.begin() + i);
		}

		else
		{
			bullets[i].update();
			for (size_t e = 0; e < enemies.size(); ++e)
			{
				if (bullets[i].getPosition().intersects(enemies[e].getSprite().getGlobalBounds()))
				{
					deathClock.restart();
					utilities.addDeath(deaths, enemies[e].getSprite().getPosition(), death, enemies[e].getSprite().getColor());

					points += utilities.addPoints(e);
					bullets.erase(bullets.begin() + i);
					enemies.erase(enemies.begin() + e);
					drawBullet = false;
					break;
				}
			}

			if (drawBullet)
			{
				for (size_t s = 0; s < shields.size(); ++s)
				{
					if (bullets[i].getPosition().intersects(shields[s].getGlobalBounds()))
					{
						bullets.erase(bullets.begin() + i);
						shields.erase(shields.begin() + s);
						drawBullet = false;
						break;
					}
				}
			}

			if (drawBullet)
			{
				window.draw(bullets[i].getShape());
			}
		}
	}
}

void Game::drawDeath(RenderWindow& window)
{
	if (deathTime.asMilliseconds() > 200)
	{
		deathClock.restart();
		deaths.clear();
	}

	else
	{
		for (auto& d : deaths)
		{
			window.draw(d);
		}
	}
}

void Game::run()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");
	window.setFramerateLimit(120);

	Player player(DEFAULT_POS_X, DEFAULT_POS_Y);

	// Main game loop
	while (window.isOpen())
	{
		// Loop for handling closing of the window
		// and 'R' for restart of the game
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyPressed:
				play = true;
				break;
			case Event::Closed:
				window.close();
				break;
			}
		}


		// Logic for game
		if (Keyboard::isKeyPressed(Keyboard::R) && play)
		{
			restart();
			isGameOver = false;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.moveLeft();
		}

		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.moveRight();
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			Vector2f pos = player.getPosition();
			Bullet bullet(pos.x + 16, pos.y - 15);
			if (!bullets.empty())
			{
				if (bullets[bullets.size() - 1].getPosition().top < 250)
				{
					bullets.push_back(bullet);
				}
			}

			else
			{
				bullets.push_back(bullet);
			}
		}

		if (utilities.furthestDown(enemies) > 572)
		{
			isGameOver = true;
			play = false;
		}

		if (enemies.empty())
		{
			isNextRound = true;
			play = false;
		}

		// Final updates before drawing
		updateGame();

		// Drawing of the window
		window.clear();

		if (play && !isGameOver)
		{
			playing(window, player);
		}

		else if (isNextRound)
		{
			nextRound(window);
		}

		else if (isGameOver)
		{
			gameOver(window);
		}

		else
		{
			menu.draw(window);
		}
		window.display();
	}
}
