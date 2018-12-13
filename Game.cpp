// Implementation of Hand class
#include <iostream>
#include <string>
#include <vector>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Game.h"

Game::Game()
{
    win = 0;
    lose = 0;
    push = 0;
}

Game::Game(int w,int l,int p) 
{
    win = w;
    lose = l;
    push = p;
}

void Game::Win() 
{
    win++;
}

void Game::Lose()
{
    lose++;   
}

void Game::Push()
{
    push++;
}

void Game::DisplayScore()
{
    cout << "\tOverall Score:\n"
         << "\t Player : " << win  << endl
         << "\t House : "  << lose << endl
         << "\t Pushes : " << push << endl;   
}

