//Standard C++ Libraries
#include <math.h>
#include <algorithm>>
#include <thread>
#include <string>
#include <cstdio>


//SFML libraries
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <SFML/Window.hpp>


int main()
{
	//Creates game window
	sf::RenderWindow window(sf::VideoMode(800, 800), "Cookie Clicker");

	//Allow window to be resized, has a maximize and close button, and has a title-bar
	sf::Style::Default;

	//Creates a "CircleShape" object in the variable "shape" and make it green
	sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Green);

	//Application runs until window is closed
	while (window.isOpen())
	{
		//Polls all input events per frame
		sf::Event event;
		while (window.pollEvent(event))
		{
			//Searches for event type and applicable actions
			switch(event.type)
			{
				//Closes window
				case sf::Event::Closed:
					window.close();
					break;
			}

		}

		//Reset the window
		window.clear();

		//Draw the "shape" we created (the circle)
		window.draw(shape);

		//Update the display on the screen
		window.display();
	}

	return 0;
}


