//Standard C++ Libraries
#include <iostream>
#include <math.h>
#include <algorithm>
#include <thread>
#include <string>
#include <sstream>


//SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Our headers
#include "TextDisplay.h"

//stands for cookieClickDetect
bool cClickDetect(sf::Event event, sf::CircleShape shape, float Xsize, float Ysize) {
		//preforms pythagorean therum on the point you choose and see if its inside it or not, it is also offset by the cookies position (y / 3 and x / 2)
		float pythagorean = sqrt((pow(event.mouseButton.x - Xsize / 2, 2)) + (pow(event.mouseButton.y - (Ysize / 3), 2)));
        if (pythagorean <= shape.getRadius()) {
		//just output to console for now...
		return true;
        }
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
	ourView.reset(sf::FloatRect(0, 0, 800, 600));
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

    //Create arial font
    sf::Font Arial;
    if (!Arial.loadFromFile("resources/font/arial.ttf"))
    {
        return EXIT_FAILURE;
    }

    //set cookies to 0
    int cookies = 0;

    //Create TextDisplay for the number of cookies
    TextDisplay CookieDisplay(Arial, sf::Vector2f(window.getSize().x / 2.f, window.getSize().y * (2.f/3.f)), cookies);

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

					//if a mouse button is pressed
                case sf::Event::MouseButtonPressed:
                	//if the left mouse button is pressed
                    if (event.mouseButton.button == sf::Mouse::Left) {
						//check if click is within the bounds of the cookie
                        if (cClickDetect(event, cookie, window.getSize().x, window.getSize().y)) {
                            cookies++;
                        }
                    }
				break;
			}

		}

        CookieDisplay.Update(sf::seconds(0));

		//Reset the window
		window.clear();

        // Apply the veiwport (ourVeiw)
        window.setView(ourView);
		//Draw the "cookie" we created onto the new veiwport
		window.draw(cookie);
		//Draw the TextDisplay for the cookie number
        window.draw(CookieDisplay);

		//Update the display on the screen using ourVeiw
		window.display();
	}
	system("pause");
	return 0;
}


