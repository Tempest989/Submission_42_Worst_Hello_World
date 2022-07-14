#ifndef ENEMY
#define ENEMY
#include <string>
#include "Pokemon.h"
#include "Person.h"
using namespace std;

class Enemy: public Person
{
public:
    Enemy();
    Enemy(int);
    void Name(string);
    void AssignParty();

    void setItemUse(int, int, string);
    int getItemUse(int);

private:
    int ID;
    int itemUse[2];
};
#endif
