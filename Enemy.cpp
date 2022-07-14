#include <iostream>
#include "Pokemon.h"
#include "Enemy.h"
#include "Person.h"
#include <string>
#include <ctime>
using namespace std;

Enemy::Enemy()
{   //initialising some variables
    name= "";
    ID = 0;
    for (int i=0;i<2;i++)
    {
        itemUse[i]=3;
    }
}

Enemy::Enemy(int num)
{
    ID = num;
    for (int i=0;i<2;i++)
    {
        itemUse[i]=1;
    }
   // srand(time(NULL));
   // current = rand()%6;

    // /*if (num==1)
    // {
    //     name
    //     //first enemy
    //     /* STEVEN
    //           team: Metagross, Aggron, Armaldo, Skarmory, Claydol, Cradily
    // }
    // else if (num==2)
    // {
    //     //second
    //     /* DRAKE
    //         team: Salamence, Haxorus, Flygon, Kingdra, Altaria, Dragalge
    // }
    // else if (num==3)
    // {
    //     //third
    //     /* CYNTHIA
    //         team: Garchomp, Spiritomb, Roserade, Togekiss, Milotic, Lucario
    // }
    // else if (num==4)
    // {
    //     //fourth
    //     /* RED:
    //          team: Charizard, Blastoise, Venosaur, Pikachu, Snorlax, Machamp
    // }
    // else if (num==5)
    // {
    //     //champion youngster joey
    //     /*Gen 1: Mewtwo

    //     Gen 2: Lugia

    //     Gen 3: Mega Rayquaza (Without a doubt the most powerful Pokémon to exist)

    //     Gen 4: Arceus

    //     Gen 5: White Kyurem (It learns more moves to accommodate its high special attack stat, but if you want a Physical attacker, Black Kyurem would serve you well,)

    //     Gen 6: Complete Forme Zygarde
    // }
    // else if (num==6)
    // {
    //     //if type, should be ash with some bs stuff
    // }*/
}

void Enemy::Name(string input)
{   //switch statement for each opponent trainer

    name=input;
//    switch (ID)
//    {
//        case 1:
//        {
//            name = "Steven";
//            break;
//        }
//        case 69:
//        {
//            name = "Tester";
//            break;
//        }
        // case 2:
        // {
        //     name = "Drake";
        //     break;
        // }
        // case 3:
        // {
        //     name = "Cynthia";
        //     break;
        // }
        // case 4:
        // {
        //     name = "Red";
        //     break;
        // }
        //case 5:
        //{
        //   name = "Youngster Joey";
        //}
}

void Enemy::AssignParty()
{
    switch (ID)
    { //switch statement to assign pokemon party for each opponent trainer
        case 1:
        {
            Pokemon temp;

            for (int i=0;i<6;i++)
            {
                party[i]=Pokemon(111+i);
            }
            int random=0;
            for (int i=0;i<6;i++)
            {
                if ((5-i)==0)
                {
                    random=i;
                }
                else
                {                
                    random=rand()%(5-i)+i;
                }
                temp=party[i];
                party[i]=party[random];
                party[random]=temp;
            }

            break;
        }
        case 69:
        {
            for (int i=0;i<6;i++)
            {
                party[i]=Pokemon(6);
            }
            break;
        }
        // case 2:
        // {
        //     for (int i=0;i<6;i++)
        //     {
        //         party[i]=Pokemon(211+i);
        //     }
        //     break;
        // }
        // case 3:
        // {
        //     for (int i=0;i<6;i++)
        //     {
        //         party[i]=Pokemon(311+i);
        //     }
        //     break;
        // }
        // case 4:
        // {
        //     for (int i=0;i<6;i++)
        //     {
        //         party[i]=Pokemon(411+i);
        //     }
        //     break;
        // }
        //case 5:
        //{
           // for (int i=0;i<6;i++)
            //{
             //   party[i]=Pokemon(511+i);
           // }
       // }
    }
}

void Enemy::setItemUse(int i, int change, string operation)
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
int Enemy::getItemUse(int i)
{
    return itemUse[i];
}
