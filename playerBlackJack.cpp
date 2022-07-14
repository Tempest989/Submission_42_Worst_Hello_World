#include "playerBlackJack.h"

playerBlackJack::playerBlackJack(std::string inputname): personBlackJack()
{
    total=350;
    name=inputname;
}

void playerBlackJack::setName(std::string i)
{
    name=i;
}

std::string playerBlackJack::getName()
{
    return name;
}
