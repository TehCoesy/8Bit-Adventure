#pragma once
#include "SFML\Graphics.hpp"
class State
{
public:
	virtual void Init() = 0;

	virtual void HandleInput(sf::RenderWindow* window) = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderWindow *window) = 0;

	virtual void Pause() { }
	virtual void Resume() { }
};
