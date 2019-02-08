#include "ECIAS.hpp"

#include <iostream>

Controller::Controller()
{
}

Controller::Controller(unsigned int id)
: id(id), button_count(sf::Joystick::getButtonCount(id)), buffer_ref(nullptr)
{
	std::cout << "Connected " << sf::Joystick::getIdentification(id).name.toAnsiString() << std::endl
	<< "Buttons: " << this->button_count << std::endl;
}

void Controller::setBufferReference(sf::SoundBuffer *ptr)
{
	this->buffer_ref = ptr;
}

void Controller::playSound(unsigned int button, sf::Sound &sound)
{
	float pitch;

	if (!this->buffer_ref)
		return;
	pitch = (10.f / (float)this->button_count) * (button + 1);
	sound.setBuffer(*this->buffer_ref);
	sound.setPitch(pitch);
	sound.play();
}
