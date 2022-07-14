#include "cpuRock.h"
#include <iostream>
using namespace std;

cpuRock::cpuRock():PersonRock()
{
    name="42";
}

void cpuRock::set_choice()
{
    int select = rand()%3;
    if (select==0)
    {
        choice = "Rock";
    }
    else if (select==1)
    {
        choice = "Scissors";
    }
    else if (select==2)
    {
        choice = "Paper";
    }
    else
        choice = "Error 44";
}

void cpuRock::set_name(int i)
{
    if (i>0)
    {
        cout << "What is the NAME for CPU " << i << "?: ";
        cin >> name;
    }
    else if (i<=0)
    {
        cout << "What is the NAME for the CPU?: ";
        cin >> name;
    }
}
