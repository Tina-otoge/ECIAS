#pragma once

#include <SFML/Audio.hpp>

class Controller {
	public:
		Controller(unsigned int id);
		Controller();

		void setBufferReference(sf::SoundBuffer *ptr);
		void playSound(unsigned int button, sf::Sound &sound);
	private:
		unsigned int id;
		unsigned int button_count;
		float pitch_offset;
		sf::SoundBuffer *buffer_ref;
};
