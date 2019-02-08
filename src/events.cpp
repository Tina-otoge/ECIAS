#include <unordered_map>
#include <ECIAS.hpp>

#include <iostream>

void ECIAS::eventClose(sf::Event __attribute__((unused)) event)
{
	this->close();
}

void ECIAS::eventConConnected(sf::Event event)
{
	this->controllers.insert(event.joystickConnect.joystickId);

	unsigned int id = event.joystickConnect.joystickId;
	std::cout << "Controller " << sf::Joystick::getIdentification(id).name.toAnsiString() << " (" << id << ") connected." << std::endl;
}

void ECIAS::eventConDisconnected(sf::Event event)
{
	this->controllers.erase(event.joystickConnect.joystickId);
	std::cout << "Controller " << event.joystickConnect.joystickId << " disconnected." << std::endl;
}

void ECIAS::eventConButton(sf::Event event)
{
	std::cout << "Button " << event.joystickButton.button << " pressed on " << event.joystickButton.joystickId << std::endl;
}


void ECIAS::handleEvents()
{
	sf::Event event;

	std::unordered_map<sf::Event::EventType, void (ECIAS::*)(sf::Event)> handlers = {
		{sf::Event::Closed, &ECIAS::eventClose},
		{sf::Event::JoystickConnected, &ECIAS::eventConConnected},
		{sf::Event::JoystickDisconnected, &ECIAS::eventConDisconnected},
		{sf::Event::JoystickButtonPressed, &ECIAS::eventConButton},
	};

	while (this->window->pollEvent(event)) {
		if (handlers.find(event.type) != handlers.end()) {
			(this->*handlers[event.type])(event);
		}
	}
}
