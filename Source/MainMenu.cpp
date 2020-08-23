// Precompiled Headers
#include "stdafx.h"

#include "MainMenu.h"

MainMenu::MainMenu() {
	menuSprite = nullptr;
	menuTexture = nullptr;
	sf::Text text;
	font.loadFromFile("Resources/Font/font1.ttf");
	text.setFont(font);
	text.setPosition(100, 300);
	text.setCharacterSize(24);                         
	text.setOutlineColor(sf::Color::White);   
	text.setStyle(sf::Text::Bold); 

	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 100);
	}

	buttons[0].setString("Play Game");
	buttons[1].setString("Options");
	buttons[2].setString("Quit");
	titleFont.loadFromFile("Resources/Font/font2.ttf");
	title.setFont(titleFont);
	title.setCharacterSize(40);
	title.setPosition(220, 100);
	title.setString("CHRONICLE: RISE");
	title.setOutlineColor(sf::Color::White);
	title.setStyle(sf::Text::Bold);
}

MainMenu::~MainMenu() {
	if (menuSprite) {
		delete menuSprite;
		menuSprite = nullptr;
	}
	if (menuTexture) {
		delete menuTexture;
		menuTexture = nullptr;
	}
}

void MainMenu::LoadFromFile(std::string strFilePath) {
	if (!menuTexture) menuTexture = new sf::Texture;
	//menuTexture.loadFromFile("Resource/Textures/bg/main.jpg");
	menuTexture->loadFromFile(strFilePath);
	if (!menuSprite) menuSprite = new sf::Sprite;
	menuSprite->setTexture(*menuTexture);
	sf::Vector2f targetSize(800.0f, 800.0f);
	menuSprite->setScale(targetSize.x / menuSprite->getLocalBounds().width,
		targetSize.y / menuSprite->getLocalBounds().height);
}

void MainMenu::Update(const float dt) {

}

void MainMenu::Render(sf::RenderWindow *window) {
	window->draw(*(MainMenu::GetInstance()->menuSprite));
	for (auto x : buttons) window->draw(x);
	window->draw(title);
}

void MainMenu::HandleInput() {

}