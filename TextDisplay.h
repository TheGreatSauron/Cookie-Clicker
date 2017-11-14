#ifndef TEXTDISPLAY_H_INCLUDED
#define TEXTDISPLAY_H_INCLUDED

#include "Object.h"
#include "SFML/graphics.hpp"
#include <memory>

//Used for displaying the number of cookies that have been clicked
class TextDisplay : public Object, public sf::Drawable
{
    //Number to be displayed
    int* DisplayNumber;

    //Rendered object
    sf::Text Display;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    TextDisplay(sf::Font& Font, sf::Vector2f Position, int& DisplayedNumber);
    virtual void Update(sf::Time DeltaTime);
    void SetPosition(float x, float y);
    sf::Vector2f GetPosition();
};

#endif // TEXTDISPLAY_H_INCLUDED
