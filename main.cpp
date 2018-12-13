#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Game.h"

using namespace std;

void Instructions() {
    cout << "\tGoal: Reach 21 without going over\n\n";
    cout << "\tThe House (computer player) will be playing against you\n\n";
    cout << "\tIf the House busts (goes over), you win.\n\n";
    cout << "\tIf the House doesn't bust, you win if your\n";
    cout << "\ttotal value is greater than the House's\n\n";
    cout << "\tIf the player gets 21 and the House doesn't\n";
    cout << "\tthe player is a winner\n\n";
    cout << "\tIf a player and the House both get 21\n";
    cout << "\tit is declared a push (tie)\n\n";
    cout << "\tc = clubs, d = diamonds, h = hearts, s = spades\n\n";
}

void displayPlayer(string name, Hand h) {
    cout << name << " shows: " << h.GetCardList() << " count: " << h.GetTotal() << endl;
}

int main() {
    Deck gameDeck;
    char opt, anotherGame;

    cout << "\t\tWelcome to Blackjack! Have fun playing!\n\n";
    Instructions();

    Hand player;
    Hand house;
    Card c;
    Card houseCard2;// A second card the house holds until the end
    Game score;
    
    // You will need to add a main loop wrapping a single game, allow the player
    // to keep playing, and keeping track of the score
    // You must create a new object class "Game".  The game object will keep track of the number of wins,  losses, and pushes
    // and will report the score when asked.
    

    //set up the game deck
    gameDeck.Populate();
    do 
    {
        cout << "----------------------------------------------------------------"<< endl;
        player.Clear();
        house.Clear();
        gameDeck.Shuffle();

        // Give house the first two cards
        // first card gets shown, second hid until end.
        c = gameDeck.Deal();
        house.Add(c);

        // Get a second house card to play after the player finishes (but don't play))
        houseCard2 = gameDeck.Deal();

        cout << "The Dealer deals two cards to the house and reveals one: " << c.CardName() << endl;

        // Give the player's their first card
        c = gameDeck.Deal();
        player.Add(c);
        cout << "The Dealer deals you a card: " << c.CardName() << endl;

        // loop giving deal a card until player stands or goes bust
        do {
            // show game state
            displayPlayer("House", house);
            displayPlayer("Player", player);
            cout << "\nStand, or hit you with another card? (S or H)";
            cin >> opt;
            opt = tolower(opt);
            // Give the player another card as long as they want one
            if (opt == 'h') 
            {
                Card d;
                d = gameDeck.Deal();
                player.Add(d);

                cout << "\nYou get a " << d.CardNameLong() << endl;
                
            }
            // loop until the player stands, goes bust, or wins
        } while (opt != 's' && !player.isBusted() && !player.Wins());

        // Play last house card if the player didn't bust
        if (!player.isBusted()) 
        {
            Card e;
            e = gameDeck.Deal();
            house.Add(e);
        }

        cout << "Game over, final results:" << endl;
        //show game state
        displayPlayer("House", house);
        displayPlayer("Player", player);

        // finally examine state of hands and tell user who wins, why they win or if it is a push (tie)
        if (player.GetTotal() == house.GetTotal())
        {
            cout << "Push! Player and House have the same count.";
            score.Push();
        }
        else
        {
            if (player.isBusted())
            {
                cout << "\nPlayer busted... so house wins... ouch!" << endl;
                score.Lose();
            }
            else if (player.Wins())
            {
                cout << "\nPlayer wins with a perfect 21, nice!" << endl;
                score.Win();
            }
            else if (player.GetTotal() > house.GetTotal())
            {
                cout << "\nPlayer wins with a higher count! Nice!" << endl;
                score.Win();
            }
            else if (house.GetTotal() > player.GetTotal())
            {
                cout << "\nHouse wins with a higher count... ouch!" << endl;
                score.Lose();
            }
        }

        // Show winners and losers
        score.DisplayScore();
        
        cout << "\nWant to test your luck again? (Y or y)";
        cin >> anotherGame;
        
    }while (anotherGame == 'Y' || anotherGame == 'y');
    
    
    return 0;
}