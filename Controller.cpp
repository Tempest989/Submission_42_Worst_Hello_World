#include "Controller.h"

#include <limits>
#include <iostream>
#include <unistd.h>
#include "playerRock.h"
#include "cpuRock.h"
#include "ref.h"

#include <cmath>
#include <time.h>
#include "dealer.h"
#include "playerBlackJack.h"

#include "Player.h"
#include "Enemy.h"
#include "Steven.h"
#include "Battle.h"
#include "Turns.h"
using namespace std;
Controller::Controller()
{

}

double driver(PersonRock* player1, PersonRock* player2)
{
    int again=1;
    int gameNum=0;
    double results=0;
    ref reffy;

    while (gameNum<5)
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
                results=1.0;
                if (reffy.getWins(1)>=3)
                {
                    results=1.5;
                }
            }
            else if (reffy.get_cancel()==3)
            {
                cout << "\e[1m" << player2->get_name();
            }

            cout << " WINS BY DEFAULT!!" << "\e[0m" << endl;

            return results;
        }

        if (reffy.get_cancel()==4)
        {
            cout << "Due to there being no Players left to play, the game is a " << "\e[1m" << "DRAW BY DEFAULT!!" << "\e[0m" << endl;
            return results;
        }
//        cout << "Would you like to PLAY AGAIN? (1 = Yes, 0 = No): ";
//        cin >> again;
//        while ((again!=0||again!=1)||(cin.fail()==true))
//        {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(),'\n');
//            cout << "Invalid input, Please Try Again: ";
//            cin >> again;
//            if ((!cin.fail())&&(again==0||again==1))
//            {
//                break;
//            }
//        }
    }

    if (reffy.getWins(1)>reffy.getWins(0))
    {
        cout << "You have passed The First Trail, CONGRATIONS!! are out of order" << endl;
        usleep(1500000);
        cout << "But, This is the 1ST of Many to Come, STEEL YOU NERVES AND GOOD LUCK YOUNG ONE...." << endl << endl << endl;
        usleep(3000000);
        results=1;
        if (reffy.getWins(1)>=3)
        {
            cout << ":)" << endl << endl << endl;
            usleep(3000000);
            results=1.5;
        }
        return results;
    }
    else
    {
        cout << endl << endl << "OK, Have a Nice Day and " << "\e[1m" << "THANKS FOR PLAYING!" << "\e[0m" << endl << endl << endl;
        return results;
    }
}

double Controller::mainRock(string input)
{
    PersonRock* player1;
    PersonRock* player2;

    playerRock number1;
    cpuRock number2;
    player1 = &number1;
    player2 = &number2;

    player1->set_name(input);

    return driver(player1,player2);
}


////blackjack


void printHeader(playerBlackJack* Player, dealer* Dealer,int start)
{
	cout << endl << endl;

	if (start==-2)
	{
		cout << "Drawing Player's Cards:" << endl << endl;
	}
	else if (start!=-7)
	{
		cout << "Drawing Player's Card:" << endl << endl;
	}

	if (start==-7)
	{
		cout << "Drawing Dealer's Cards:" << endl << endl;

		cout << "Dealer's Cards: ";
		int* card=Dealer->getHand();

		for (int i=0;i<5;i++)
		{
			if (card[i]<=0||card[i]>15)
			{
				break;
			}
			if (card[i]==11)
			{
				cout << "Jack ";
			}
			else if (card[i]==12)
			{
				cout << "Queen ";
			}
			else if (card[i]==13)
			{
				cout << "King ";
			}
			else if (card[i]==14)
			{
				cout << "Ace ";
			}
			else if (card[i]==15)
			{
				cout << "Ace(1) ";
			}
			else
			{
				cout << card[i] << " ";
			}
		}
		cout << endl << "SUM OF CARDS: " << Dealer->getSum() << endl << endl;

		return;
	}

	int* card=Player->getHand();

	cout << "Player Cards: ";
	usleep(1250000);
	for (int i=0;i<5;i++)
	{
		if (card[i]<=0||card[i]>15)
		{
			break;
		}
		if (card[i]==11)
		{
			cout << "Jack ";
		}
		else if (card[i]==12)
		{
			cout << "Queen ";
		}
		else if (card[i]==13)
		{
			cout << "King ";
		}
		else if (card[i]==14)
		{
			cout << "Ace ";
		}
		else if (card[i]==15)
		{
			cout << "Ace(1) ";
		}
		else
		{
			cout << card[i] << " ";
		}
	}
	cout << endl << "SUM OF CARDS: " << Player->getSum() << endl << endl;

	if (start==-2)
	{
		cout << "Drawing Dealer's cards:" << endl;
	}
	cout << "Dealers cards: ";

	if (start==-2)
	{
		usleep(1250000);
	}

	cout << "? ";

	if (start==-2)
	{
		usleep(1250000);
	}

	if (Dealer->getCard(1)==11)
	{
		cout << "Jack ";
	}
	else if (Dealer->getCard(1)==12)
	{
		cout << "Queen ";
	}
	else if (Dealer->getCard(1)==13)
	{
		cout << "King ";
	}
	else if (Dealer->getCard(1)==14)
	{
		cout << "Ace ";
	}
	else if (Dealer->getCard(1)==15)
	{
		cout << "Ace(1) ";
	}
	else
	{
		cout << Dealer->getCard(1) << " ";
	}
	cout << endl << endl;
}

int initial (playerBlackJack* Player, dealer* Dealer,int bet)
{
	Player->setHand(Dealer->drawCard());
	Player->updateSum(Player->getCard(0));

	Player->setHand(Dealer->drawCard());
	Player->updateSum(Player->getCard(1));

	Dealer->setHand(Dealer->drawCard());
	Dealer->updateSum(Dealer->getCard(0));

	Dealer->setHand(Dealer->drawCard());
	Dealer->updateSum(Dealer->getCard(1));

	printHeader(Player,Dealer,-2);

	if (Dealer->blackJackCheck(Player->getHand())==1&&Dealer->blackJackCheck(Dealer->getHand())==1)
	{
		Player->setWins(2);
		Dealer->setWins(2);
		cout << "BOTH DEALER AND THE PLAYER HAVE BLACKJACK!!!" << endl << endl << "Result: PUSH" << endl << endl;
		//print draw and both go blackjack, maybe put after printing player and dealers cards?
		return 3;
	}
	else if (Dealer->blackJackCheck(Player->getHand())==1)
	{
		Player->setWins(0);
		Dealer->setWins(1);
		Player->setTotal(1.5*bet);
		Dealer->setTotal((-1.5)*bet);
		cout << "PLAYER HAS BLACKJACK!!!" << endl << endl << "Result: WIN" << endl << endl;
		return 2;
	}
	else if (Dealer->blackJackCheck(Dealer->getHand())==1)
	{
		Player->setWins(1);
		Dealer->setWins(0);
		Player->setTotal((-1)*bet);
		Dealer->setTotal(bet);
		cout << "DEALER HAS BLACKJACK!!!" << endl << endl << "Result: LOSS" << endl << endl;
		return 1;
	}

	return 0;
}

void playersTurn(playerBlackJack* Player, dealer* Dealer, int bet)
{
	int decision=0;

	for (int i=2;i<5;i++)
	{
		if (i!=2)
		{
			printHeader(Player,Dealer,0);
		}

		cout << "What would the player like to do? ( 0 = STAND, 1 = HIT ) ";
		cin >> decision;
		while ((decision!=0&&decision!=1)||(cin.fail()==true))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, Please Try Again: ";
            cin >> decision;
            if ((!cin.fail())&&(decision==0||decision==1))
            {
                break;
            }
        }

		if (decision==0)
		{
			return;
		}
		else if (decision==1)
		{
			Player->setHand(Dealer->drawCard());
			Player->updateSum(Player->getCard(i));

			while (Player->isAce()!=-1&&Player->getSum()>21)
			{
				Player->setCard(Player->isAce(),15);
				Player->updateSum(15);
			}

			if (Player->getSum()>21)
			{
				printHeader(Player,Dealer,0);
				return;
			}
		}
	}
}


void dealersTurn(dealer* Dealer, playerBlackJack* Player)
{
	for (int i=2;i<5;i++)
	{
		if (Dealer->getSum()<17)
		{
			Dealer->setHand(Dealer->drawCard());
			Dealer->updateSum(Dealer->getCard((i)));

			while (Dealer->isAce()!=-1&&Dealer->getSum()>21)
			{
				Dealer->setCard(Dealer->isAce(),15);
				Dealer->updateSum(15);
			}
		}

		if (Dealer->getSum()>=17)
		{
			printHeader(Player,Dealer,-7);
			return;
		}
	}
}

//do print-outs
void results(playerBlackJack* Player, dealer* Dealer,int bet)
{
	if (Dealer->getSum()>21)
	{
		Player->setTotal(bet);
		Dealer->setTotal((-1)*bet);
		Player->setWins(0);
		Dealer->setWins(1);
		cout << "DEALER has gone BUST" << endl << endl << "Result: WIN" << endl << endl;
		return;
	}

	if ((Player->getSum()<=21)&&(Player->getCard(4)!=0)&&((Dealer->getSum()<=21)&&(Dealer->getCard(4)!=0)))
	{
		Player->setWins(2);
		Dealer->setWins(2);
		cout << "BOTH DEALER AND THE PLAYER HAVE 5-UNDER!!!" << endl << endl << "Result: PUSH" << endl << endl;
	}
	else if ((Player->getSum()<=21)&&(Player->getCard(4)!=0))
	{
		Player->setTotal(bet);
		Dealer->setTotal((-1)*bet);
		Player->setWins(0);
		Dealer->setWins(1);
		cout << "PLAYER HAS 5-UNDER!!!" << endl << endl << "Result: WIN" << endl << endl;
	}
	else if ((Dealer->getSum()<=21)&&(Dealer->getCard(4)!=0))
	{
		Player->setTotal((-1)*bet);
		Dealer->setTotal(bet);
		Player->setWins(1);
		Dealer->setWins(0);
		cout << "DEALER HAS 5-UNDER!!!" << endl << endl << "Result: LOSS" << endl << endl;
	}
	else if ((Player->getSum()>21)||(Dealer->getSum()>Player->getSum()))
	{
		Player->setTotal((-1)*bet);
		Dealer->setTotal(bet);
		Player->setWins(1);
		Dealer->setWins(0);
		if (Player->getSum()>21)
		{
			cout << "PLAYER has gone BUST" << endl << endl << "Result: LOSS" << endl << endl;
		}
		else
		{
			cout << "DEALER has a BETTER HAND than the PLAYER ( " << Dealer->getSum() << " VS " << Player->getSum() << " )" << endl << endl << "Result: LOSS" << endl << endl;
		}
	}
	else if (Dealer->getSum()==Player->getSum())
	{
		Player->setWins(2);
		Dealer->setWins(2);
		cout << "DEALER and PLAYER have the same HAND SUM" << endl << endl << "Result: PUSH" << endl << endl;
	}
	else if (Dealer->getSum()<Player->getSum())
	{
		Player->setTotal(bet);
		Dealer->setTotal((-1)*bet);
		Player->setWins(0);
		Dealer->setWins(1);
		cout << "PLAYER has a BETTER HAND than the DEALER ( " << Dealer->getSum() << " VS " << Player->getSum() << " )" << endl << endl << "Result: WIN" << endl << endl;
	}
}



double Controller::mainBlackJack(string input)
{
	dealer* Dealer=new dealer;

	playerBlackJack* Player=new playerBlackJack(input);

	int bet=0;

	int gamenum=1;

    double result=0;

	cout << endl << endl << "\e[1m" << "        BLACKJACK!!        " << "\e[0m" << endl << endl;
    usleep(3000000);

    cout << endl;

	while (gamenum<=10)
	{
		cout << endl << endl << endl << endl << flush;
        usleep(1250000);
        cout << "---------------------------" << endl;
        cout << "      Game Number: " << gamenum << endl;
        cout << "---------------------------" << endl;
        cout << endl << endl << endl << endl << flush;
        usleep(1250000);

		cout << endl << endl;
		cout << "DEALER'S CURRENT AMOUNT OF MONEY: $" << Dealer->getTotal() << endl << endl;
		cout << "PLAYER'S CURRENT AMOUNT OF MONEY: $" << Player->getTotal() << endl << endl;
		cout << "NUMBER OF PLAYER WINS: " << Player->getWins(0) << endl;
		cout << "NUMBER OF PUSHES (DRAWS): " << Player->getWins(2) << endl;
		cout << "NUMBER OF PLAYER LOSES: " << Player->getWins(0) << endl << endl;
		cout << "Bets in ( How much are you going to bet? ): " << endl;
		cin >> bet;

		//fix up
		while ((bet<=0||bet>Player->getTotal())||(cin.fail()==true))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, Please Try Again: ";
            cin >> bet;
            if ((!cin.fail())&&(bet>0&&bet<=Player->getTotal()))
            {
                break;
            }
        }

		int jackCheck=initial(Player,Dealer,bet);

		if (jackCheck==0)
		{
			playersTurn(Player,Dealer,bet);

			if (Player->getSum()<=21)
			{
				dealersTurn(Dealer,Player);
				results(Player,Dealer,bet);
			}
			else
			{
				Player->setTotal((-1)*bet);
				Dealer->setTotal(bet);
				Player->setWins(1);
				Dealer->setWins(0);
				cout << "PLAYER has gone BUST" << endl << endl << "Result: LOSS" << endl << endl;
			}
		}

		usleep(1250000);

		// if (Player->getTotal()>1000)
		// {
		// 	cout << "CONGRATS!!!!!" << endl << endl << "Onto the next Section....->" << endl << endl;
		// 	break;
		// }
		// else if (Player->getTotal()==1000)
		// {
		// 	cout << "I'VE TRIED SO HARD, AND GOT SO FARRRR, BUT IN THE END IT DOES'NOT EVEN MATTEEEERRRR" << endl << endl;
		// }
		// else
		// {
		// 	cout << "If You Wish to ESCAPE, you must continue FORTH.....";
		// }

		if (Player->getTotal()<=0)
		{
			cout << "You have FAILED this trial...... GOODBYE WEAKLING!" << endl;
			return result;
		}

		Player->resetHand();
		Dealer->resetHand();

		if (Dealer->getTotalCards()<10)
		{
			Dealer->resetDeck();
			cout << "LOW AMOUNT OF CARDS REMAINING!!! DECK HAS BEEN RE-SHUFFLED" << endl << endl;
		}

        if (gamenum==5&&Player->getTotal()>=2100)
        {
            result=1.5;
        }

		gamenum++;
	}

    if (Player->getTotal()>3000)
    {
        if ((gamenum==10&&Player->getTotal()>=12000)&&result==1.5)
        {
            result=1.5;
        }
        else
        {
            result=1;
        }
        cout << endl << "Oh wow, amazing job kiddo really, You have outdone yourself here. Pity since this the END OF EASY MODE HAHAHAHAHAH. Better Prepare yOURSELF for the..." << endl << endl << endl;
    }
    else
    {
        result=0;
        cout << endl << "Really Screwed the Pooch here Huh, Well";
    }

	free(Dealer);
	free(Player);

    return result;
}

double Controller::mainPoke(string input)
{
    Player *player1 = new Player();
    Enemy* steven = new Enemy(1);
    Battle *battle;
    Steven steve;
    Turns turner;

    battle = &steve;

    player1->Name(input);
    player1->AssignParty();
    steven->AssignParty();
    steven->Name("Steven");

    double results=0;;
    
    results=turner.turn(player1,steven,battle);

    free(player1);
    free(steven);

    return results;
}
