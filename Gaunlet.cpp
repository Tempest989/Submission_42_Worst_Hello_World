#include <iostream>
#include <unistd.h>
#include <limits>
#include <time.h>
#include "Controller.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int finale=0;
    double results=1.5;
    Controller fatController;
    string name=" ";
    int again=1;
    
    cout << "Welcome Welcome ye few from far and wide, To the New World!!" << endl << endl;
    usleep(150000);
    for (int i=0;i<10;i++)
    {
        cout << "*clapping applaise" << endl;
        usleep(300000);
    }
    
    cout << "\e[1m" << "SILENCE!" << "\e[0m" << endl << endl;
    usleep(3000000);

    cout << "Now What is YOUR NAME?: ";
    cin >> name;
    
    cout << endl << endl;

    cout << "Now if any of U wish to see this paradise, ye must RUN the gaunlet and PROVE YE ARE WISE!" << endl;
    cout << "*incoherent chatter all around" << endl;
    usleep(15000);

    cout << "If you REALLY wish to see this new world, prove to it me." << endl <<  "Exhaust your reason, knowledge, skills, and wealth to construct a tower of wisdom and prove that you are indeed -- wise." << endl << endl;
    usleep(100000);    

    while (again==1)
    {
        finale=0;
        cout << "Now If " << "\e[1m" << "YOU" << "\e[0m" << " are READY, Lets Begin....." << endl << endl << endl;

        cout << "LOADED FIRST TRIAL....";
        usleep(9000000);

        cout << endl << endl << endl;

        results=fatController.mainRock(name);
        
        if (results>=1)
        {
            finale++;
            if (results==1.5)
            {
                finale++;
            }
            cout << endl << "Congratulations, You have an Operating Brain capable of Thinking; You'll need More than That from Here on Out, Now SHUFFLE on Out of Here" << endl << endl << endl;

            cout << "LOADED SECOND TRIAL....";
            usleep(9000000);

            results=fatController.mainBlackJack(name);
            if (results>=1)
            {
                finale++;
                if (results==1.5)
                {
                    finale++;
                }
                cout << "LOADED THIRD TRIAL....";
                usleep(9000000);
                
                cout << endl << endl << endl;

                results=fatController.mainPoke(name);
                
                if (results>=1)
                {
                    finale++;
                    if (results==1.5)
                    {
                        finale++;
                    }
                        
                    cout << endl << "Finale, someone has DONE IT, finally clear this FORSAKEN GAUNLET OF RNG, WELCOME TO THE NEW WORLD FRIEND, now say it" << endl;
                    if (finale<6)
                    {
                        cout << "HELLO NOTHING, GET GUD!" << endl;
                    }
                    if (finale>=6)
                    {
                        cout << "HELLO WORLD!!!!" << endl;
                        cout << endl << "CONGRATS, U BIG WIN! Enjoy the NEW WORLD!!!!!" << endl << endl;
                        return 0;
                    }

                     cout << endl << "Thanks again for dropping by, IS THIS THE RESULT U WANTED? IF NOT, The Gaunlet Awaits... " << endl << endl;
    
                }
                else
                {
                    cout << endl << "YOU'VE TRIED SO HARD, AND GOT SO FARRRR, BUT IN THE END IT DOES'NOT EVEN MATTEEEERRRR" << endl;
                }
            }
        }
        
        cout << "You Have FAILED! Wow what an impressive Cavity you have in your EMPTY SKULL." << endl << endl;
        cout << "Would you like to try again, Plebeian? ( 1 = YES, 0 = NO ) : ";
        cin >> again;

        while ((again!=0&&again!=1)||(cin.fail()==true))
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

        if (again==1)
        {
            cout << "Great, Now let me just hit this Big Red RESET BUTTON..." << endl;
        }
        else if (again==0)
        {
            cout << "Run along then, I have beter things to attend to." << endl << endl;
        }
    }
    
    return 0;
}
