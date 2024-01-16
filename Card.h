#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card
{
    public:
        enum Color {purple, orange};    // enumerated public member type

        Card() = default;   // defualt constructor
        Card(int r, Color c) : rank{r}, color{c}    // parameterized constructor
        {
            if (color == purple)    // sets value of purple cards equal to it's rank
                { value = rank; }
            else                    // sets value of orange cards twice of it's rank
                { value = 2 * rank; }
        } 

        std::string printCard();

        int getRank();      // accessors
        Color getColor();
        int getValue();
    private:
         int rank {0};              // private member variables
         Color color {purple};
         int value {0};
};
  
#endif // CARD_H_