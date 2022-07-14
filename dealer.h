#ifndef DEALER
#define DEALER

#include "personBlackJack.h"

class dealer: public personBlackJack
{
    public:
    dealer();
    int getDeck(int);
    void setTotalCards(int);
    int getTotalCards();

    int drawCard();

    void resetDeck();

    int blackJackCheck(int*);

    private:
    int deck[14];
    int totalCards;
};
#endif
