#include "StageClear.h"


void StageClear::Init() {
	
	m_rec.setFillColor(sf::Color(0, 0, 0, 150));
	m_rec.setSize(sf::Vector2f((float)WINDOW_W, (float)WINDOW_H));
	
	m_font.loadFromFile(FONT_FONT2);
	m_text1.setFont(m_font);
	m_text.setFont(m_font);
	m_text1.setString("STAGE CLEAR");
	m_text1.setCharacterSize(80);
	m_text1.setStyle(sf::Text::Bold);
	m_text1.setPosition(sf::Vector2f((float)((WINDOW_W - m_text1.getGlobalBounds().width) / 2.0f), (float)((WINDOW_H - m_text1.getGlobalBounds().height) / 2.0f)));
	
	m_text.setString("Click to continue...");
	m_text.setCharacterSize(20);
	m_text.setPosition(sf::Vector2f((float)((WINDOW_W - m_text.getGlobalBounds().width) / 2.0f), 750.0f));
	SM->PlayMusicByName("GAME_WIN");
	SM->SetMusicLoop(false);

}

void StageClear::HandleInput(sf::RenderWindow * window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		StateMachine->AddState(StateRef(new MainMenu()));
	}
}

void StageClear::Update(float dt)
{
}

void StageClear::Render(sf::RenderWindow * window)
{

	window->draw(m_rec);
	window->draw(m_text);
	window->draw(m_text1);

	for (auto x : m_aButtons) {
		window->draw(x);
	}
}



