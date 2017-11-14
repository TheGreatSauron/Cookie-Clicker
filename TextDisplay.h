#ifndef TEXTDISPLAY_H_INCLUDED
#define TEXTDISPLAY_H_INCLUDED

#include "Object.h"
#include "SFML/graphics.hpp"

//Used for displaying the number of cookies that have been clicked
class TextDisplay : public Object, public sf::Drawable, public sf::Transformable
{
    //Number to be displayed
    int* DisplayNumber;

    //Rendered object
    sf::Text Display;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    TextDisplay(sf::Font& Font, sf::Vector2f Position, int& DisplayedNumber);
    virtual void Update(sf::Time DeltaTime);
    void SetCharacterSize(unsigned NewSize);
};

#endif // TEXTDISPLAY_H_INCLUDED
