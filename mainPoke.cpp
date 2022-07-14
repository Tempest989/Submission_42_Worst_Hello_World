#include "Player.h"
#include "Enemy.h"
#include "Steven.h"
#include "Battle.h"
#include "Turns.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    Player *player1 = new Player();
    Enemy* steven = new Enemy(1);
    Battle *battle;
    Steven steve;
    Turns turner;

    battle = &steve;

    string input=" ";
    cout << "What is Your Name?: ";
    cin >> input;    

    player1->Name(input);
    player1->AssignParty();
    steven->AssignParty();
    steven->Name("Steven");

    turner.turn(player1,steven,battle);

    cout << "Hello World!" << endl << endl;

    free(player1);
    free(steven);
    return 0;
}
