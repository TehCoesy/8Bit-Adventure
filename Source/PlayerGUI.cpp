#include "stdafx.h"
#include "PlayerGUI.h"

PlayerGUI::PlayerGUI(Player* player) {
	this->player = player;
	this->initFont();
	this->initHPBar();
}

PlayerGUI::~PlayerGUI() {

}

void PlayerGUI::initFont() {
	this->font.loadFromFile("Resources/Font/Dosis-Light.ttf");
}

void PlayerGUI::initHPBar() {
	this->hpBarBack.setSize(sf::Vector2f(200.0f, 20.0f));
	this->hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->hpBarBack.setPosition(20.0f, 20.0f);

	this->hpBarInside.setSize(sf::Vector2f(200.0f*(player->getHealth())/(player->getMaxHealth()), 20.0f));
	this->hpBarInside.setFillColor(sf::Color(250, 50, 50, 200));
	this->hpBarInside.setPosition(this->hpBarBack.getPosition());
}

void PlayerGUI::updateHPBar(float newHP) {
	this->hpBarInside.setSize(sf::Vector2f(200.0f * newHP / (player->getMaxHealth()),20.0f));
}

void PlayerGUI::update(const float& dt) {
	updateHPBar(player->getHealth());
}

void PlayerGUI::renderHPBar(sf::RenderTarget* target) {
	target->draw(this->hpBarBack);
	target->draw(this->hpBarInside);
}

void PlayerGUI::render(sf::RenderTarget* target,bool is_Pause,int elap_time) {
	if (is_Pause) {
		SettingArg::GetInstance()->setTime(time(NULL) - elap_time);
	}
	this->renderHPBar(target);
	int second = time(NULL) - SettingArg::GetInstance()->getTime();
	int minute = second / 60;
	second %= 60;
	sf::Text text;
	sf::Font font;
	font.loadFromFile("Resources/Font/kirbyss.ttf");
	text.setFont(font);
	text.setPosition(700, 20);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Yellow);
	std::string str = "";
	if (minute < 10) str = "0";
	str = str + std::to_string(minute) + ":";
	if (second < 10) str = str + "0";
	str = str + std::to_string(second);
	text.setString(str);
	target->draw(text);
}