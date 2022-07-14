#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Player::Player()
{
    current = 0;
    //Pokemon ditto(3);
    //dittoOG=&ditto;
    itemUse[0]=3; itemUse[1]=3; itemUse[2]=10; itemUse[3]=5; itemUse[4]=10; itemUse[5]=10;
    itemDescript[0]="Fully Restores HP and Heals all Status conditions of the target Pokemon.";
    itemDescript[1]="Restores 200 HP of the target Pokemon.";
    itemDescript[2]="Heals all Status conditions of the target Pokemon.";
    itemDescript[3]="Revives the target Pokemon at 1/2 of their MAX HP, does NOT restore any PP of their Moves.";
    itemDescript[4]="Restores PP of chosen Move of the target Pokemon to MAX PP.";
    itemDescript[5]="Increases the target Pokemon's ATK, DEF, SP.ATK, SP.DEF and SPD by 1 Stage.";
    item[0]="Full Restore";
    item[1]="Hyper Potion";
    item[2]="Full Heal";
    item[3]="Revive";
    item[4]="PP++";
    item[5]="X-Up";
    name="";
}

void Player::Name(string input)
{
    name=input;
}

void Player::AssignParty()
{
    srand(time(NULL));
    int choice1;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
    int choice6;
    if (name == "Tyson")
    {
        int poke=0;
        for (int i=0;i<6;i++)
        {
            cout << "POKE Number?: ";
            cin >> poke;
            while ((poke<0||poke>6)&&poke==3)
            {
                cout << "Try Again: ";
                cin >> poke;
            }

            party[i]=Pokemon(poke);
        }
    }
    else if (name == "Maxwell")
    {
        int poke=0;
        for (int i=0;i<6;i++)
        {
            cout << "POKE Number?: ";
            cin >> poke;
            while ((poke<0||poke>6)&&poke==3)
            {
                cout << "Try Again: ";
                cin >> poke;
            }

            party[i]=Pokemon(poke);
        }
    }
    else if (name == "Darcy")
    {
        int poke=0;
        for (int i=0;i<6;i++)
        {
            cout << "POKE Number?: ";
            cin >> poke;
            while ((poke<0||poke>6)&&poke==3)
            {
                cout << "Try Again: ";
                cin >> poke;
            }

            party[i]=Pokemon(poke);
        }
    }
    else if (name == "TestMAN")
    {
        party[0]=Pokemon(6);
        for (int i=1;i<6;i++)
        {
            party[i]=Pokemon();
        }
        cout << "TestMAN is here!!" << endl;
    }
    else
    {
        // int randomiserFixer[6]={0,0,0,0,0,0};
        // int counter=0;
        // for (int i=0;i<6;i++)
        // {
        //     while (counter>=0)
        //     {
        //         choice = rand()%6+1;
        //         counter=0;
        //         for (int j=0;j<6;j++)
        //         {
        //             if ((randomiserFixer[j]==choice)||(randomiserFixer[j]==69&&choice==6))
        //             {
        //                 counter++;
        //             }
        //         }

        //         if (counter<2)
        //         {
        //             break;
        //         }
        //     }

        //     if (choice==6)
        //     {
        //         choice=69;
        //     }

        //     party[i]=Pokemon(choice);
        //     randomiserFixer[i]=choice;
        // }

        int randomiser[6]={0,0,0,0,0,0};
        for (int i=0;i<6;i++)
        {
            randomiser[i]=rand()%10+2;
            for (int j=0;j<6;j++)
            {
                if (randomiser[j]==randomiser[i]&&i!=j)
                {
                    i--;
                }
             }
        }
//        choice1=rand()%6+1;
//        if (choice1==6)
//        {
//            choice1=69;
//        }
//
//        choice2=rand()%6+1;
//        if (choice2==6)
//        {
//            choice2=69;
//        }
//
//        choice3=rand()%6+1;
//        if (choice3==6)
//        {
//            choice3=69;
//        }
//
//        choice4=rand()%6+1;
//        if (choice4==6)
//        {
//            choice4=69;
//        }
//
//        choice5=rand()%6+1;
//        if (choice5==6)
//        {
//            choice5=69;
//        }
//
//        choice6=rand()%6+1;
//        if (choice6==6)
//        {
//            choice6=69;
//        }

        party[0]=Pokemon(randomiser[0]);
        party[1]=Pokemon(randomiser[1]);
        party[2]=Pokemon(randomiser[2]);
        party[3]=Pokemon(randomiser[3]);
        party[4]=Pokemon(randomiser[4]);
        party[5]=Pokemon(randomiser[5]);
    }
}

void Player::setItemUse(int i,int change,string operation)
{
    if (operation=="+")
    {
        itemUse[i]+=change;
    }
    else if (operation=="-")
    {
        itemUse[i]-=change;
    }
    else if (operation=="=")
    {
        itemUse[i]=change;
    }
}
int Player::getItemUse(int i)
{
    return itemUse[i];
}
