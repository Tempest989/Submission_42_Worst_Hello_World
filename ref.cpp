#include "ref.h"
#include "cpuRock.h"
#include "playerRock.h"
#include <unistd.h>
#include <iostream>
using namespace std;

ref::ref()
{
    numWins1=0;
    numWins2=0;
    numSpecials1=0;
    numSpecials2=0;
    cancel=0;
}

int ref::get_cancel()
{
    return cancel;
}

void ref::singleBattle(PersonRock* first, PersonRock* second)
{
    if (cancel==1&&(first->get_choice()=="Splash"||second->get_choice()=="Splash"))
    {
        if (first->get_choice()=="Splash"&&second->get_choice()=="Splash")
        {
            int winner = rand()%3;
            cout << "Both " << first->get_name() << " and " << second->get_name() << "Activate SPLASH, bouncing kilometres up into the air." << endl;

            cout << "\e[1m" << ".   .   .   .   ." << "\e[0m";
            usleep(1000000);

            cout << endl << "And coming down to Earth with the forces of interplantery meteors, with both hitting the ground with such force that" << endl << "all landmass within sight is flooded with lava spouting out from the now exposed underground, turning the Earth's surface into a lava hotpot." << endl;

            if (winner==0)
            {
                cout << "Since both Players Hit the Ground at the Same Time, both perished via contact with lava at the same time." << endl << endl;
                cancel=4;
                return;
            }
            else if (winner==1)
            {
                cout << "Since " << first->get_name() << " hit the ground first, they were the first to come into contact with the lava and thus left this mortal coil, leaving " << second->get_name() << " the only one left standing (if only for a few more microseconds)." << endl << endl;
                cancel=3;
                return;
            }
            else if (winner==2)
            {
                cout << "Since " << second->get_name() << " hit the ground first, they were the first to come into contact with the lava and thus left this mortal coil, leaving " << first->get_name() << " the only one left standing (if only for a few more microseconds)." << endl << endl;
                cancel=2;
                return;
            }
        }
    }


    if (first->get_choice()=="Nothing")
    {
        cout << endl << first->get_name() << " Uses SPLASH, But it does NOTHING?? What a Fantastic Move!" << endl;
    }
    else if (first->get_choice()=="Splash"&&second->get_choice()!="Splash"&&cancel==0)
    {
        cout << first->get_name() << " Activates SPLASH, bouncing kilometres up into the air." << endl;

        cout << "\e[1m" << ".   .   .   .   ." << "\e[0m";
        usleep(1000000);

        cout << endl << "And coming down to Earth with a force of an interplantery meteor, " << first->get_name() << " hits the ground, casuing ";
        if (numSpecials1<3)
        {
            cout << "fissures to form underneath " << second->get_name() << " and dropping them into a decently-sized hole," << endl << "making them unable to USE their MOVE." << endl << endl;
            cout << first->get_name() << " WINS!!" << endl << endl;
            numWins1++;
            numSpecials1++;
            cout << "Number of WINS for " << first->get_name() << ": " << numWins1 << endl;
            cout << "Number of WINS " << second->get_name() << ": " << numWins2 << endl << endl;
            return;
        }
        else if (numSpecials1==2)
        {
            cout << "the Tectonic Plate below them to flip vertical, launching " << second->get_name() << " out of Earth's Atmosphere and straight into the Sun, incentrating them upon impact." << endl << endl;
            cout << "\e[1m" << "!!SPECIAL FINISH!!" << "\e[0m" << endl << endl;
            numWins1++;
            numSpecials1=0;
            cout << "Number of WINS for " << first->get_name() << ": " << numWins1 << endl;
            cout << "Number of WINS " << second->get_name() << ": " << numWins2 << endl << endl;
            return;
        }
    }
    else if (second->get_choice()=="Splash"&&first->get_choice()!="Splash"&&cancel==0)
    {
        cout << second->get_name() << " Activates SPLASH, bouncing kilometres up into the air." << endl;

        cout << "\e[1m" << ".   .   .   .   ." << "\e[0m";
        usleep(1000000);

        cout << endl << "And coming down to Earth with a force of an interplantery meteor, " << second->get_name() << " hits the ground, casuing ";
        if (numSpecials2<3)
        {
            cout << "fissures to form underneath " << first->get_name() << " and dropping him into a decently-sized hole, making them unable to USE their MOVE." << endl << endl;
            cout << second->get_name() << " WINS!!" << endl << endl;
            numWins2++;
            numSpecials2++;
            cout << "Number of WINS for " << first->get_name() << ": " << numWins1 << endl;
            cout << "Number of WINS " << second->get_name() << ": " << numWins2 << endl << endl;
            return;
        }
        else if (numSpecials2==2)
        {
            cout << "the Tectonic Plate below them to flip vertical, launching " << first->get_name() << " out of Earth's Atmosphere and straight into the Sun, incentrating them upon impact." << endl << endl;
            cout << "\e[1m" << "!!SPECIAL FINISH!!" << "\e[0m" << endl << endl;
            numWins2++;
            numSpecials2=0;
            cout << "Number of WINS for " << first->get_name() << ": " << numWins1 << endl;
            cout << "Number of WINS " << second->get_name() << ": " << numWins2 << endl << endl;
            return;
        }
    }
    else
        cout << endl << first->get_name() << " Uses " << first->get_choice() << endl;

    if (second->get_choice()=="Nothing")
    {
        cout << second->get_name() << " Activates SPLASH, But it does NOTHING?? What a Fantastic Move!" << endl << endl;
    }
    else
        cout << second->get_name() << " Plays " << second->get_choice() << endl << endl;

    if ((first->get_choice()=="Rock"&&second->get_choice()=="Paper")||(first->get_choice()=="Scissors"&&second->get_choice()=="Rock")||(first->get_choice()=="Paper"&&second->get_choice()=="Scissors"))
    {
        cout << second->get_name() << " WINSS!!" << endl << endl;
        numWins2++;
    }
    else if ((first->get_choice()=="Paper"&&second->get_choice()=="Rock")||(first->get_choice()=="Rock"&&second->get_choice()=="Scissors")||(first->get_choice()=="Scissors"&&second->get_choice()=="Paper"))
    {
        cout << first->get_name() << " WINSS!!" << endl << endl;
        numWins1++;
    }
    else if (first->get_choice()==second->get_choice())
    {
        cout << "Its a DRAW!!!" << endl << endl;
    }
    else if (first->get_choice()=="Splash"&&second->get_choice()=="Splash")
    {
        cout << "Both " << first->get_name() << " and " << second->get_name() << "Activate SPLASH, bouncing kilometres up into the air." << endl;

        cout << "\e[1m" << ".   .   .   .   ." << "\e[0m";
        usleep(1000000);

        cout << endl << "And coming down to Earth with a force of interplantery meteors, both hitting the ground, casuing the ground to violently shake and fracture, but ultimately neither Player seems affected." << endl;
        cout << "It's a DRAW!!!" << endl << endl;
        cout << "\e[1m" << "The NEXT SPLASH MOVE would results in the User's Demise!" << "\e[0m" << endl << endl;
        cancel=1;
    }
    else
        cout << "Um, thats supposed to happen?" << endl << endl;

    cout << "Number of WINS for " << first->get_name() << ": " << numWins1 << endl;
    cout << "Number of WINS " << second->get_name() << ": " << numWins2 << endl << endl;
}

int ref::getWins(int i)
{
    if (i==1)
    {
        return numWins1;
    }
    else
    {
        return numWins2;
    }
}
