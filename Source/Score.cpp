#include "stdafx.h"
#include "Score.h"

Score::Score(Player* player) {
	score = 1015;
	this->player = player;
	init();
}

Score::~Score() {

}

void Score::init() {
	font.loadFromFile("Resources/Font/kirbyss.ttf");
	t.setFont(font);
	t.setCharacterSize(20);
	t.setPosition(400, 20);
	t.setFillColor(sf::Color::Yellow);
	t.setStyle(sf::Text::Bold);
}

sf::String Score::conv(int score) {
	int n = 0, t = 1;
	while (t < score) {
		n++;
		t *= 10;
	}
	sf::String res;
	while (score) {
		res = (char)(score % 10 + '0') + res;
		score /= 10;
	}
	for (int i = 0; i < digit - n; i++) {
		res = "0" + res;
	}
	return res;
}

void Score::Update() {

}

void Score::Render(sf::RenderTarget* target) {
	t.setString("SCORE   "+conv(score));
	target->draw(t);
}