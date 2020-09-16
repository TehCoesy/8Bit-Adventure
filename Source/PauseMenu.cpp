#include "PauseMenu.h"

PauseMenu::PauseMenu(int time, Player* player) {
	this->player = player;
	this->elap_time = time;
	//this->playerGUI = playerGUI;
}

void PauseMenu::Init() {
	m_rec.setFillColor(sf::Color(0, 0, 0, 150));
	m_rec.setSize(sf::Vector2f((float)WINDOW_W, (float)WINDOW_H));


	m_font.loadFromFile(FONT_FONT2);
	m_text.setFont(m_font);
	m_text.setString("PAUSE");
	m_text.setCharacterSize(20);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::White);
	m_aButtons.push_back(m_text);
	m_aButtons.push_back(m_text);
	float margin = WINDOW_W / 20.0;
	m_aButtons[0].setString("Continue");
	m_aButtons[1].setString("Title Screen");
	float x = WINDOW_W - margin * 2;
	for (int i = 0; i < 2; i++) {
		x -= m_aButtons[i].getGlobalBounds().width;
	}
	float pos = margin;
	for (int i = 0; i < 2; i++) {
		m_aButtons[i].setPosition(pos, 0.9f * WINDOW_H);
		pos += m_aButtons[i].getGlobalBounds().width + x;
	}
	//t.setPosition(sf::Vector2f(150, 400));
	m_text.setCharacterSize(30);
	m_text.setPosition(sf::Vector2f((float)((WINDOW_W - m_text.getGlobalBounds().width) / 2.0f), (float)(0.15f*WINDOW_H)));
	//m_text.setPosition(sf::Vector2f((float)((WINDOW_W - m_text.getGlobalBounds().width) / 2.0f), (float)((WINDOW_H - m_text.getGlobalBounds().height) / 2.0f)));
	p_state = 0;
	resume = false;
	toTitle = false;
	sf::Text text;
	text.setFont(m_font);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	m_Objective.push_back(text);
	m_Objective.push_back(text);
	m_Objective.push_back(text);
	for (int i = 0; i < 3; i++) {
		std::string str;
		if (SettingArg::GetInstance()->m_Objectives[i].first.GetValue() == Objectives::CLEAR_STAGE_IN_TIME) {
			str = "Clear stage in under " + std::to_string(SettingArg::GetInstance()->m_Objectives[i].second) + " seconds.";
		}
		else if (SettingArg::GetInstance()->m_Objectives[i].first.GetValue() == Objectives::LOSE_HP_LESS_THAN) {
			str = "Lose less than " + std::to_string(SettingArg::GetInstance()->m_Objectives[i].second) + " PERCENTAGE OF TOTAL HP.";
		}
		else if (SettingArg::GetInstance()->m_Objectives[i].first.GetValue() == Objectives::DIE_LESS_THAN) {
			str = "Die less than " + std::to_string(SettingArg::GetInstance()->m_Objectives[i].second) + " times.";
		}
		m_Objective[i].setString(str);
		m_Objective[i].setPosition(100.0f, 250.0f + i*60.0f);
	}
}

void PauseMenu::HandleInput(sf::RenderWindow * window)
{
	//TODO: change state
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
			break;
		}
	}
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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!resume && !toTitle) {
			if (isTextClicked(window, m_aButtons[0])) {
				resume = true;
			}
			else if (isTextClicked(window, m_aButtons[1])) {
				toTitle = true;
			}
		}
	}
	else {
		if (resume) {
			StateMachine->RemoveState();
		}
		if (toTitle) {
			StateMachine->AddState(StateRef(new MainMenu()), true);
		}
	}
}

void PauseMenu::Update(float dt)
{
	SettingArg::GetInstance()->setTime(time(NULL) - elap_time);
	//SettingArg::GetInstance()->setTime(time(NULL) - start_time+SettingArg::GetInstance()->getTime());
}

void PauseMenu::Render(sf::RenderWindow * window)
{
	window->draw(m_rec);
	window->draw(m_text);

	for (auto x : m_aButtons) {
		window->draw(x);
	}
	if (SettingArg::GetInstance()->getMod()==0)
	for (int i = 0; i < 3; i++) {
		std::string str = m_Objective[i].getString();
		if (SettingArg::GetInstance()->m_Objectives[i].first.GetValue() == Objectives::CLEAR_STAGE_IN_TIME) {
			int _time = time(NULL) - SettingArg::GetInstance()->getTime();
			if (_time >= SettingArg::GetInstance()->m_Objectives[i].second) {
				m_Objective[i].setFillColor(sf::Color::Red);
				m_Objective[i].setString(m_Objective[i].getString() + " (Failed)");
			}
			else {
				m_Objective[i].setFillColor(sf::Color::White);
				m_Objective[i].setString(m_Objective[i].getString() + " (Ongoing)");
			}
		}
		else if (SettingArg::GetInstance()->m_Objectives[i].first.GetValue() == Objectives::LOSE_HP_LESS_THAN) {
			if (player->getHealth() <= 0.01f * SettingArg::GetInstance()->m_Objectives[i].second * player->getMaxHealth()) {
				m_Objective[i].setFillColor(sf::Color::Red);
				m_Objective[i].setString(m_Objective[i].getString() + " (Failed)");
			}
			else {
				m_Objective[i].setFillColor(sf::Color::White);
				m_Objective[i].setString(m_Objective[i].getString() + " (Ongoing)");
			}
		}
		else if (SettingArg::GetInstance()->m_Objectives[i].first.GetValue() == Objectives::DIE_LESS_THAN) {
			m_Objective[i].setFillColor(sf::Color::White);
			m_Objective[i].setString(m_Objective[i].getString() + " (Ongoing)");
		}
		window->draw(m_Objective[i]);
		m_Objective[i].setString(str);
	}
}

bool PauseMenu::isTextClicked(sf::RenderWindow* window, sf::Text text) {
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	if (rect.contains(sf::Mouse::getPosition(*window)))
		return true;


	//Otherwise, don't do anything
	return false;
}




