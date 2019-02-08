#include "ECIAS.hpp"

ECIAS::ECIAS()
{
	this->window = new sf::RenderWindow(
		sf::VideoMode(1280, 720),
		"Every Controller Is A Soundboard",
		sf::Style::Close
	);

	for (unsigned int i = 0; i < sf::Joystick::Count; i += 1) {
		if (sf::Joystick::isConnected(i)) {
			this->controllers.insert(i);
		}
	}
}

ECIAS::~ECIAS()
{
}
