// Note: There is no Player.cpp file.
// The player class is simple enough to
// implement everything in Player.h

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Deck.h"
#include "Hand.h"

class Player
{
    public:
        Hand hand;  // instance of Hand
        int score {0};
        
        Player() = default; // default constructor
        Player(Deck d, int N) : hand{d, N} {}   // parameterized constructor
};
  

#endif // PLAYER_H_
