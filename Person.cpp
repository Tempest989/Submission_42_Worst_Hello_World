#include "Person.h"

Person::Person()
{

}

string Person::getItem(int i)
{
    return item[i];
}

string Person::getItemDescript(int i)
{
    return itemDescript[i];
}

string Person::getName()
{
    return name;
}

void Person::setCurrent(int change)
{
    current=change;
}
int Person::getCurrent()
{
    return current;
}

Pokemon* Person::getParty(int i)
{
    return &party[i];
}