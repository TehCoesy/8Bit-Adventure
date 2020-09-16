#pragma once

#include "Player.h"
#include "SettingArg.h"
#include <string>

class sf::RectangleShape;

class PlayerGUI
{
private:
	Player* player;

	sf::Font font;

	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInside;

	void initFont();
	void initHPBar();

public:
	PlayerGUI(Player* player);
	virtual ~PlayerGUI();

	void updateHPBar(float newHP);

	void update(const float& dt);

	void renderHPBar(sf::RenderTarget* target);

	void render(sf::RenderTarget* target, bool is_Pause, int elap_time);
};