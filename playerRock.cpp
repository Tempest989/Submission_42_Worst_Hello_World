#include <iostream>
#include "playerRock.h"
using namespace std;

playerRock::playerRock():PersonRock()
{
    name = "playerRock";
}

void playerRock::set_choice()
{
    cout << "What MOVE would " << name << " like to make? (1/R/r = Rock, 2/S/s = Scissors, 3/P/p = Paper): ";
    cin >> choice;
    while (choice!="1"&&choice!="2"&&choice!="3"&&choice!="R"&&choice!="r"&&choice!="S"&&choice!="s"&&choice!="P"&&choice!="p"&&choice!="Rock"&&choice!="Paper"&&choice!="Scissors"&&choice!="Splash")
    {
        cout << "Invalid MOVE, Please Try Again: ";
        cin >> choice;
    }

    if (choice=="1"||choice=="R"||choice=="r")
    {
        choice="Rock";
    }
    else if (choice=="2"||choice=="S"||choice=="s")
    {
        choice="Scissors";
    }
    else if (choice=="3"||choice=="P"||choice=="p")
    {
        choice="Paper";
    }
    else if (choice=="Splash")
    {
        if (name=="Magikarp")
        {
            choice="Splash";
        }
        else
        {
            choice="Nothing";
        }
    }
    else if (choice!="Rock"&&choice!="Paper"&&choice!="Scissors")
    {
        choice="Error damn";
    }
}

void playerRock::set_name(string i)
{
    name=i;
}
