#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>

#include "Card.h"
#include "Deck.h"

class Hand
{
    private:
        std::vector<Card> hand;
    public:
        Hand() = default;       // default constructor
        Hand(Deck d, int N)     // parameterized constructor
        {
            for (int i = 0; i < N; i++)
                { hand.push_back(d.drawCard()); }
        }

        std::string printHand();    // prototypes
        Card dealCard(int);

        int getHandSize();      // accessor
};

#endif // HAND_H_
