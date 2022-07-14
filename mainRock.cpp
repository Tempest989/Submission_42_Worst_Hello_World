#include <limits>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <string>
#include "playerRock.h"
#include "cpuRock.h"
#include "ref.h"
using namespace std;

void driver(PersonRock* player1, PersonRock* player2)
{
    int again=1;
    int gameNum=0;
    ref reffy;

    while (again==1)
    {
        gameNum++;

        cout << endl << endl << endl << endl << flush;
        usleep(1250000);
        cout << "---------------------------" << endl;
        cout << "      Game Number: " << gameNum << endl;
        cout << "---------------------------" << endl;
        cout << endl << endl << endl << endl << flush;
        usleep(1250000);
        player1->set_choice();

        // for (int i=0;i<51;i++)               // for clearing terminal, very sketchy bug fix for 2 player version
        // {
        //     cout << "\n";
        // }

        player2->set_choice();
        reffy.singleBattle(player1,player2);

        if (reffy.get_cancel()==2||reffy.get_cancel()==3)
        {
            cout << "Due to there being only 1 Player left to play, " << endl << endl;
            if (reffy.get_cancel()==2)
            {
                cout << "\e[1m" << player1->get_name();
            }
            else if (reffy.get_cancel()==3)
            {
                cout << "\e[1m" << player2->get_name();
            }

            cout << " WINS BY DEFAULT!!" << "\e[0m" << endl;

            return;
        }

        if (reffy.get_cancel()==4)
        {
            cout << "Due to there being no Players left to play, the game is a " << "\e[1m" << "DRAW BY DEFAULT!!" << "\e[0m" << endl;
            return;
        }
        cout << "Would you like to PLAY AGAIN? (1 = Yes, 0 = No): ";
        cin >> again;
        while ((again!=0||again!=1)||(cin.fail()==true))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, Please Try Again: ";
            cin >> again;
            if ((!cin.fail())&&(again==0||again==1))
            {
                break;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    PersonRock* player1;
    PersonRock* player2;
    string name1=" ";
    string name2=" ";

    int numplayers;

    cout << "How many HUMAN PLAYERS will be playing today?: ";
    cin >> numplayers;
    while ((numplayers<0||numplayers>2)||(cin.fail()==true))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, Please Try Again: ";
        cin >> numplayers;
        if ((!cin.fail())&&(numplayers>=0&&numplayers<=3))
        {
            break;
        }
    }

    if (numplayers==0)
    {
        cpuRock number1;
        cpuRock number2;

        player1 = &number1;
        player2 = &number2;

        cout << "What is the Name of the First CPU?: ";
        cin >> name1;
                
        cout << "What is the Name of the Second CPU?: ";
        cin >> name2;
        

        player1->set_name(name1);
        player2->set_name(name2);

        driver(player1,player2);
    }
    else if (numplayers==1)
    {
        playerRock number1;
        cpuRock number2;
        player1 = &number1;
        player2 = &number2;

        cout << "What Is Your Name?: ";
        cin >> name1;
                
        cout << "What is the Name of the CPU?: ";
        cin >> name2;

        player1->set_name(name1);
        player2->set_name(name2);

        driver(player1,player2);

    }
    else if (numplayers==2)
    {
        playerRock number1;
        playerRock number2;
        player1 = &number1;
        player2 = &number2;

        cout << "What is the Name of the First Player?: ";
        cin >> name1;
                
        cout << "What is the Name of the Second Player?: ";
        cin >> name2;

        player1->set_name(name1);
        player2->set_name(name2);

        driver(player1,player2);
    }

    cout << endl << endl << "OK, Have a Nice Day and " << "\e[1m" << "THANKS FOR PLAYING!" << "\e[0m" << endl;
    cout << "Hello World!" << endl << endl;

    return 0;
}
