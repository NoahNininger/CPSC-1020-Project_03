#include "Card.h"
#include <sstream>

std::string Card::printCard()   // prints a card (color:rank)
{
    std::stringstream printCard;

    if (color == purple)
        { printCard << "purple:" << rank; }
    else    
        { printCard << "orange:" << rank; }

    return printCard.str(); // converts the sstream to a string
}

int Card::getRank()     // accessors
    { return rank; }
Card::Color Card::getColor()
    { return color; }
int Card::getValue()
    { return value; }