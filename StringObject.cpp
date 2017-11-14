#include "StringObject.h"

virtual void draw(RenderTarget& target, RenderStates states) const
{
    states.transform *= TextDisplay.getTransform();

    target.draw(TextDisplay, states);
}

void StringObject::Update(sf::Time DeltaTime)
{

}
