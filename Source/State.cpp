#include "State.h"

bool State::isTextClicked(sf::RenderWindow* window, sf::Text text) {
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	if (rect.contains(sf::Mouse::getPosition(*window)))
		return true;

	return false;
}