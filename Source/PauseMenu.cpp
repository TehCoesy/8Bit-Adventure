#include "PauseMenu.h"


void PauseMenu::Init() {
	m_rec.setFillColor(sf::Color(0, 0, 0, 150));
	m_rec.setSize(sf::Vector2f((float)WINDOW_W, (float)WINDOW_H));


	m_font.loadFromFile(FONT_FONT2);
	m_text.setFont(m_font);
	m_text.setString("PAUSE");
	m_text.setCharacterSize(80);
	m_text.setStyle(sf::Text::Bold);
	//t.setPosition(sf::Vector2f(150, 400));
	m_text.setPosition(sf::Vector2f((float)((WINDOW_W - m_text.getGlobalBounds().width) / 2.0f), (float)((WINDOW_H - m_text.getGlobalBounds().height) / 2.0f)));
	p_state = 0;

}

void PauseMenu::HandleInput(sf::RenderWindow * window)
{
	//TODO: change state
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && p_state == 0) {
		p_state = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && p_state == 1) {
		p_state = 2;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && p_state == 2)
	{
		p_state = 0;
		StateMachine->RemoveState();
	}
}

void PauseMenu::Update(float dt)
{
	
}

void PauseMenu::Render(sf::RenderWindow * window)
{
	window->draw(m_rec);
	window->draw(m_text);

	for (auto x : m_aButtons) {
		window->draw(x);
	}
}




