//Standard C++ Libraries
#include <iostream>
#include <math.h>
#include <algorithm>>
#include <thread>
#include <string>
#include <cstdio>
#include <sstream>


//SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


//enable the "to_string" function of std:: as code-blocks has bugs with it not working correctly
template <typename T>
std::string to_string(T value){
      //create an output string stream
      std::ostringstream os ;
      //throw the value into the string stream
      os << value ;
      //convert the string stream into a string and return
      return os.str() ;
}


int main()
{
	//Creates game window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Cookie Clicker");


	// Create our own view (basically allows for resizing of window to only be perspective based)
	// The viewport allows to map the scene to a custom part of the render target, and can be used for split-screen or for displaying a minimap,
	// for example. If the source rectangle doesn't have the same size as the viewport, its contents will be stretched to fit in.
	sf::View ourView;
	// Initialize the view to a rectangle located at (0, 0) and with a size of 800x600 (like the window dimentions
	ourView.reset(sf::FloatRect(0, 0, 800, 800));
	// Set its target viewport to be the entire window
	ourView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));




	//Creates a "CircleShape" object in the variable "cookie"
	sf::CircleShape cookie(200.f, 180);
	sf::Texture cookieTxt;

    //get the cookie's texture and apply it to the circle
    if (!cookieTxt.loadFromFile("resources/img/cookie.png"))
	{
		return EXIT_FAILURE;
	}
	cookie.setTexture(&cookieTxt);

	//set circle's center point to (0, 0)
	cookie.setOrigin(0.f, 0.f);


	// set the cookie's position (just a bit higher than the center of screen) and use window.getSize to get the x and y of window
    // and getRadius to offset where it starts (point 200,200 because thats its radius)
    // need to add check to ensure that if the window dimensions are too small the cookie doesn't leave the screen accidentally
    cookie.setPosition((window.getSize().x / 2.f) - cookie.getRadius(), (window.getSize().y / 3.f) - cookie.getRadius());
    int i = 0;

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

		//debug for cookie position & origin
		std::cout << cookie.getPosition().x << " " << cookie.getRadius()<< "   ";
		std::cout << cookie.getOrigin().x << " " << cookie.getScale().x << " " << cookie.getScale().y << "\n";

		//Reset the window
		window.clear();

        // Apply the veiwport (ourVeiw)
        window.setView(ourView);
		//Draw the "cookie" we created onto the new veiwport
		window.draw(cookie);


		//Update the display on the screen using ourVeiw
		window.display();
	}
	system("pause");
	return 0;
}


