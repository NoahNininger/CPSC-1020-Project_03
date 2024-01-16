#include "Deck.h"

void Deck::shuffle() 
{
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(deck), std::end(deck), rng);        // shuffles deck
}

Card Deck::drawCard() 
{
    Card drawnCard {deck.back()};    // creates an object taken from the last element in deck
    deck.pop_back();                 // removes the last element in deck

    return drawnCard;               // returns the stored value in dealtCard
}

int Deck::getDeckSize()             // accessor
    { return deck.size(); }