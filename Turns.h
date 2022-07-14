#ifndef TURN
#define TURN

#include "Enemy.h"
#include "Player.h"
#include "Battle.h"
using namespace std;

class Turns
{
public:
    Turns();
    double turn(Player*,Enemy*,Battle*);
};
#endif
