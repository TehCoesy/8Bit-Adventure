#pragma once

#include "Player.h"

class sf::Font;
class Score {
private:
	Player* player;
	int score;
	sf::Font font;
	sf::Text t;
	void init();
	const int digit = 8;
	sf::String conv(int score);
public:
	Score(Player* player);
	virtual ~Score();
	void Update();
	void Render(sf::RenderTarget* target);
};