#pragma once

#include <set>
#include <SFML/Graphics.hpp>

class ECIAS {
	public:
		ECIAS();
		~ECIAS();

		void run();
		void close();
	private:
		void handleEvents();
		void eventClose(sf::Event);
		void eventConConnected(sf::Event);
		void eventConDisconnected(sf::Event);
		void eventConButton(sf::Event);

		sf::RenderWindow *window;
		std::set<int> controllers;
};
