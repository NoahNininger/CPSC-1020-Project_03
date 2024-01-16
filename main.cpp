#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
  int numGames {0}, humanWins {0}, cpuWins {0}, humanGameWins {0}, 
      cpuGameWins {0}, finalNumRounds {0}, totalHumanPoints {0}, totalCpuPoints {0},
      numRounds, userInput;
  vector<int> humanPoints, cpuPoints;

  cout << "Welcome to TigerGame!" << endl;

  do
  {
    cout << "How many rounds would you like to play? ";
    cin >> numRounds;

    Card humanCard, cpuCard;
    Deck deckOfCards;
    Player human (deckOfCards, numRounds), cpu (deckOfCards, numRounds);
    numGames = numGames + 1;

    deckOfCards.shuffle();                                                      // shuffles the deck
    cout << "The deck was shuffled and each player has drawn "
         << numRounds << " cards." << endl << endl;

    for (int i = 0; i < numRounds; ++i)                                         // loops until all rounds are played
    {
      cout << "Round "<< (i + 1) << endl << "-------" << endl;

      cpu.hand.dealCard(i);                                                     // cpu draws card
      cout << "The computer plays: " << cpuCard.printCard() << endl;

      cout << "Your hand:" << human.hand.printHand() << endl
          << "Which card do you want to play? ";
      cin >> userInput;                                                         // allows user to select card to draw
      human.hand.dealCard(userInput);                                           // draws the selected card
      cout << "You played: " << humanCard.printCard() << endl;

      if (humanCard.getValue() > cpuCard.getValue())                            // if human wins round
        {
          cout << "You win this round!" << endl << endl;
          human.score = human.score + (humanCard.getValue() + cpuCard.getValue());
          humanWins = humanWins + 1;
        }
      else if (cpuCard.getValue() > humanCard.getValue())                       // if cpu wins round
        {
          cout << "The computer wins this round!" << endl << endl;
          cpu.score = cpu.score + (humanCard.getValue() + cpuCard.getValue());
          cpuWins = cpuWins + 1;
        }
      else                                                                      // if tie
        { cout << "Tie!" << endl << endl; }

      cout << "Current scores:" << endl                                         // prints current scores
          << "Human: " << human.score << endl
          << "Computer: " << cpu.score << endl << endl;
    }

    cout << "FINAL SCORE:" << endl                                              // prints final score
        << "Human: " << human.score << endl
        << "Computer: " << cpu.score << endl << endl;

    humanPoints.push_back(human.score);
    cpuPoints.push_back(cpu.score);

    totalHumanPoints = totalHumanPoints + human.score;
    totalCpuPoints = totalCpuPoints + cpu.score;

    if (human.score > cpu.score)                                                // if human wins
      {
        cout << "Human has won!" << endl;
        humanGameWins = humanGameWins + 1;
      }
    else if (cpu.score > human.score)                                           // if cpu wins
      { 
        cout << "Computer has won!" << endl; 
        cpuGameWins = cpuGameWins + 1;
      }
    else                                                                        // if human and cpu tie
      { cout << "Human and Computer have tied!" << endl; }

    finalNumRounds = finalNumRounds + numRounds;                                // calculates total number of rounds

    cout << "Want to play another game of TigerGame? ";
    cin >> userInput;
  } while (userInput == 'Y');                                                   // loops until player is finished    

  cout << endl << "Summary" << endl 
       << "-------------------------------------" << endl
       << "Number of Games: " << numGames << endl                               // prints each total provided
       << "Number of Rounds: " << finalNumRounds << endl << endl
       << "Number of Rounds Won By Human: " << humanWins << endl
       << "Number of Rounds Won By Computer: " << cpuWins << endl
       << "-------------------------------------" << endl
       << "Number of Games Won By Human: " << humanGameWins << endl
       << "Number of Games Won By Computer: " << cpuGameWins << endl << endl
       << "Number of Points Won By Human: ";
       
       int humanSize = humanPoints.size();
       for (int i = 0; i < humanSize; i++)
        { cout << humanPoints.at(i) << ", "; }
      
      cout << endl << "Number of Points Won By Computer: ";
      
      int cpuSize = cpuPoints.size();
      for (int i = 0; i < cpuSize; i++)
        { cout << cpuPoints.at(i) << ", "; }

      cout << endl << "-------------------------------------" << endl
           << "Human Total: " << totalHumanPoints << endl
           << "Computer Total: " << totalCpuPoints << endl << endl
           << "Thanks for playing!" << endl;

  return 0;
}