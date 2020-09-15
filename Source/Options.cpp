#include "stdafx.h"

#include "Options.h"

Options::Options() {
	font.loadFromFile(FONT_FONT2);
	font2.loadFromFile("Resources/Font/Symbol.ttf");
	title.setFont(font);
	title.setCharacterSize(40);
	title.setString("OPTIONS");
	title.setPosition((((float)WINDOW_W) - title.getGlobalBounds().width) / 2.0, 150.0f);
	darkRect.setSize(sf::Vector2f((float)WINDOW_H, (float)WINDOW_W));
	darkRect.setFillColor(sf::Color(0, 0, 0, 230.0f));
	coverRect.setSize(sf::Vector2f((float)WINDOW_W * 0.6f, (float)WINDOW_H * 0.6f));
	coverRect.setOutlineColor(sf::Color(255, 0, 255, 100));
	coverRect.setFillColor(sf::Color::Transparent);
	coverRect.setOutlineThickness(5.0f);
	coverRect.setPosition((float)(WINDOW_W - coverRect.getGlobalBounds().width) / 2.0, title.getPosition().y + (float)WINDOW_H / 10);
	text1.setFont(font);
	text1.setCharacterSize(30);
	text1.setString("DIFFICULTY");
	text1.setFillColor(sf::Color::Red);
	text1.setStyle(sf::Text::Bold);
	ltext1 = rtext1 = text1;
	ltext1.setFont(font2);
	rtext1.setFont(font2);
	ltext1.setString("<");
	rtext1.setString(">");
	text1.setPosition(coverRect.getPosition().x + (float)WINDOW_W / 40.0f, coverRect.getPosition().y + WINDOW_H / 10.0f);
	ltext1.setPosition(text1.getPosition().x+text1.getGlobalBounds().width+(float)WINDOW_W/40.0f,text1.getPosition().y-WINDOW_H/100.0f);
	rtext1.setPosition(coverRect.getPosition().x + coverRect.getGlobalBounds().width - (float)WINDOW_W / 40.0f - rtext1.getGlobalBounds().width, ltext1.getPosition().y);
	m_text1 = text1;
	text2 = text1;
	text2.setString("MODE");
	ltext2 = ltext1;
	rtext2 = rtext1;
	text2.setPosition(text2.getPosition().x, text2.getPosition().y + WINDOW_H / 10.0);
	ltext2.setPosition(ltext2.getPosition().x, ltext2.getPosition().y + WINDOW_H / 10.0);
	rtext2.setPosition(rtext2.getPosition().x, rtext2.getPosition().y + WINDOW_H / 10.0);
	m_text2 = m_text1;
	df = SettingArg::GetInstance()->getDif();
	mode = SettingArg::GetInstance()->getMod();
	lflag = rflag = lflag2 = rflag2 = 0;
	exit = 0;
}

Options::~Options() {
}

void Options::Update(float dt) {

}

void Options::Render(sf::RenderWindow* window) {
	//window->draw(*menuSprite);
	window->draw(darkRect);
	
	window->draw(coverRect);
	window->draw(title);
	window->draw(text1);
	window->draw(ltext1);
	window->draw(rtext1);
	if (df == 0) {
		m_text1.setString("EASY");
	}
	else if (df == 1) {
		m_text1.setString("NORMAL");
	}
	else if (df == 2) {
		m_text1.setString("HARD");
	}
	m_text1.setPosition((ltext1.getPosition().x + ltext1.getGlobalBounds().width + rtext1.getPosition().x - m_text1.getGlobalBounds().width) / 2.0f, text1.getPosition().y);
	window->draw(m_text1);
	window->draw(text2);
	window->draw(ltext2);
	window->draw(rtext2);
	if (mode == 0) {
		m_text2.setString("NORMAL");
	}
	else if (mode == 1) {
		m_text2.setString("INFINITY");
	}
	m_text2.setPosition((ltext2.getPosition().x + ltext2.getGlobalBounds().width + rtext2.getPosition().x - m_text2.getGlobalBounds().width) / 2.0f, text2.getPosition().y);
	window->draw(m_text2);
}

void Options::Init() {

	/*if (!menuTexture) menuTexture = new sf::Texture;
	menuTexture->loadFromFile(MAINMENU_BACKGROUND);
	if (!menuSprite) menuSprite = new sf::Sprite;
	menuSprite->setTexture(*menuTexture);
	sf::Vector2f targetSize((float)WINDOW_H, (float)WINDOW_W);
	menuSprite->setScale(targetSize.x / menuSprite->getLocalBounds().width,
		targetSize.y / menuSprite->getLocalBounds().height);*/
}

void Options::HandleInput(sf::RenderWindow* window) {
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			else if (event.key.code == sf::Keyboard::Return) {
				StateMachine->RemoveState();
			}
			break;

		case sf::Event::MouseMoved:
			if (isTextClicked_v2(window, rtext1))
				rtext1.setFillColor(sf::Color::Yellow);
			else
				rtext1.setFillColor(sf::Color::Red);
			if (isTextClicked_v2(window, ltext1))
				ltext1.setFillColor(sf::Color::Yellow);
			else
				ltext1.setFillColor(sf::Color::Red);
			if (isTextClicked_v2(window, rtext2)) {
				rtext2.setFillColor(sf::Color::Yellow);
			}
			else {
				rtext2.setFillColor(sf::Color::Red);
			}
			if (isTextClicked_v2(window, ltext2)) {
				ltext2.setFillColor(sf::Color::Yellow);
			}
			else {
				ltext2.setFillColor(sf::Color::Red);
			}
			break;
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (lflag == 0 && rflag == 0) {
			if (isTextClicked_v2(window, ltext1)) {
			//	printf("Clicked left b %d %d\n", lflag, rflag);
				(lflag)++;
			//	printf("Clicked left a %d %d\n", lflag, rflag);
			}
			else if ((isTextClicked_v2(window, rtext1))) {
			//	printf("Clicked right b %d %d\n", lflag, rflag);
				(rflag)++;
			//	printf("Clicked right a %d %d\n", lflag, rflag);
			}
			else if (isTextClicked_v2(window, ltext2)) {
				lflag2++;
			}
			else if (isTextClicked_v2(window, rtext2)) {
				rflag2++;
			}

		}
		sf::IntRect rect(coverRect.getPosition().x, coverRect.getPosition().y, coverRect.getGlobalBounds().width, coverRect.getGlobalBounds().height);
		if (!rect.contains(sf::Mouse::getPosition(*window)) && exit==1) {
			exit = 2;
		}
	}
	else {
		if (lflag) {
			SM->PlayEffectByName("BTN_CLICK");
			lflag = 0;
			df--;
			if (df < 0) df += 3;
			SettingArg::GetInstance()->setDif(df);
		}
		if (rflag) {
			SM->PlayEffectByName("BTN_CLICK");
			rflag = 0;
			df++;
			if (df >= 3) df -= 3;
			SettingArg::GetInstance()->setDif(df);
		}
		if (lflag2) {
			SM->PlayEffectByName("BTN_CLICK");
			lflag2 = 0;
			mode--;
			if (mode < 0) mode += 2;
			SettingArg::GetInstance()->setMod(mode);
		}
		if (rflag2) {
			SM->PlayEffectByName("BTN_CLICK");
			rflag2 = 0;
			mode++;
			if (mode >= 2) mode -= 2;
			SettingArg::GetInstance()->setMod(mode);
		}
		if (exit == 0) {
			exit = 1;
		}
		if (exit==2) {
			SM->PlayEffectByName("BTN_CLICK");
			exit = 0;
			StateMachine->RemoveState();
		}

	}
}

bool Options::isTextClicked(sf::RenderWindow* window, sf::Text text) {
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);
	if (rect.contains(sf::Mouse::getPosition(*window)))
		return true;


	//Otherwise, don't do anything
	return false;
}

bool Options::isTextClicked_v2(sf::RenderWindow* window, sf::Text text) {
	sf::IntRect rect(text.getPosition().x, text.getPosition().y+WINDOW_H/80.0, text.getGlobalBounds().width, text.getGlobalBounds().height+WINDOW_H/50.0);
	if (rect.contains(sf::Mouse::getPosition(*window)))
		return true;


	return false;
}