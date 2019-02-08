#include <unordered_map>
#include <ECIAS.hpp>

#include <iostream>

void ECIAS::eventClose(sf::Event __attribute__((unused)) event)
{
	this->close();
}

void ECIAS::eventConConnected(sf::Event event)
{
	unsigned int id = event.joystickConnect.joystickId;

	this->controllers[id] = Controller(id);
}

void ECIAS::eventConDisconnected(sf::Event event)
{
	unsigned int id = event.joystickConnect.joystickId;

	this->controllers.erase(id);
}

void ECIAS::eventConButton(sf::Event event)
{
	unsigned int id = event.joystickButton.joystickId;
	unsigned int button = event.joystickButton.button;
	auto sound = this->sounds.insert(this->sounds.end(), sf::Sound());

	this->controllers[id].playSound(button, *sound);
}


void ECIAS::handleEvents()
{
	static std::unordered_map<sf::Event::EventType, void (ECIAS::*)(sf::Event)> handlers = {
		{sf::Event::Closed, &ECIAS::eventClose},
		{sf::Event::JoystickConnected, &ECIAS::eventConConnected},
		{sf::Event::JoystickDisconnected, &ECIAS::eventConDisconnected},
		{sf::Event::JoystickButtonPressed, &ECIAS::eventConButton},
	};

	sf::Event event;

	while (this->window->pollEvent(event)) {
		if (handlers.find(event.type) != handlers.end()) {
			(this->*handlers[event.type])(event);
		}
	}
}
