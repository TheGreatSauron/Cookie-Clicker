#include "TextDisplay.h"
#include "to_string.h"

//Allows display to be drawn directly
void TextDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(Display, states);
}

//Construct the display and set number to be displayed
TextDisplay::TextDisplay(sf::Font& Font, sf::Vector2f Position, int& DisplayedNumber)
{
    IsDrawable = true;

    DisplayNumber = &DisplayedNumber;

    Display = sf::Text(sf::String("Error"), Font);
    Update(sf::seconds(0));

    setPosition(Position);
}

//Update the text every frame
void TextDisplay::Update(sf::Time DeltaTime)
{
    Display.setString(to_string(*DisplayNumber));

    Display.setOrigin(Display.getLocalBounds().width / 2, Display.getLocalBounds().height / 2);
}

//Sets character size
void TextDisplay::SetCharacterSize(unsigned NewSize)
{
    Display.setCharacterSize(NewSize);
}
