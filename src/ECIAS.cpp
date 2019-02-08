#include <exception>
#include "ECIAS.hpp"

ECIAS::ECIAS()
{
	this->window = new sf::RenderWindow(
		sf::VideoMode(1280, 720),
		"Every Controller Is A Synthesizer",
		sf::Style::Close
	);
	this->window->setFramerateLimit(30);

	for (unsigned int i = 0; i < sf::Joystick::Count; i += 1) {
		if (sf::Joystick::isConnected(i)) {
			this->controllers[i] = Controller(i);
		}
	}
}

ECIAS::~ECIAS()
{
	delete this->window;
}
