// Implementation of Card class
#include <iostream>
#include <string>
#include <vector>

#include "Card.h"

//Constructor

Card::Card() 
{
    m_Rank = ACE;
    m_Suit = CLUBS;
}

Card::Card(cRank r, suit s) 
{
    m_Rank = r;
    m_Suit = s;
}

string Card::CardName() const 
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};
    return (RANKS[m_Rank] + SUITS[m_Suit]);
}

string Card::CardNameLong() const 
{
    const string RANKS[] = {"Blank","Ace","2","3","4","5","6",
        "7","8","9","10","Jack","Queen","King"};
    const string SUITS[] = {"Clubs","Diamonds","Hearts","Spades"};
    return (RANKS[m_Rank] +" of " + SUITS[m_Suit]);
}

int Card::GetValue() const 
{
    //value is number showing on card
    int value = m_Rank;
    //value is 10 for face cards
    if (value > 10) {
        value = 10;
    }
    return value;
}