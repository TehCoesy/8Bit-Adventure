 // Precompiled Headers
#include "stdafx.h"

#include "Game.h"

Game::Game() {

}

Game::~Game() {
	
}

void Game::Update(float fDeltaTime) {
	StateMachine->GetActiveState()->Update(fDeltaTime);
	
}

void Game::Render() {
	m_MainWindow.clear();
	
	StateMachine->GetActiveState()->Render(&m_MainWindow);

	m_MainWindow.display();
}

void Game::Init() {
	m_MainWindow.create(sf::VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
	// Limit Display()
	m_MainWindow.setFramerateLimit(static_cast<int>(FRAMERATE));

	RM->InitWithFile("RM.txt");
	SM->InitWithFile("Sound.txt");

	//state machine
	StateMachine->AddState(StateRef(new MainMenu()));
}

sf::RenderWindow* Game::GetMainWindow() {
	return &m_MainWindow;
}

void Game::RunMainLoop() {
	const float fDeltaTime = 1.0f / FRAMERATE;
	float fNewTime = 0.0f, fFrameTime = 0.0f, fInterpolation = 0.0f;
	
	float fCurrentTime = m_Clock.getElapsedTime().asSeconds();
	float fAccumulator = 0.0f;
	bool isMainMenu = true;
	while (m_MainWindow.isOpen()) {

		StateMachine->ProcessStateChanges();
		StateMachine->GetActiveState()->HandleInput(&m_MainWindow);


		sf::Event event;
		while (m_MainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_MainWindow.close();
		}

		fNewTime = m_Clock.getElapsedTime().asSeconds();
		fFrameTime = fNewTime - fCurrentTime;

		if (fFrameTime > 0.25f) {
			fFrameTime = 0.25f;
		}

		fCurrentTime = fNewTime;
		fAccumulator += fFrameTime;

		while (fAccumulator >= fDeltaTime) {
			Update(fDeltaTime);
			fAccumulator -= fDeltaTime;
		}

		Render();

		SM->Clean();
	}

	printf("Application Closed!\n");
}
