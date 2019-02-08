#include "ECIAS.hpp"

void ECIAS::run()
{
	while (this->window->isOpen()) {
		this->window->clear(sf::Color::Black);
		this->window->display();
		this->handleEvents();
	}
}
