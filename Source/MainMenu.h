#pragma once

// Precompiled Headers
#include "stdafx.h"

// Local
#include "Singleton.h"
#include "MyObject.h"

class MainMenu : public Singleton<MainMenu> {
private:
	//sf::Sprite menuSprite;
	sf::Texture* menuTexture;
	sf::Font font, titleFont;
	const int NUM_BUTTONS = 3;
	sf::Text title;
	std::vector<sf::Text> buttons;
public:
	MainMenu();
	~MainMenu();
	void Update(const float dt);
	void Render(sf::RenderWindow *window);
	void HandleInput();
	void LoadFromFile(std::string strFilePath);
	sf::Sprite* menuSprite;
};