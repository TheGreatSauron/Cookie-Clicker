#include <SFML\graphics.hpp>

int main()
{
	//Creates game window
	sf::RenderWindow Window(sf::VideoMode(800, 800), "Cookie Clicker");

	//Creates a "shape" object in the variable shape and makes it green
	sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Green);

	//Application runs until window is closed
	while (Window.isOpen())
	{
		//Polls all input events per frame
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			//Searches for event type and applicable actions
			switch(Event.type)
			{
				//Closes window
				case sf::Event::Closed:
					Window.close();
					break;
			}
		}

		//Reset the window
		Window.clear();
		//Draw the "shape" we created (the circle)
		Window.draw(shape);
		//Update the display on the screen
		Window.display();
	}

	return 0;
}


