#ifndef PLAYER
#define PLAYER
#include "Person.h"
#include <string>
using namespace std;

class Player: public Person
{
public:
    Player();
    void Name(string);
    void AssignParty();

    void setItemUse(int,int,string);
    int getItemUse(int);

private:
    int itemUse[6];
    //Pokemon *dittoOG;   create array for base stats incase of swap for ditto
};
#endif
