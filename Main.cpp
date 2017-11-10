#include <SFML\graphics.hpp>

int main()
{
	//Creates game window
	sf::RenderWindow window(sf::VideoMode(800, 800), "Cookie Clicker");

	//Creates a "shape" object in the variable shape and makes it green
	sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Green);

	//Application runs until window is closed
	while (window.isOpen())
	{
		//Polls all input events per frame
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			//Searches for event type and applicable actions
			switch(Event.type)
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


