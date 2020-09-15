#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "Singleton.h"
#include "MyObject.h"
#include "State.h"
#include "StateManager.h"
#include "GameScene.h"
#include "Options.h"

class MainMenu : public State {
private:
	//sf::Sprite menuSprite;
	sf::Sprite* menuSprite;
	sf::Texture* menuTexture;
	sf::Font font, titleFont;
	const int NUM_BUTTONS = 3;
	sf::Text title;
	std::vector<sf::Text> buttons;
	int mode, dif;
	bool isTextClicked(sf::RenderWindow* window, sf::Text text);
public:
	MainMenu();
	~MainMenu();
	void Update(const float dt);
	void Render(sf::RenderWindow *window);
	void HandleInput(sf::RenderWindow* window);
	void Init();
};