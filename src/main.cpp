#include <exception>
#include <iostream>
#include "ECIAS.hpp"

int main()
{
	try {
		ECIAS app;
		app.run();
	} catch (const std::exception &e) {
		std::cout << e.what();
	}
	return (0);
}
