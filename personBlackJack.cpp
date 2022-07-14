#include "personBlackJack.h"

personBlackJack::personBlackJack()
{
    for (int i=0;i<5;i++)
    {
        hand[i]=0;
        if (i<3)
        {
            wins[i]=0;
        }
    }
    total=0;
    sum=0;
}

void personBlackJack::setHand(int dealtCard)
{
    for (int i=0;i<5;i++)
    {
        if (hand[i]<=0||hand[i]>15)
        {
            hand[i]=dealtCard;
            return;
        }
    }
}

int* personBlackJack::getHand()
{
    return hand;
}

int personBlackJack::getCard(int cardnum)
{
    return hand[cardnum];
}

void personBlackJack::setCard(int cardnum,int set)
{
    hand[cardnum]=set;
}

void personBlackJack::setTotal(int i)
{
    total+=i;
}

int personBlackJack::getTotal()
{
    return total;
}

void personBlackJack::setWins(int section)
{
    wins[section]++;
}

int personBlackJack::getWins(int i)
{
    return wins[i];
}

void personBlackJack::resetHand()
{
    for (int i=0;i<5;i++)
    {
        hand[i]=0;
    }
    sum=0;
}

int personBlackJack::isAce()
{
    for (int i=0;i<5;i++)
    {
        if (hand[i]==14)
        {
            return i;
        }
    }

    return -1;
}

void personBlackJack::updateSum(int i)
{
    if (i>10&&i<14)
    {
        sum+=10;
    }
    else if (i==14)
    {
        sum+=11;
    }
    else if (i==15)
    {
        sum-=10;
    }
    else
    {
        sum+=i;
    }
}

int personBlackJack::getSum()
{
    return sum;
}
