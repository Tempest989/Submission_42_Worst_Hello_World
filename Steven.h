#ifndef STEVEN
#define STEVEN
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"

class Steven: public Battle
{
public:
    Steven();
    int enemyAttack(Player*,Enemy*,Battle*);
    int enemyItem(Enemy*,Player*,Battle*);
};
#endif
