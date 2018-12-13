// A class for Playing Cards
#ifndef CARD_H
#define CARD_H

using namespace std;

enum cRank 
{
    // Blank is a special rank to signal out of cards
    BLANK = 0, ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING
};

enum suit 
{
    CLUBS, DIAMONDS, HEARTS, SPADES
};

class Card 
{
public:
    // Card Constructors
    Card();
    Card(cRank r, suit s);

    // Get the short name of a card (1s, Kc)
    string CardName() const; 
    
    // Get the long name (Ace of Hearts, 3 of Diamonds)
    string CardNameLong() const; 
    
    // Get the numeric value of the card 
    // (Will be the face value, though some cards may have multiple values based on need)
    int GetValue() const; // 1-13

private:
    cRank m_Rank;
    suit m_Suit;
};

#endif /* CARD_H */
