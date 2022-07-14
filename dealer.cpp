#include "dealer.h"
#include <cmath>
#include <iostream>

dealer::dealer():personBlackJack()
{
    total=100000;

    for (int i=0;i<14;i++)
    {
        deck[i]=4;
    }

    totalCards=52;
    sum=0;
}

int dealer::getDeck(int card)
{
    return deck[card];
}

void dealer::setTotalCards(int card)
{
    totalCards-=card;
}

int dealer::getTotalCards()
{
    return totalCards;
}

int dealer::drawCard()
{
    int card=ceil(rand()%totalCards);
    int tracker=0;
    for (int i=0;i<14;i++)
    {
        tracker+=deck[i];
        if (tracker>=card)
        {
            deck[i]--;
            totalCards--;
            return i+1;
        }
    }

    return -1;
}

void dealer::resetDeck()
{
    totalCards=52;

    for (int i=0;i<14;i++)
    {
        deck[i]=4;
    }
}

int dealer::blackJackCheck(int* hand)
{
    if ((hand[0]==14&&(hand[1]>=10&&hand[1]<=13))||((hand[1]==14&&(hand[0]>=10&&hand[0]<=13))))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
