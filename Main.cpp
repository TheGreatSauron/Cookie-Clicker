#include <SFML\graphics.hpp>

int main()
{
	//Creates game window
	sf::RenderWindow Window(sf::VideoMode(800, 800), "Cookie Clicker");
	
	//Application runs until window is closed
	while (Window.isOpen())
	{
		//Polls all input events per frame
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			//Searchhes for event type and applicable actions
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
		
		//Update the display on the screen
		Window.display();
	}
	
	return 0;
}
