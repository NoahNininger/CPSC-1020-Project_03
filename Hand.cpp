#include "Hand.h"

std::string Hand::printHand()
{
    Card obj;   // instance of Card
    std::stringstream printHand;
    int handSize = hand.size();

    for (int i = 0; i < handSize; i++)
        { printHand << " [" << i << "] " << obj.printCard(); }

    return printHand.str(); // returns the sstream as as string value
}

Card Hand::dealCard(int num)
{
    Card dealtCard {hand.at(num)};
    hand.erase(hand.begin() + num); // removes Nth element from deck

    return dealtCard;
}

int Hand::getHandSize()     // accessor
    { return hand.size(); }