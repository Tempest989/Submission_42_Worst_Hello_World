#ifndef PERSON
#define PERSON
#include "Pokemon.h"
#include <string>
using namespace std;

class Person
{
public:
    Person();
    virtual void Name(string) = 0;
    virtual void AssignParty() = 0;

    string getItem(int);

    string getItemDescript(int);

    string getName();

    void setCurrent(int);
    int getCurrent();

    Pokemon* getParty(int);

protected:
    string item[6];
    string itemDescript[6];
    string name;
    int current;
    Pokemon party[6];
};
#endif
