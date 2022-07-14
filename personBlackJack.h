#ifndef PERSONBLACKJACK
#define PERSONBLACKJACK

#include <string>

class personBlackJack
{
    public:
    personBlackJack();
    void setHand(int);
    int* getHand();
    int getCard(int);
    void setCard(int,int);

    void setTotal(int);
    int getTotal();

    void setWins(int);
    int getWins(int);

    int isAce();

    void resetHand();

    void updateSum(int);
    int getSum();

    protected:
    int hand[5];
    int total;
    int wins[3];
    int sum;
};
#endif
