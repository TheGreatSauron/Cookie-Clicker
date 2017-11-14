#include "TextDisplay.h"
#include "to_string.h"

//Allows display to be drawn directly
void TextDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= Display.getTransform();

    target.draw(Display, states);
}

//Construct the display and set number to be displayed
TextDisplay::TextDisplay(sf::Font& Font, sf::Vector2f Position, int& DisplayedNumber)
{
    DisplayNumber = &DisplayedNumber;

    Display = sf::Text(sf::String("Error"), Font);

    Update(sf::seconds(0));
}

//Update the text every frame
void TextDisplay::Update(sf::Time DeltaTime)
{
    Display.setString(to_string(*DisplayNumber));
}

void TextDisplay::SetPosition(float x, float y)
{
    Display.setPosition(x, y);
}

sf::Vector2f TextDisplay::GetPosition()
{
    return Display.getPosition();
}
