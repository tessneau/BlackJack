// A class for a deck of playing card
#ifndef DECK_H
#define DECK_H

using namespace std;

const int DECKSIZE = 52;

class Deck 
{
public:
    Deck();

    //clears deck of all cards
    void Clear();

    //creates deck of 52 cards
    void Populate();

    //shuffles cards
    void Shuffle();

    //deals one card 
    Card Deal();

    // Return Deck size
    int Size();

    // create a string list of all the cards in this deck.
    string GetCardList();

private:
    vector <Card> m_Cards;  // Used to store a list of current cards in Deck. 
};

#endif /* DECK_H */