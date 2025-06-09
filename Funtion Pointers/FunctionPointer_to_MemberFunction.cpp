/*
In C++, functions that belong to classes are different—this is special syntax.
*/

#include<iostream>
using namespace std;
class Game {
public:
    void start() { cout << "Start Game\n"; }
    void pause() { cout << "Pause Game\n"; }
    void quit()  { cout << "Quit Game\n"; }
};

int main(){
    Game g;
    void (Game::*commands[3])() = { &Game::start, &Game::pause, &Game::quit };
    int choice = 1;
    (g.*commands[choice])();  // Calls pause

    return 0;
}

/*
*commands is an array of pointers to all member functions of class Game.

It points to functions which:

    Returns void
    Belongs to class Game
    Takes no arguments

&Game::start/pause/quit gets the address of the play function in class Game.

📌 This is how you store a class function in a pointer in C++.
*/