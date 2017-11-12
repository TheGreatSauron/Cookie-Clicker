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


	// **************NOT YET IMPLIMENTED*************
	// Create our own view (basically allows for resizing of window to only be perspective based)
	// Ensuring that window resizing will not affect the actual graphics, just the users perception of them
	sf::View ourView;
	ourView.reset(sf::FloatRect(100, 100, 400, 200));
	ourView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	// **************NOT YET IMPLIMENTED*************


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

		//get window's current width and height


		//set the cookies position (just a bit higher than the center of screen) and use window.getSize to get the x and y of window
		//and getRadius to offset where it starts (point 200,200 because thats its radius)
		// need to add check to ensure that if the window dimensions are too small the cookie doesn't leave the screen accidentally
		cookie.setPosition((window.getSize().x / 2.f) - cookie.getRadius(), (window.getSize().y / 3.f) - cookie.getRadius());

		//debug for cookie position & origin
		std::cout << cookie.getPosition().x << " " << cookie.getPosition().y << "   ";
		std::cout << cookie.getOrigin().x << " " << cookie.getOrigin().y << "\n";

		//Reset the window
		window.clear();

		//Draw the "cookie" we created (the circle)
		window.draw(cookie);


		//Update the display on the screen using ourVeiw

		//SETS THE VEIW TO OUR UNIMPLIMENTED "ourVeiw"
		//window.setView(ourView);

		window.display();
	}
	system("pause");
	return 0;
}


