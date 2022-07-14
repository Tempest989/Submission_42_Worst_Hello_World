#ifndef PLAYERBLACKJACK
#define PLAYERBLACKJACK

#include <string>
#include "personBlackJack.h"

class playerBlackJack: public personBlackJack
{
    public:
    playerBlackJack(std::string);

    void setName(std::string);
    std::string getName();

    private:
    std::string name;

};
#endif
