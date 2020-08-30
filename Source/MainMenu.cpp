// Precompiled Headers
#include "stdafx.h"

#include "MainMenu.h"

MainMenu::MainMenu() {
	menuSprite = nullptr;
	menuTexture = nullptr;
	sf::Text text;
	font.loadFromFile("Resources/Font/font2.ttf");
	text.setFont(font);
	text.setPosition(100, 300);
	text.setCharacterSize(30);                         
	text.setFillColor(sf::Color::White);   
	text.setStyle(sf::Text::Bold); 

	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 100);
	}

	buttons[0].setString("Play Game");
	buttons[1].setString("Options");
	buttons[2].setString("Quit");
	/*titleFont.loadFromFile("Resources/Font/font2.ttf");
	title.setFont(titleFont);
	title.setCharacterSize(40);
	title.setPosition(220, 100);
	title.setString("CHRONICLE: RISE");
	title.setFillColor(sf::Color::White);
	title.setStyle(sf::Text::Bold);*/
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
}

bool MainMenu::isTextClicked(sf::RenderWindow* window,sf::Text text) {
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	if (rect.contains(sf::Mouse::getPosition(*window)))
		return true;


	//Otherwise, don't do anything
	return false;
}

int MainMenu::HandleInput(sf::RenderWindow* window) {
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
			window->close();
			break;

			/* Change Between game states */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			else if (event.key.code == sf::Keyboard::Return) {
				return 1;
				//loadgame();
			}
			break;

		case sf::Event::MouseMoved:
			if (isTextClicked(window,buttons[0]))
				buttons[0].setFillColor(sf::Color::Yellow);
			else
				buttons[0].setFillColor(sf::Color::White);
			if (isTextClicked(window,buttons[1]))
				buttons[1].setFillColor(sf::Color::Yellow);
			else
				buttons[1].setFillColor(sf::Color::White);
			if (isTextClicked(window,buttons[2]))
				buttons[2].setFillColor(sf::Color::Yellow);
			else
				buttons[2].setFillColor(sf::Color::White);
			break;
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (isTextClicked(window, buttons[0])) {
			return 1;
		//	loadgame();
		}
		else if (isTextClicked(window,buttons[2]))
			window->close();


	}
	return 0;
}