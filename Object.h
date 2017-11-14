#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "SFML/system.hpp"

//Base class for all objects that update every frame
class Object
{
public:
    virtual void Update(sf::Time DeltaTime) =0;
};

#endif // OBJECT_H_INCLUDED
