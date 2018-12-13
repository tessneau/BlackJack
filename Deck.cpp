// Implementation of Deck class
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "Card.h"
#include "Deck.h"

// Private functions needed for shuffling
void seedRandom() 
{
    srand(time(NULL));
}

double nextRandom() 
{
    double random = ((double) rand()) / RAND_MAX;
    return random;
}

Deck::Deck() 
{
    seedRandom(); //seed the random number generator
    Populate();
}

void Deck::Clear() 
{
    //clear vector
    m_Cards.clear();
}

void Deck::Populate() 
{
    Clear();

    //create deck
    for (int s = CLUBS; s <= SPADES; ++s) 
    {
        for (int r = ACE; r <= KING; ++r) 
        {
            m_Cards.push_back(Card(static_cast<cRank> (r), static_cast<suit> (s)));
        }
    }
}

void Deck::Shuffle() 
{
// You do
    seedRandom();
    
    for (int i = 0; i < m_Cards.size(); i++ )
    {
        int randomCard;
        Card temp;
        
        randomCard = rand() % m_Cards.size();
        temp = m_Cards[i];
        m_Cards[i] = m_Cards[randomCard];
        m_Cards[randomCard] = temp;
    }

}

int Deck::Size() 
{
    return m_Cards.size();
}

Card Deck::Deal() 
{
    // Make a special zero valued card in case we have nothing left
    Card aCard(BLANK,CLUBS);
    if (!m_Cards.empty()) {
        aCard = m_Cards.back();
        m_Cards.pop_back();
    } else {
        cout << "Out of cards, Unable to deal.\n";
    }
    
    return aCard;
}

string Deck::GetCardList() 
{
    string list = "";
    for (int i = 0; i < m_Cards.size(); i++) {
        list += m_Cards[i].CardName() + " ";
    }
    
    return list;
}
