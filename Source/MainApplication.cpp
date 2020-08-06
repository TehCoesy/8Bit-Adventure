// Precompiled Headers
#include "stdafx.h"

#include "Game.h"

int main() {
	// Application entry point;
	Game::GetInstance()->Init();
	Game::GetInstance()->RunMainLoop();
}