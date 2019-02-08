#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Controller.hpp"

class ECIAS {
	public:
		ECIAS();
		~ECIAS();

		void run();
		void close();
	private:
		void cleanSounds();
		void handleEvents();
		void eventClose(sf::Event);
		void eventConConnected(sf::Event);
		void eventConDisconnected(sf::Event);
		void eventConButton(sf::Event);

		sf::RenderWindow *window;
		std::unordered_map<unsigned int, Controller> controllers;
		std::unordered_map<std::string, sf::SoundBuffer> loaded_instruments;
		std::vector<sf::Sound> sounds;
};
