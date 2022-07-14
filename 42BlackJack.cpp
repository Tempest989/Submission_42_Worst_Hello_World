#include <iostream>
#include <cmath>
#include <time.h>
#include <unistd.h>
#include <limits>
#include "dealer.h"
#include "playerBlackJack.h"
using namespace std;

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

// NEED TO ADD IN BLACKJACK FUNCTION FOR NORMAL DEAL PHASE AFTER SPLIT, USE LIMIT RESTRICTION AS A PARAMETER FOR IF STATEMENTS->
int main()
{
	srand(time(NULL));

	dealer* Dealer=new dealer;
    
    string input=" ";

    cout << "What is Your Name?: ";
    cin >> input;

	playerBlackJack* Player=new playerBlackJack(input);

	int bet=0;

	int gamenum=1;

	cout << endl << endl << "\e[1m" << "        BLACKJACK!!        " << "\e[0m" << endl << endl;

	cout << "What Would You Like Your Starting Total Amount of Money to be?: ";
	cin >> bet;

	while ((bet<=0)||(cin.fail()==true))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, Please Try Again: ";
        cin >> bet;
        if ((!cin.fail())&&(bet>0))
        {
            break;
        }
    }

    Player->setTotal(bet);

    cout << endl << "What Would You Like the Dealers Starting Total Amount of Money to be?: ";
	cin >> bet;

	while ((bet<=0)||(cin.fail()==true))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, Please Try Again: ";
        cin >> bet;
        if ((!cin.fail())&&(bet>0))
        {
            break;
        }
    }

    Dealer->setTotal(bet);
    cout << endl;
    bet=0;

	while (true)
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
		cout << "Bets in ( How much are you going to bet? 0 = exit game): " << endl;
		cin >> bet;

		//fix up
		while ((bet<0||bet>Player->getTotal())||(cin.fail()==true))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, Please Try Again: ";
            cin >> bet;
            if ((!cin.fail())&&(bet>=0&&bet<=Player->getTotal()))
            {
                break;
            }
        }

        if (bet==0)
        {
            break;
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
			return 1;
		}

		Player->resetHand();
		Dealer->resetHand();

		if (Dealer->getTotalCards()<10)
		{
			Dealer->resetDeck();
			cout << "LOW AMOUNT OF CARDS REMAINING!!! DECK HAS BEEN RE-SHUFFLED" << endl << endl;
		}

		gamenum++;
	}

    cout << "Hello World!" << endl << endl;

	free(Dealer);
	free(Player);

	return 0;
}
