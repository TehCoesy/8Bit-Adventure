#include "GameOver.h"


void GameOver::Init() {
	m_aButtons.push_back(m_text);
	m_aButtons.push_back(m_text);
	m_aButtons.push_back(m_text);
	m_aButtons[0].setString("Play Again");
	m_aButtons[1].setString("Title Screen");
	m_aButtons[2].setString("Quit Game");
	float margin = 30.0f;
	float o_row = 750.0f;
	float x = (float)WINDOW_W - 2 * margin;
	for (int i = 0; i < 3; i++) {
		x -= m_aButtons[i].getGlobalBounds().width;
	}
	x /= 2.0f;
	float pos = margin;
	for (int i = 0; i < 3; i++) {
		m_aButtons[i].setPosition(pos, o_row);
		pos += m_aButtons[i].getGlobalBounds().width + x;
	}
	
	m_rec.setFillColor(sf::Color(0, 0, 0, 150));
	m_rec.setSize(sf::Vector2f((float)WINDOW_W, (float)WINDOW_H));
	
	
	m_font.loadFromFile(FONT_FONT2);
	m_text.setFont(m_font);
	m_text.setString("GAME OVER");
	m_text.setCharacterSize(80);
	m_text.setStyle(sf::Text::Bold);
	//t.setPosition(sf::Vector2f(150, 400));
	m_text.setPosition(sf::Vector2f((float)((WINDOW_W - m_text.getGlobalBounds().width) / 2.0f), (float)((WINDOW_H - m_text.getGlobalBounds().height) / 2.0f)));
	

	
}

void GameOver::HandleInput(sf::RenderWindow * window)
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::MouseMoved:
			if (isTextClicked(window, m_aButtons[0]))
				m_aButtons[0].setFillColor(sf::Color::Yellow);
			else
				m_aButtons[0].setFillColor(sf::Color::White);
			if (isTextClicked(window, m_aButtons[1]))
				m_aButtons[1].setFillColor(sf::Color::Yellow);
			else
				m_aButtons[1].setFillColor(sf::Color::White);
			if (isTextClicked(window, m_aButtons[2]))
				m_aButtons[2].setFillColor(sf::Color::Yellow);
			else
				m_aButtons[2].setFillColor(sf::Color::White);
			break;
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (isTextClicked(window, m_aButtons[0])) {
			StateMachine->AddState(StateRef(new GameScene));
		}
		if (isTextClicked(window, m_aButtons[1])) {
			StateMachine->AddState(StateRef(new MainMenu()));
		}
		if (isTextClicked(window, m_aButtons[2])) {
			window->close();
		}
	}
}

void GameOver::Update(float dt)
{
}

void GameOver::Render(sf::RenderWindow * window)
{
	window->draw(m_rec);
	window->draw(m_text);

	for (auto x : m_aButtons) {
		window->draw(x);
	}
}



