// A Class for keeping track of wins, losses and pushes.
#ifndef GAME_H
#define GAME_H

using namespace std;

class Game
{
public:
    
    Game();
    
    Game(int w,int l,int p);
    
    void Win();
    
    void Lose();
    
    void Push();
    
    void DisplayScore();
    
private:
    int win;
    int lose;
    int push;
};

#endif /* DECK_H */

