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

	this->hpBarInside.setSize(sf::Vector2f(120.0f, 20.0f));
	this->hpBarInside.setFillColor(sf::Color(250, 50, 50, 200));
	this->hpBarInside.setPosition(this->hpBarBack.getPosition());
}

void PlayerGUI::updateHPBar() {

}

void PlayerGUI::update(const float& dt) {

}

void PlayerGUI::renderHPBar(sf::RenderTarget* target) {
	target->draw(this->hpBarBack);
	target->draw(this->hpBarInside);
}

void PlayerGUI::render(sf::RenderTarget* target) {
	this->renderHPBar(target);
}