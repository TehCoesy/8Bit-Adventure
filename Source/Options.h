#pragma once

#include "stdafx.h"
#include "State.h"
#include "StateManager.h"
#include "SettingArg.h"
#include "SoundManager.h"

class Options : public State {
private:
	sf::Text title, text1, ltext1, rtext1, itext1,m_text1,text2,ltext2,rtext2,m_text2;
	sf::Font font,font2;
	sf::RectangleShape darkRect,coverRect;
	int df; //df = 0: Easy, df = 1: Normal, df = 2: Hard;
	int mode; //mode = 0: Normal, mode = 1: Infinity;
	int lflag, rflag, lflag2,rflag2,exit;
	bool isTextClicked(sf::RenderWindow* window, sf::Text text);
	bool isTextClicked_v2(sf::RenderWindow* window, sf::Text text);
public:
	Options();
	~Options();
	void Update(float dt);
	void Render(sf::RenderWindow* window);
	void Init();
	void HandleInput(sf::RenderWindow* window);
};