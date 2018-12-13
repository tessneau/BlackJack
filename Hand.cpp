// Implementation of Hand class
#include <iostream>
#include <string>
#include <vector>

#include "Card.h"
#include "Hand.h"

Hand::Hand() 
{
    m_Cards.reserve(7);
}

void Hand::Add(Card& card) 
{
    // add a card to hand
    m_Cards.push_back(card);
}

bool Hand::Wins() 
{
    // Need to write, currently always busted.
    // Return true if this hand wins (21)
    if (Hand::GetTotal() == 21)
        return true;
    else
        return false; //return false for testing
}

void Hand::Clear() 
{
    //clear vector of cards
    m_Cards.clear();
}

string Hand::GetCardList() 
{
    string list = "";
    for (int i = 0; i < m_Cards.size(); i++) 
    {
        list += m_Cards[i].CardName() + " ";
    }
    return list;

}

int Hand::GetTotal() 
{
    // Compute the total sum of the cards in hand
    // needs to be smart, the ACE is 11 or 1, whichever gets you closer to 21 without going over.
    // just return 0 for testing
    int total(0);
    
    for (int i = 0; i < m_Cards.size(); i++)
    {
        
        if (total <= 10 && m_Cards[i].GetValue() == 1)
        {
            total += 11;
        }
        else
        {
            total += m_Cards[i].GetValue();
        }
        
    }
    
    return total;
}

bool Hand::isBusted() 
{
    // Need to write, currently always busted.
    // Return true if this hand is busted, otherwise return false
    
    if (Hand::GetTotal() > 21 )
        return true;
    else
        return false;
}
