#ifndef REF
#define REF

#include "PersonRock.h"
using namespace std;

class ref
{
    public:
    ref();
    void singleBattle(PersonRock*,PersonRock*);
    int get_cancel();
    int getWins(int);

    private:
    int numWins1;
    int numWins2;
    int numSpecials1;
    int numSpecials2;
    int cancel;
};
#endif
