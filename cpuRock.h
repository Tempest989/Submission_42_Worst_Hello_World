#ifndef CPUROCK
#define CPUROCK

#include "PersonRock.h"
using namespace std;

class cpuRock: public PersonRock
{
    public:
    cpuRock();
    void set_choice();
    void set_name(int);
};
#endif
