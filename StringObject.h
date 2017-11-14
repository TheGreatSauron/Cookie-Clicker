#ifndef STRINGOBJECT_H_INCLUDED
#define STRINGOBJECT_H_INCLUDED

#include "SFML/graphics.hpp"
#include "Object.h"

//Object that displays a string from another source
class StringObject : public Object, public Drawable
{
    sf::Text TextDisplay;
    virtual void draw(RenderTarget& target, RenderStates states) const;

public:
    virtual void Update(sf::Time DeltaTime);
};

#endif // STRINGOBJECT_H_INCLUDED
