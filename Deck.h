#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

#include "Card.h"


class Deck
{
    private:
        std::vector<Card> deck;
        Card card1;
    public:
        Deck()
        {
            for (int c = 0; c < 10; c++)
            {
                for (int r = 0; r < 2; r++)
                    { deck.push_back(card1); }
            }
        };

        void shuffle();
        Card drawCard();
        int getDeckSize();
};
  
#endif // DECK_H_