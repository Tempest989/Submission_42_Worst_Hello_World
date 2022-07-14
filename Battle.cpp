#include "Battle.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <limits>

using namespace std;


Battle::Battle()
{
    //weatherCondition="None";
    playerSpikes=0;
    enemySpikes=0;
    playerReflect=0;
    enemyReflect=0;
    playerLightScreen=0;
    enemyLightScreen=0;
}

int Battle::enemySwitch(Player* player, Enemy* enemy)
{
        // if (counter!=6)
        // {
        //     for (int i=0;i<6;i++)
        //     {
        //         if (enemy->getParty(i)->getCurrent(0)>0)
        //         {
        //             for (int j =0; j<6;j++)
        //             {
        //                 enemy->getParty(i)->setStatMultiplier(j,0,"=");
        //             }
        //             enemy->getParty(i)->setCondition(1,"Not Confused");
        //             enemy->getParty(i)->setConditionCool(1,0,"=");
        //             enemy->getParty(i)->setBadCounter(0,"=");
        //             enemy->getParty(i)->setTurnCount(0,"=");

        //             cout << "Enemy " << enemy->getName() << " has SWITCHED OUT " << enemy->getParty(enemy->getCurrent())->getPokeName() << " for ";
        //             enemy->setCurrent(i);
        //             cout << enemy->getParty(enemy->getCurrent())->getPokeName() << endl;
        //             return 1;
        //         }
        //     }
        // }
     
//    //check player pokemons weakness to slected enemy move
//    for (int i=0;i<player->getParty(player->getCurrent())->getTypeNum();i++)
//    {
//        weak += weakness(enemy->getParty(enemy->getCurrent())->getTypeNum(),enemy->getParty(enemy->getCurrent())->getTypes(),player->getParty(player->getCurrent())->getType(i));
//    }
//    //check enemy AI pokemon weakness to slected player move
//    for (int i=0;i<enemy->getParty(enemy->getCurrent())->getTypeNum();i++)
//    {
//        for (int j=0;j<player->getParty(player->getCurrent())->getTypeNum();j++)
//        {
//            if ((enemy->getParty(enemy->getCurrent())->getType(i)==player->getParty(player->getCurrent())->getType(j))&&(enemy->getParty(enemy->getCurrent())->getType(i)=="Dragon"||enemy->getParty(enemy->getCurrent())->getType(i)=="Ghost")&&(weak>=2.0))
//            {
//                //check if has super effective move against
//                for (int k=0;k<4;k++)
//                {
//                    if (enemy->getParty(enemy->getCurrent())->getMoves(k)->getMoveType()!="Status")
//                    {
//                        double check = weakness(player->getParty(player->getCurrent())->getTypeNum(),player->getParty(player->getCurrent())->getTypes(),enemy->getParty(enemy->getCurrent())->getMoves(k)->getMoveEle());
//
//                        if (check>=2.0)
//                        {
//                            typecounter=1;
//                            return 1;
//                        }
//                    }
//                }
//
//            }
//        }
//    }

    double weak=1.0;
    for (int i=0;i<player->getParty(player->getCurrent())->getTypeNum();i++)
    {
        weak *= weakness(enemy->getParty(enemy->getCurrent())->getTypeNum(), enemy->getParty(enemy->getCurrent())->getTypes(),player->getParty(player->getCurrent())->getType(i));
    }

    if (weak>=2.0&&enemy->getParty(enemy->getCurrent())->getCurrent(0)<=((6.0/10.0)*enemy->getParty(enemy->getCurrent())->getBase(0)))
    {
        for (int i=0;i<5;i++)
        {
            weak=1.0;
            if (i==enemy->getCurrent())
            {
                i++;
            }

            for (int j=0;i<player->getParty(player->getCurrent())->getTypeNum();i++)
            {
                weak *= weakness(enemy->getParty(i)->getTypeNum(), enemy->getParty(i)->getTypes(),player->getParty(player->getCurrent())->getType(j));
            }
            
            if (weak<=1.0&&enemy->getParty(i)->getCurrent(0)>=((7.0/10.0)*enemy->getParty(i)->getBase(0)))  //swap in here
            {
                for (int j =0; j<6;j++)
                {                                       //removing confused and resetting counters when player switches pokemon
                    enemy->getParty(enemy->getCurrent())->setStatMultiplier(j,0,"=");
                }
                enemy->getParty(enemy->getCurrent())->setCondition(1,"Not Confused");
                enemy->getParty(enemy->getCurrent())->setConditionCool(1,0,"=");
                enemy->getParty(enemy->getCurrent())->setBadCounter(0,"=");
                enemy->getParty(enemy->getCurrent())->setTurnCount(0,"=");
                enemy->getParty(enemy->getCurrent())->setProtect(0);
                enemy->getParty(enemy->getCurrent())->setOutrage(0);
                enemy->getParty(enemy->getCurrent())->setFlinched(0);

                cout << "Enemy's " << enemy->getParty(enemy->getCurrent())->getPokeName() << " has SWITCHED OUT for ";
                enemy->setCurrent(i);
                cout << enemy->getParty(enemy->getCurrent())->getPokeName() << endl;
                return -1;
            }
        }
    }

    if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
    {
        int counter=0;
        for (int i=0;i<6;i++)
        {
            // if (enemy->getParty(i)->getCurrent(0)>((1/2)*enemy->getParty(i)->getBase(0)))
            // {
            //     for (int j =0; j<6;j++)
            //     {
            //         enemy->getParty(i)->setStatMultiplier(j,0,"=");
            //     }
            //     enemy->getParty(i)->setCondition(1,"Not Confused");
            //     enemy->getParty(i)->setConditionCool(1,0,"=");
            //     enemy->getParty(i)->setBadCounter(0,"=");
            //     enemy->getParty(i)->setTurnCount(0,"=");

            //     cout << "Enemy " << enemy->getName() << " has SWITCHED OUT " << enemy->getParty(enemy->getCurrent())->getPokeName() << " for ";
            //     enemy->setCurrent(i);
            //     cout << enemy->getParty(enemy->getCurrent())->getPokeName() << endl;
            //     return 1;
            // }
            if (enemy->getParty(i)->getCurrent(0)<=0)
            {
                counter++;
            }
            else if (enemy->getParty(i)->getCurrent(0)>0)
            {
                for (int j =0; j<6;j++)
                {                                       //removing confused and resetting counters when player switches pokemon
                    enemy->getParty(enemy->getCurrent())->setStatMultiplier(j,0,"=");
                }
                enemy->getParty(enemy->getCurrent())->setCondition(1,"Not Confused");
                enemy->getParty(enemy->getCurrent())->setConditionCool(1,0,"=");
                enemy->getParty(enemy->getCurrent())->setBadCounter(0,"=");
                enemy->getParty(enemy->getCurrent())->setTurnCount(0,"=");
                enemy->getParty(enemy->getCurrent())->setProtect(0);
                enemy->getParty(enemy->getCurrent())->setOutrage(0);

                cout << "Enemy's " << enemy->getParty(enemy->getCurrent())->getPokeName() << " has SWITCHED OUT for ";
                enemy->setCurrent(i);
                cout << enemy->getParty(enemy->getCurrent())->getPokeName() << endl;
                return -1;
            }
        }
        
           if (counter==6)
        {
            return -10;
        }

    }
    
    return 1;
//
//    if (weakness(enemy->getParty(enemy->getCurrent())->getTypeNum(), enemy->getParty(enemy->getCurrent())->getTypes(),player->getParty(player->getCurrent())->getType(0)
//
//
//    if (((weak>=2.0)&&(enemy->getParty(enemy->getCurrent())->getCurrent(0)>((1/4)*(enemy->getParty(enemy->getCurrent())->getBase(0)))))||enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
//    {
//        double weakCheck[6]={0,0,0,0,0,0};
//        int max=0;
//        int maxCheck;
//        while (maxCheck>0)
//        {
//            maxCheck=6;
//            for (int j=0;j<6;j++)
//            {
//                if (weakCheck[j]==-1)
//                {
//                    maxCheck--;
//                }
//                for (int i=0;i<player->getParty(player->getCurrent())->getTypeNum();i++)
//                {
//                    if (j!=enemy->getCurrent()&&weakCheck[j]!=-1)
//                    {
//                       weakCheck[j] *= weakness(enemy->getParty(enemy->getCurrent())->getTypeNum(),enemy->getParty(j)->getTypes(),player->getParty(player->getCurrent())->getType(i));
//                    }
//                }
//
//                if (weakCheck[max]<weakCheck[j]&&enemy->getParty(j)->getCurrent(0)>0)
//                {
//                    max=j;
//                }
//            }
//
//            if (max!=enemy->getCurrent()&&enemy->getParty(max)->getCurrent(0)>0)
//            {
//                for (int i =0; i<6;i++)
//                {
//                    enemy->getParty(max)->setStatMultiplier(i,0,"=");
//                }
//                enemy->getParty(max)->setCondition(1,"Not Confused");
//                enemy->getParty(max)->setConditionCool(1,0,"=");
//                enemy->getParty(max)->setBadCounter(0,"=");
//                enemy->getParty(max)->setTurnCount(0,"=");
//
//                cout << "Enemy " << enemy->getName() << " has SWITCHED OUT " << enemy->getParty(enemy->getCurrent())->getPokeName() << " for ";
//                enemy->setCurrent(max);
//                cout << enemy->getParty(enemy->getCurrent())->getPokeName() << "." << endl;
//
//                return -1;
//            }
//            else if (enemy->getParty(max)->getCurrent(0)<=0)
//            {
//                weakCheck[max]=-1;
//            }
//        }
//    }
    //checking which pokemon has highest hp (enemy AI)
//    if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
//    {
//        int hp=0;
//        for (int i=0;i<6;i++)
//        {
//            if (enemy->getParty(i)->getCurrent(0)>enemy->getParty(hp)->getCurrent(0))
//            {
//                hp=i;
//            }
//        }
//        //on switch out resetting certain counters and remving confusion and stat buffs
//        for (int i =0; i<6;i++)
//        {
//            enemy->getParty(hp)->setStatMultiplier(i,0,"=");
//        }
//        enemy->getParty(hp)->setCondition(1,"Not Confused");
//        enemy->getParty(hp)->setConditionCool(1,0,"=");
//        enemy->getParty(hp)->setBadCounter(0,"=");
//        enemy->getParty(hp)->setTurnCount(0,"=");
//
//        cout << "Enemy " << enemy->getName() << " has SWITCHED OUT " << enemy->getParty(enemy->getCurrent())->getPokeName() << " for ";
//        enemy->setCurrent(hp);
//        cout << enemy->getParty(enemy->getCurrent())->getPokeName() << endl;
//        return -1;
//    }
//
}

int Battle::playerBattle(Player* player)
{
    int choice; //displaying player current pokemons moves
    cout << "---------------MOVESET---------------" << endl;
    for (int i=0;i<4;i++)
    {
        if (i != 3){
            cout << i << " = " << player->getParty(player->getCurrent())->getMoves(i)->getMoveName() << ", TYPE = " << player->getParty(player->getCurrent())->getMoves(i)->getMoveEle() <<", PP =" << player->getParty(player->getCurrent())->getMoves(i)->getMovePP() << endl << endl;
        } else {
            cout << i << " = " << player->getParty(player->getCurrent())->getMoves(i)->getMoveName() << ", TYPE = " << player->getParty(player->getCurrent())->getMoves(i)->getMoveEle() <<", PP =" << player->getParty(player->getCurrent())->getMoves(i)->getMovePP() << endl;
        }
    }
    cout << "-------------------------------------" << endl;
    cout << "What MOVE should " << player->getParty(player->getCurrent())->getPokeName() << " use? ";
    cin >> choice;

    while ((choice<-1||choice>3)||(cin.fail()==true))   //preventing user from entering invalid inputs
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please Try again: (1 = Attack, 2 = Use Item, 3 = Switch) ";
        cin >> choice;
        if ((!cin.fail())&&(choice>=-1&&choice<=3))
        {
            break;
        }
    }
    cout << endl;

    if (choice==-1)
    {
        return -1;
    }

    /*if (getParty[current]->movePP[choice]>0&&getParty[current]->getMoveType()=="Physical")
    {
        playerPhysical();
    }
    else if (getParty[current]->movePP[choice]>0&&getParty[current]->getMoveType()=="Special")
    {
        playerSpecial();
    }
    else if (getParty[current]->movePP[choice]>0&&getParty[current]->getMoveType()=="Status")
    {
        playerStatus();
    }
    */

    while (player->getParty(player->getCurrent())->getMoves(choice)->getMovePP()<=0) //preventing user from picking a move with no PP remaining
    {
        cout << "Not enough POWER POINTS to use this move, please try again: " << endl;
        cin >> choice;
        while ((choice!=-1&&choice!=0&&choice!=1&&choice!=2&&choice!=3)||(cin.fail()==true))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please Try again: (1 = Attack, 2 = Use Item, 3 = Switch) ";
            cin >> choice;
            if ((!cin.fail())&&(choice>=-1&&choice<=3))
            {
                break;
            }
        }
        if (choice==-1)
        {
            return -1;
        }
    }

    return choice;
}

int Battle::playerItem(Player* player)
{
    cout << endl << endl << "NOPE, Have FUN Its HARDCORE NUZLOCKE TIME!!!!!!" << endl << endl;
    return 0;

    /* PROPER ITEM MENU DISPLAY, UNCOMMENT AND IT SHOULD WORK (SOME OF THE ITEMS MIGHT NOT THOUGH, MOST SHOULD HOPEFULLY)*/
//    int choice;
//    int choicePoke=-1;
//    double check=1;
//    int pp;
//    int pokeStat=1;
//    //player item usage
//    while (choicePoke==-1)
//    {
//        cout << "-----------------Items-------------------------" << endl;
//        for (int i=0;i<6;i++)
//        {
//            cout << i << " = " << player->getItem(i) << ":" << endl << "Description: " << player->getItemDescript(i) << endl;
//        }
//        cout << "-----------------------------------------------" << endl;
//
//        //print out items, basic effect & how many are left->
//        cout << "Which ITEM would you like to use?: ";
//        cin >> choice;
//
//        while ((choice!=2&&choice!=1&&choice!=-1&&choice!=3&&choice!=4&&choice!=5&&choice!=0)||(cin.fail()==true))
//        {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(),'\n');
//            cout << "Please Try again: ";
//            cin >> choice;
//            if ((!cin.fail())&&(choice>=-1&&choice<=5))
//            {
//                break;
//            }
//        }
//        //preventing user from using items which do no have any stored
//        while ((player->getItemUse(choice)<=0)&&(choice!=-1))
//        {
//            cout << "ITEM out of stock, Please try again: ";
//            cin >> choice;
//            while ((choice!=2&&choice!=1&&choice!=-1&&choice!=3&&choice!=4&&choice!=5&&choice!=0)||(cin.fail()==true))
//            {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                cout << "Please Try again: ";
//                cin >> choice;
//                if ((!cin.fail())&&(choice>=-1&&choice<=5))
//                {
//                    break;
//                }
//            }
//        }
//
//        if (choice==-1)
//        {
//            return 0;
//        }
//        else
//        {   //viewing pokemon player stats
//            while (choice>-1&&choicePoke==-1)
//            {
//                while (pokeStat!=0)
//                {
//                    for (int i=0;i<6;i++)
//                    {
//                        cout << i << " = " << player->getParty(i)->getPokeName() << ", HP: " << player->getParty(i)->getCurrent(0) << "/" << player->getParty(i)->getBase(0) << endl;
//                    }
//
//                    cout << "Which POKEMON STATS would you like to fully view? ";
//                    cin >> pokeStat;
//
//                    while ((pokeStat!=1&&pokeStat!=2&&pokeStat!=3&&pokeStat!=4&&pokeStat!=0&&pokeStat!=5&&pokeStat!=-1)||(cin.fail()==true))
//                    {
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                        cout << "Please Try again: ";
//                        cin >> pokeStat;
//                        if ((!cin.fail())&&(pokeStat>=-1&&pokeStat<=5))
//                        {
//                            break;
//                        }
//                    }
//                    if (pokeStat==-1)
//                    {
//                        break; // check if this works
//                    }
//
//                    if (player->getParty(pokeStat)->getTypeNum()==2)
//                    {
//                        cout << "Types: " << player->getParty(pokeStat)->getType(0) << " & " << player->getParty(pokeStat)->getType(1) << endl;
//                    }
//                    else
//                    cout << "Type: " << player->getParty(pokeStat)->getType(0) << endl;
//
//                    cout << endl << player->getParty(pokeStat)->getPokeName() << "'s Moveset: " << endl;
//
//                    for (int i=0;i<4;i++)
//                    {
//                        cout << player->getParty(pokeStat)->getMoves(i)->getMoveEle() << " Type Move: " << player->getParty(pokeStat)->getMoves(i)->getMoveName() << endl;
//                        cout << "Power = " << player->getParty(pokeStat)->getMoves(i)->getMovePow() << " , Accuracy = " << player->getParty(pokeStat)->getMoves(i)->getMoveAcc();
//                        cout << " , Impact Type: " << player->getParty(pokeStat)->getMoves(i)->getMoveType() << " , PP: " << player->getParty(pokeStat)->getMoves(i)->getMovePP() << " / " << player->getParty(pokeStat)->getMoves(i)->getOr_MovePP() << endl;
//                        cout << "Move Description: " << player->getParty(pokeStat)->getMoves(i)->getMoveDescript() << endl << endl;
//                    }
//
//                    cout << "HP: " << player->getParty(pokeStat)->getBase(0) << endl;
//                    cout << "ATK: " << player->getParty(pokeStat)->getBase(1) << endl;
//                    cout << "DEF: " << player->getParty(pokeStat)->getBase(2) << endl;
//                    cout << "SP->ATK: " << player->getParty(pokeStat)->getBase(3) << endl;
//                    cout << "SP->DEF: " << player->getParty(pokeStat)->getBase(4) << endl;
//                    cout << "SPD: " << player->getParty(pokeStat)->getBase(5) << endl;
//
//                    cout << "Ability: " << player->getParty(pokeStat)->getAbility() << endl;
//                    cout << "Description: " << player->getParty(pokeStat)->getAbilityDescript() << endl << endl;
//
//                    //cout << "Held Item: " << player->getParty(pokeStat)->item << endl;
//                    //need to add item descriptions/effects etc
//
//                    //add item description once its added (if, probs though)
//
//                    cout << "Would you like to view another Pokemon's Stats?: (0 = No, 1 = Yes) ";
//                    cin >> pokeStat;
//                    while ((pokeStat!=0&&pokeStat!=1)||(cin.fail()==true))
//                    {
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                        cout << "Please Try again: ";
//                        cin >> choice;
//                        if ((!cin.fail())&&(pokeStat>=0&&pokeStat<=1))
//                        {
//                            break;
//                        }
//                    }
//                    //ask which pokemon stat they want to view, view it etc etc
//                    // then return to top, maybe make whole thing in while loop using choice for switch or back as breaks/returns?
//                }
//                    //using an item on allied pokemon
//                cout << "Which pokemon would you like to use this item on?: ";
//                cin >> choicePoke;
//                while ((choicePoke<-1||choicePoke>5)||(cin.fail()==true))
//                {
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                    cout << "Please Try again: ";                                   //preventing invalid inputs
//                    cin >> choicePoke;
//                    if ((!cin.fail())&&(choicePoke>=-1&&choicePoke<=5))
//                    {
//                        break;
//                    }
//                }
//
//                for (int i=0;i<5;i++)
//                {
//                    if (player->getParty(choicePoke)->getStatMultiplier(i)==6.0)
//                    {
//                        check -= 0.2;
//                    }
//                }
//
//                while (choice==5)   //using exlirs on allied pokemon
//                {
//                    cout << "What move would you like to restore the PP of?: ";
//                    cin >> pp;
//                    while ((pp!=1&&pp!=2&&pp!=3&&pp!=4&&pp!=-1)||(cin.fail()==true))
//                    {
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                        cout << "Please Try again: ";
//                        cin >> pp;
//                        if ((!cin.fail())&&((pp>=1&&pp<=4)||pp==-1))
//                        {
//                            break;
//                        }
//                    }
//                    if (pp!=-1)
//                    {
//                        while (player->getParty(choicePoke)->getMoves(pp)->getMovePP()==player->getParty(choicePoke)->getMoves(pp)->getOr_MovePP())
//                        {
//                            cout << player->getParty(choicePoke)->getMoves(pp)->getMoveName() << "'s PP is at maximum, Please choose another move or change Pokemon: ";
//                            cin >> pp;
//                            while ((pp!=1&&pp!=2&&pp!=3&&pp!=4&&pp!=-1)||(cin.fail()==true))
//                            {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                                cout << "Please Try again: ";
//                                cin >> pp;
//                                if ((!cin.fail())&&((pp>=1&&pp<=4)||pp==-1))
//                                {
//                                    break;
//                                }
//                            }
//                            if (pp==-1)
//                            {
//                                break;
//                            }
//                        }
//                    }
//
//                    if (pp==-1)
//                    {
//                        break;
//                    }
//                }
//
//                while (((choice==1||choice==2)&&((player->getParty(choicePoke)->getCurrent(0)==player->getParty(choicePoke)->getBase(0))||player->getParty(choicePoke)->getCurrent(0)<=0))||(choice==3&&(player->getParty(choicePoke)->getCondition(0)=="None"&&player->getParty(choicePoke)->getCondition(1)=="Not Confused"))||(choice==4&&player->getParty(choicePoke)->getCurrent(0)>0)||(choice==6&&(player->getParty(choicePoke)->getCurrent(0)<=0))||(choicePoke!=player->getCurrent())||(check==0))
//                {
//                    cout << "Will have no effect, Please choose a different Pokemon: "; //preventing invalid inputs
//                    cin >> choicePoke;
//                    while ((choicePoke!=2&&choicePoke!=1&&choicePoke!=-1&&choicePoke!=3&&choicePoke!=4&&choicePoke!=5&&choicePoke!=0)||(cin.fail()==true))
//                    {
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                        cout << "Please Try again: ";
//                        cin >> choice;
//                        if ((!cin.fail())&&(choicePoke>=-1&&choicePoke<=5))
//                        {
//                            break;
//                        }
//                    }
//                }
//
//                while ((choicePoke!=2&&choicePoke!=1&&choicePoke!=-1&&choicePoke!=3&&choicePoke!=4&&choicePoke!=5&&choicePoke!=0)||(cin.fail()==true))
//                {
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
//                    cout << "Please Try again: ";
//                    cin >> choicePoke;
//                    if ((!cin.fail())&&(choicePoke>=-1&&choicePoke<=5))
//                    {
//                        break;
//                    }
//                }
//                /* while (((choice==1||choice==2||choice==5)&&((player->getParty(choicePoke)->current[0]==player->getParty(choicePoke)->getBase(0))||player->getParty(choicePoke)->current[0]<=0))
//                {
//                    cout << "Will have no effect, Please choose a different Pokemon: ";
//                    cin >> choicePoke;
//                }
//
//                while (choice==3&&(player->getParty(choicePoke)->condition=="None"))
//                {
//                    cout << "Will have no effect, Please choose a different Pokemon: ";
//                    cin >> choicePoke;
//                }
//
//                while (choice==4&&(player->getParty(choicePoke)->current[0]>0))
//                {
//                    cout << "Will have no effect, Please choose a different Pokemon: ";
//                    cin >> choicePoke;
//                }
//
//                while (choice==6&&((player->getParty(choicePoke)->current[0]<=0)||(choicePoke!=player->current)||(check==0)))
//                {
//                    cout << "Will have no effect, Please choose a different Pokemon: ";
//                    cin >> choicePoke;
//                } */
//                //compare if item will have any effect (hp allowed, stats already maxed etc), will need multiply layered if statement->
//
//                if (choicePoke!=-1&&choice!=5)
//                {
//                    if (choice==1)
//                    {                               //restoring health and status when full restore is used
//                        //print full restore has been used->
//                        cout << "FULL RESTORE has been used on " << player->getParty(choicePoke)->getPokeName() << ", HP and STATUS conditions fully restored." << endl;
//                        player->getParty(choicePoke)->setCurrent(0,player->getParty(choicePoke)->getBase(0),"=");
//                        player->getParty(choicePoke)->setCondition(0,"None");
//                        player->getParty(choicePoke)->setCondition(1,"Not Confused");
//                        player->getParty(choicePoke)->setConditionCool(0,0,"=");
//                        player->getParty(choicePoke)->setConditionCool(1,0,"=");
//                        player->setItemUse(0,1,"-");
//                        return 1;
//                    }
//                    else if (choice==2)
//                    {           //restoring heath when hyper potion is used
//                        //print hyper potion has been used
//                        cout << "HYPER POTION has been used on " << player->getParty(choicePoke)->getPokeName() << ", HP has been restored by 200 points." << endl;
//                        player->getParty(choicePoke)->setCurrent(0,200,"+");
//                        if (player->getParty(choicePoke)->getCurrent(0)>player->getParty(choicePoke)->getBase(0))
//                        {
//                            player->getParty(choicePoke)->setCurrent(0,player->getParty(choicePoke)->getBase(0),"=");
//                        }
//                        player->setItemUse(1,1,"-");
//                        return 1;
//                    }
//                    else if (choice==3)
//                    {                       //removing status effects when full heal is used
//                        //print full heal has been used
//                        cout << "FULL HEAL has been used on " << player->getParty(choicePoke)->getPokeName() << ", STATUS conditions has been healed." << endl;
//                        player->getParty(choicePoke)->setCondition(0,"None");
//                        player->getParty(choicePoke)->setCondition(1,"Not Confused");
//                        player->getParty(choicePoke)->setConditionCool(0,0,"=");
//                        player->getParty(choicePoke)->setConditionCool(1,0,"=");
//                        player->setItemUse(2,1,"-");
//                        return 1;
//                    }
//                    else if (choice==4)
//                    {                        //reviving a pokemon when revive is used
//                        //print revive has been used
//                        cout << "REVIVE has been used on " << player->getParty(choicePoke)->getPokeName() << ", they can continue fighting!!" << endl;
//                        player->getParty(choicePoke)->setCurrent(0,(player->getParty(choicePoke)->getBase(0)/2),"+");
//                        player->setItemUse(3,1,"-");
//                        return 1;
//                    }
//                    else if (choice==6)
//                    {
//                        //print X-Up has been used
//                        cout << "X-UP has been used on " << player->getParty(choicePoke)->getPokeName() << ", all STATS have been getBuffed by 1 STAGE." << endl;
//                        for (int i=0;i<5;i++)
//                        {
//                            if (player->getParty(choicePoke)->getStatMultiplier(i)<6.0)
//                            {
//                                player->getParty(choicePoke)->setStatMultiplier(i,1,"+");
//                            }
//                        }
//                        player->setItemUse(5,1,"-");
//                        return 1;
//                    }
//                }
//                else if (choicePoke!=-1&&choice==5)
//                {
//                    //print PP++ has been used
//                    cout << "PP++ has been used on " << player->getParty(choicePoke)->getPokeName() << ", PP of " << player->getParty(choicePoke)->getMoves(pp)->getMoveName() << " has been fully restored." << endl;
//                    player->getParty(choicePoke)->getMoves(pp)->setMovePP(player->getParty(choicePoke)->getMoves(pp)->getOr_MovePP(),"=");
//                    player->setItemUse(4,1,"-");
//                    return 1;
//                }
//            }
//        }
//    }
//
//    return -69;
}



// need to fix so infinite switching from viewing stats to switching etc->

int Battle::playerSwitch(Player* player,Enemy* enemy)
{
    int choice;
    int pokeStat=1;
    int checker=0;

    for (int i=0;i<6;i++)
    {
        if (player->getParty(i)->getCurrent(0)<=0)
        {
            checker++;
        }

        if (checker==6)
        {
            return -10;
        }
    }
    
    cout << endl << endl;
    for (int i=0;i<6;i++)
    {
        cout << i << " = " << player->getParty(i)->getPokeName() << ", HP: " << player->getParty(i)->getCurrent(0) << "/" << player->getParty(i)->getBase(0) << endl;
    }
    cout << endl;

    //print out pokemon to swap to and brief stats (hp condition);
    cout << "Would you like to view a Pokemon's Stats?: (0 = No, 1 = Yes) ";
    cin >> choice;
    while ((choice!=0&&choice!=1)||(cin.fail()==true))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please Try again: ";
        cin >> choice;
        if ((!cin.fail())&&(choice>=0&&choice<=1))
        {
            break;
        }
    }

    if (choice==1)
    {
        while (pokeStat!=0)
        {
//            for (int i=0;i<6;i++)
//            {
//                cout << i << " = " << player->getParty(i)->getPokeName() << ", HP: " << player->getParty(i)->getCurrent(0) << "/" << player->getParty(i)->getBase(0) << endl;
//            }

            cout << "Which Pokemon stats would you like to view? (Enter the number) ";
            cin >> pokeStat;

            while ((pokeStat!=1&&pokeStat!=2&&pokeStat!=3&&pokeStat!=4&&pokeStat!=0&&pokeStat!=5)||(cin.fail()==true))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Please Try again: ";
                cin >> pokeStat;
                if ((!cin.fail())&&(pokeStat>=0&&pokeStat<=5))
                {
                    break;
                }
            }
            
            cout << endl << endl;
            if (player->getParty(pokeStat)->getTypeNum()==2)
            {
                cout << "Types: " << player->getParty(pokeStat)->getType(0) << " & " << player->getParty(pokeStat)->getType(1) << endl;
            }
            else
            cout << "Type: " << player->getParty(pokeStat)->getType(0) << endl;

            cout << endl << player->getParty(pokeStat)->getPokeName() << "'s Moveset: " << endl << endl;

            for (int i=0;i<4;i++)
            {
                cout << player->getParty(pokeStat)->getMoves(i)->getMoveEle() << " Type Move: " << player->getParty(pokeStat)->getMoves(i)->getMoveName() << endl;
                cout << "Power = " << player->getParty(pokeStat)->getMoves(i)->getMovePow() << " , Accuracy = " << player->getParty(pokeStat)->getMoves(i)->getMoveAcc();
                cout << " , Move Type: " << player->getParty(pokeStat)->getMoves(i)->getMoveType() << " , PP: " << player->getParty(pokeStat)->getMoves(i)->getMovePP() << " / " << player->getParty(pokeStat)->getMoves(i)->getOr_MovePP() << endl;
                cout << "Move Description: " << player->getParty(pokeStat)->getMoves(i)->getMoveDescript() << endl << endl;
            }

            cout << "HP: " << player->getParty(pokeStat)->getBase(0) << endl;
            cout << "ATK: " << player->getParty(pokeStat)->getBase(1) << endl;
            cout << "DEF: " << player->getParty(pokeStat)->getBase(2) << endl;
            cout << "SP.ATK: " << player->getParty(pokeStat)->getBase(3) << endl;
            cout << "SP.DEF: " << player->getParty(pokeStat)->getBase(4) << endl;
            cout << "SPD: " << player->getParty(pokeStat)->getBase(5) << endl;

            cout << "Ability: " << player->getParty(pokeStat)->getAbility() << endl;
            cout << "Description: " << player->getParty(pokeStat)->getAbilityDescript() << endl << endl;

            //add item description once its added (if, probs though)

            cout << "Would you like to view another Pokemon's Stats?: (0 = No, 1 = Yes) ";
            cin >> pokeStat;
            while ((pokeStat!=0&&pokeStat!=1)||(cin.fail()==true))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Please Try again: ";
                cin >> pokeStat;
                if ((!cin.fail())&&(pokeStat>=0&&pokeStat<=1))
                {
                    break;
                }
            }

            if (pokeStat==0)
            {
                break;
            }

            //ask which pokemon stat they want to view, view it etc etc
            // then return to top, maybe make whole thing in while loop using choice for switch or back as breaks/returns?
        }
    }
    cout << endl << endl;

            //player pokemon switching
    cout << "Which Pokemon would you like to switch in?: ";
    cin >> choice;
    while ((choice!=-1&&choice!=0&&choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5)||(cin.fail()==true))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please Try again: ";
        cin >> choice;
        if ((!cin.fail())&&(choice>=-1&&choice<=5))
        {
            break;
        }
    }

    if (choice==-1)
    {
        return -1;
    }

    while (choice==player->getCurrent()||player->getParty(choice)->getCurrent(0)<=0)
    {           ///preventing invalid inputs
        cout << "Pokemon is already in or is unable to continue, Please try again: " << endl;
        cin >> choice;
        while ((choice<-1||choice>5)||(cin.fail()==true))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please Try again: ";
            cin >> choice;
            if ((!cin.fail())&&(choice>=-1&&choice<=5))
            {
                break;
            }
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please Try again: ";
        cin >> choice;
        if ((!cin.fail())&&(choice!=player->getCurrent()&&player->getParty(choice)->getCurrent(0)>0))
        {
            break;
        }
        
        if (choice==-1)
        {
            return -1;
        }
    }

    // for (int i=0;i<6;i++)
    // {

    //     //need to think about how transform will work, discuss with rowe

    //     // if (player->getParty(player->getCurrent())->transformed==1)
    //     // {

    //     // }
    //     // player->getParty(player->getCurrent())->statMultiplier[i]=1->0;
    //     // player->getParty(player->getCurrent())->condition[1]="Not Confused";
    //     // player->getParty(player->getCurrent())->badCounter=0;
    // }

    for (int j =0; j<6;j++)
    {                                       //removing confused and resetting counters when player switches pokemon
        player->getParty(player->getCurrent())->setStatMultiplier(j,0,"=");
    }
    player->getParty(player->getCurrent())->setCondition(1,"Not Confused");
    player->getParty(player->getCurrent())->setConditionCool(1,0,"=");
    player->getParty(player->getCurrent())->setBadCounter(0,"=");
    player->getParty(player->getCurrent())->setTurnCount(0,"=");
    player->getParty(player->getCurrent())->setProtect(0);
    player->getParty(player->getCurrent())->setOutrage(0);
    player->getParty(player->getCurrent())->setFlinched(0);

    cout << "Player's " << player->getParty(player->getCurrent())->getPokeName() << " has SWITCHED OUT for ";
    player->setCurrent(choice);
    cout << player->getParty(player->getCurrent())->getPokeName() << endl;

    if (player->getParty(player->getCurrent())->getAbility()=="Intimidate"&&enemy->getParty(enemy->getCurrent())->getAbility()!="Clear Body")
    {
        cout << player->getParty(player->getCurrent())->getPokeName() <<" Intimidate Ability has lowered " << enemy->getParty(enemy->getCurrent())->getPokeName() << " ATK!" <<endl << flush;
        usleep(750000);
        enemy->getParty(enemy->getCurrent())->setStatMultiplier(0,1,"-");
    }
    else if (player->getParty(player->getCurrent())->getAbility()=="Intimidate"&&enemy->getParty(enemy->getCurrent())->getAbility()=="Clear Body")
    {
        cout << player->getParty(player->getCurrent())->getPokeName() <<" Intimidate Ability has No Effect on " << enemy->getParty(enemy->getCurrent())->getPokeName() << "!" << endl << flush;
        usleep(750000);
    }

    return 1;
}

int Battle::turnAttack(Pokemon* atk, Pokemon* def, int attack, string user)
{
    //destiny bond and overall check so can't do moves whilst dead
    if (atk->getCurrent(0)<=0&&def->getCurrent(0)<=0)
    {
        atk->setCurrent(0,0,"=");
        def->setCurrent(0,0,"=");
        return 1;
    }
    else if (atk->getCurrent(0)<=0)
    {
        atk->setCurrent(0,0,"=");
        return 1;
    }
    else if (def->getCurrent(0)<=0)
    {
        def->setCurrent(0,0,"=");
        return 1;
    }

    int damage=0;
    double stab=1.0;
    double burn=1.0;
    double weather=1.0;
    double effective=1.0;
    double random;
    double chance;
    double crit;
    int numHitsCheck=1;

    double speedEnemy;
    double speedPlayer;
    int serene=1;
    int pressure=1;

    if (def->getAbility()=="Pressure")
    {
        pressure=2;
    }
    
    if (atk->getAbility()=="Serene Grace")
    {
        serene=2;
    }
    
    if (atk->getMoves(attack)->getMoveName()=="Outrage")
    {
        atk->setOutrage(atk->getOutrage()+1);
    }

    if (atk->getProtect()>0&&atk->getMoves(attack)->getMoveName()!="Protect")
    {
        atk->setProtect(0);
    }
    //special if statements for certain moves which have extra effects
    if (atk->getMoves(attack)->getMoveName()=="Fishious Rend")
    {
        if (user=="Player")
        {
            speedPlayer = atk->getCurrent(5)*stageMulti(atk->getStatMultiplier(4),4);

            speedEnemy= def->getCurrent(5)*stageMulti(def->getStatMultiplier(4),4);

            if (atk->getCondition(0)=="Paralyzed")
            {
                speedPlayer *= (1/2);
            }
            if (def->getCondition(0)=="Paralyzed")
            {
                speedEnemy *= (1/2);
            }
        }
        else if (user=="Enemy")
        {
            speedPlayer = def->getCurrent(5)*stageMulti(def->getStatMultiplier(4),4);

            speedEnemy= atk->getCurrent(5)*stageMulti(atk->getStatMultiplier(4),4);

            if (def->getCondition(0)=="Paralyzed")
            {
                speedPlayer *= (1/2);
            }
            if (atk->getCondition(0)=="Paralyzed")
            {
                speedEnemy *= (1/2);
            }
        }
    }

                //DIG / phantom force invicibility
    if (atk->getMoves(attack)->getCooldown()>0&&atk->getCooldown()==0)
    {
        atk->setCooldown((atk->getMoves(attack)->getCooldown()+1),"+");
        atk->setImpermeable(1,"=");
        if (atk->getMoves(attack)->getMoveName()=="Dig")
        {
            cout << atk->getPokeName() << " has DUG UNDERGROUND!" << endl;
        }

        if (atk->getMoves(attack)->getMoveName()=="Phantom Force")
        {
            cout << atk->getPokeName() << " has FADED into the SHADOWS!" << endl;
        }
        return 0;
    }

    if (atk->getCooldown()<0)
    {
        atk->setCooldown(0,"=");
        return 0;
    }
    else if (atk->getCooldown()>0)
    {
        atk->setCooldown(0,"=");
    }

    atk->setCritLast(0,"=");

    cout << user << "'s " << atk->getPokeName() << " uses " << atk->getMoves(attack)->getMoveName() << endl << flush;
    usleep(1500000);

    if (atk->getCondition(0)=="Burned")             //halves player physical attack if poemon is burned
    {
        burn=0.5;
    }

    if (atk->getMoves(attack)->getNumHits(0)>1)             //multi hit moves
    {
        numHitsCheck=atk->getMoves(attack)->getNumHits(1)-atk->getMoves(attack)->getNumHits(0);
        chance=rand()%numHitsCheck+atk->getMoves(attack)->getNumHits(0);
        numHitsCheck=chance;
    }

    if (def->getRoost()==1)
    {
        if (def->getType(0)=="Flying"&&def->getTypeNum()==1)
        {        
            effective=1.0;
        }
        else if (def->getType(0)=="Flying"&&def->getTypeNum()==2)
        {
            string fake[2]={def->getType(1)," "};
            effective = weakness(def->getTypeNum(),fake,atk->getMoves(attack)->getMoveEle());
        }
        else if (def->getType(1)=="Flying"&&def->getTypeNum()==2)
        {
            string fake[2]={def->getType(0)," "};
            effective = weakness(def->getTypeNum(),fake,atk->getMoves(attack)->getMoveEle());
        }
    }
    else
    {
        effective = weakness(def->getTypeNum(),def->getTypes(),atk->getMoves(attack)->getMoveEle());
    }

    for (int i=0;i<atk->getTypeNum();i++)
    {
        if (atk->getType(i)==atk->getMoves(attack)->getMoveEle())
        {
            stab=1.5;                            //increase damage if STAB is in effect
            break;
        }
    }

    if (def->getProtect()>=1)
    {
            atk->getMoves(attack)->setMovePP(1*pressure,"-");
            cout << atk->getMoves(attack)->getMoveName() << " Was BLOCKED!" << endl;
            return 0;
    }

    if (def->getImpermeable()>0)
    {
        def->setImpermeable(1,"-");
        cout << atk->getMoves(attack)->getMoveName() << " MISSED!" << endl;             //if enemy pokemon cannot be hit force a MISS
        return 0;
    }

    if (atk->getMoves(attack)->getMoveAcc()*atk->getStatMultiplier(5)<100&&atk->getMoves(attack)->getMoveAcc()*atk->getStatMultiplier(5)!=0)
    {
        chance = rand()%100;
        if (chance>atk->getMoves(attack)->getMoveAcc()*atk->getStatMultiplier(5))
        {
            atk->getMoves(attack)->setMovePP(1*pressure,"-");
            cout << atk->getMoves(attack)->getMoveName() << " MISSED!" << endl;
            return 0;
        }
    }

    atk->getMoves(attack)->setMovePP(1*pressure,"-");

    if ((def->getAbility()=="Wonder Guard"&&effective<2.0)||(def->getAbility()=="Levitate"&&atk->getMoves(attack)->getMoveEle()=="Ground"))
    {
        cout << atk->getPokeName() << " USED " << atk->getMoves(attack)->getMoveName() << endl;

        cout << atk->getMoves(attack)->getMoveName() << " dealt 0.0 DAMAGE Thanks to " << def->getAbility() << "!" << endl;

        return 0;
    }

    for (int i=0;i<numHitsCheck;i++)
    {
        random=rand()%15+85;
        random/=100;
        if (atk->getPokeName()=="MagikarpGOD"&&def->getPokeName()=="MagikarpGOD")
        {
            random=1.0;
        }
        if (atk->getMoves(attack)->getMoveType()=="Physical")
        {
            if ((((user=="Player")&&(speedPlayer>speedEnemy))||((user=="Enemy")&&(speedPlayer<speedEnemy)))&&atk->getMoves(attack)->getMoveName()=="Fishious Rend")
            {
                damage += ((((((2*50)/5)+2)*atk->getMoves(attack)->getMovePow()*2*((atk->getCurrent(1)*(stageMulti(atk->getStatMultiplier(0),0)))/(def->getCurrent(2)*(stageMulti(def->getStatMultiplier(1),1)))))/50)+2)*weather*stab*random*burn*effective*1.5;
            }
            else
            {
                damage += ((((((2*50)/5)+2)*atk->getMoves(attack)->getMovePow()*((atk->getCurrent(1)*(stageMulti(atk->getStatMultiplier(0),0)))/(def->getCurrent(2)*(stageMulti(def->getStatMultiplier(1),1)))))/50)+2)*weather*stab*random*burn*effective*1.5;
            }
        }
        else if (atk->getMoves(attack)->getMoveType()=="Special")
        {
            if (atk->getMoves(attack)->getMoveName()=="Brine"&&def->getCurrent(0)<=0.5*def->getBase(0))
            {
                damage += ((((((2*50)/5)+2)*atk->getMoves(attack)->getMovePow()*2*((atk->getCurrent(3)*(stageMulti(atk->getStatMultiplier(2),2)))/(def->getCurrent(4)*(stageMulti(def->getStatMultiplier(3),2)))))/50)+2)*weather*stab*random*effective*1.5;
            }
            else if ((atk->getCurrent(0)<=(0.333*atk->getBase(0)))&&atk->getAbility()=="Blaze")
            {
                damage += ((((((2*50)/5)+2)*atk->getMoves(attack)->getMovePow()*2*((atk->getCurrent(3)*1.5*(stageMulti(atk->getStatMultiplier(2),2)))/(def->getCurrent(4)*(stageMulti(def->getStatMultiplier(3),2)))))/50)+2)*weather*stab*random*effective*1.5;
            }
            else
            {
                damage += ((((((2*50)/5)+2)*atk->getMoves(attack)->getMovePow()*((atk->getCurrent(3)*(stageMulti(atk->getStatMultiplier(2),2)))/(def->getCurrent(4)*(stageMulti(def->getStatMultiplier(3),2)))))/50)+2)*weather*stab*random*effective*1.5;
            }
        }
    }

    crit = stageMulti(atk->getMoves(attack)->getCrit_Ratio(),-1);
    chance = rand()%100;

    if ((chance<=crit)&&(def->getAbility()!="Shell Armour"&&def->getAbility()!="Battle Armour"))
    {
        damage *= 2.0;
        atk->setCritLast(1,"=");
        cout << "CRITICAL HIT!!" << endl;
    }

    if (effective >= 2.0)
    {
        cout << "SUPER EFFECTIVE!!" << endl;
    }
    else if (effective == 0.5)
    {
        cout << "NOT VERY EFFECTIVE!!" << endl;
    }
    else if (effective == 0)
    {
        cout << "IT HAD NO EFFECT!!" << endl;
    }

    //cout << atk->getPokeName() << " USED " << atk->getMoves(attack)->getMoveName() << endl;

    //water absorb stuff!!!
    if (atk->getMoves(attack)->getMoveEle()=="Water"&&def->getAbility()=="Water Absorb")
    {
        cout << def->getPokeName() << " Absorbed " << atk->getPokeName() << " Attack and Gain HP!" << endl << flush;        
        usleep(1500000);
        def->setCurrent(0,(damage*0.25),"+");
        if (def->getCurrent(0)>def->getBase(0))
        {
            def->setCurrent(0,def->getBase(0),"=");
        }
        damage=0;
    }
    else
    {
        cout << atk->getMoves(attack)->getMoveName() << " dealt ";
    }

    if (def->getAbility()=="Thick Fat"&&(atk->getMoves(attack)->getMoveEle()=="Fire"||atk->getMoves(attack)->getMoveEle()=="Ice"))
    {
        def->setCurrent(0,(0.5*damage),"-");
        damage*=0.5;
    }
    else if ((((def->getCurrent(0)-damage)<=0)&&def->getCurrent(0)==def->getBase(0))&&def->getAbility()=="Sturdy")
    {
        damage=def->getCurrent(0)-1;
        def->setCurrent(0,1,"=");
    }
    else
    {
        def->setCurrent(0,damage,"-");
    }

    cout << damage << " DAMAGE!" << endl << flush;
    usleep(1500000);

    if (def->getCurrent(0)<=0)
    {
        atk->setDamageLast((damage+def->getCurrent(0)),"=");
        damage+=def->getCurrent(0);
        def->setCurrent(0,0,"=");
        cout << def->getPokeName() << " has FAINTED!" << endl;
        if (def->getDestiny()!=0)
        {
            cout << def->getPokeName() << " HAS TAKEN " << atk->getPokeName() << " DOWN WITH IT!!!" << endl << flush;
            usleep(1500000);
            atk->setCurrent(0,0,"=");
            return 1;
        } 
    }
    else
    {
        atk->setDamageLast(damage,"=");
    }
    
    if (atk->getMoves(attack)->getRecoil(0)==1&&atk->getAbility()!="Rock Head")
    {
        int recoil = damage*(atk->getMoves(attack)->getRecoil(1)/100);
        atk->setCurrent(0,recoil,"-");
        cout << atk->getPokeName() << " lost " << recoil << " DAMAGE to RECOIL" << endl << flush;
        usleep(750000);

        if (atk->getCurrent(0)<0)
        {
            atk->setCurrent(0,0,"=");
        }
    }

    if (atk->getMoves(attack)->getFlinch()>0)
    {
        chance=rand()%100;
        if (chance<=atk->getMoves(attack)->getFlinch())
        {
            def->setFlinched(1);
        }
    }

    if (atk->getMoves(attack)->getContact()==1&&def->getAbility()=="Static")
    {
        atk->setCondition(0,"Paralyzed");
        cout << atk->getPokeName() << " has been PARALYZED" << endl;
        atk->setConditionCool(0,-1,"=");
    }

    //check if works, not sure about ancient power stat up if statement
    chance = rand()%100;
    if (atk->getMoves(attack)->getBuff(0)>0)
    {
        if (atk->getMoves(attack)->getBuff(0)==69&&(chance<=(atk->getMoves(attack)->getBuff(2)*serene)))
        {
            cout << "All of " << atk->getPokeName() << "'s stats have been increased by 1 Stage, including ATK, DEF, SP.ATK, SP.DEF, SPD & ACC" << endl << flush;
            usleep(750000);
            for (int i=0;i<5;i++)
            {
                atk->setStatMultiplier(i,1,"+");
            }
        }
        else if (chance<=(atk->getMoves(attack)->getBuff(2)*serene))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been increased by " << atk->getMoves(attack)->getBuff(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff(0)),atk->getMoves(attack)->getBuff(1),"+");
        }
    }

    if (atk->getMoves(attack)->getBuff2(0)>0)
    {
        if (chance<=(atk->getMoves(attack)->getBuff2(2)*serene))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff2(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been increased by " << atk->getMoves(attack)->getBuff2(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff2(0)),atk->getMoves(attack)->getBuff2(1),"+");
        }
    }

    if (atk->getMoves(attack)->getBuff3(0)>0)
    {
        if (chance<=(atk->getMoves(attack)->getBuff3(2)*serene))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff3(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been increased by " << atk->getMoves(attack)->getBuff3(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff3(0)),atk->getMoves(attack)->getBuff3(1),"+");
        }
    }

    if (atk->getMoves(attack)->getBuff(0)<0)
    {
        if (chance<=atk->getMoves(attack)->getBuff(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been reduced by " << atk->getMoves(attack)->getBuff(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff(0)),atk->getMoves(attack)->getBuff(1),"-");
        }
    }

    if (atk->getMoves(attack)->getBuff2(0)<0)
    {
        if (chance<=atk->getMoves(attack)->getBuff2(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff2(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been reduced by " << atk->getMoves(attack)->getBuff2(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff2(0)),atk->getMoves(attack)->getBuff2(1),"-");
        }
    }

    if (atk->getMoves(attack)->getBuff3(0)<0)
    {
        if (chance<=atk->getMoves(attack)->getBuff3(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff3(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been reduced by " << atk->getMoves(attack)->getBuff3(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff3(0)),atk->getMoves(attack)->getBuff3(1),"-");
        }
    }

    if (atk->getMoves(attack)->getStatus(0)>0)
    {
        chance = rand()%100;
        if (chance<=(atk->getMoves(attack)->getStatus(1)*serene))
        {
            switch (atk->getMoves(attack)->getStatus(0))
            {
                case 1:
                {
                    if (def->getType(0)!="Electric"&&def->getType(1)!="Electric")
                    {
                        def->setCondition(0,"Paralyzed");
                        cout << def->getPokeName() << " has been PARALYZED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 2:
                {
                    def->setCondition(0,"Sleeping");
                    chance = rand()%3;
                    cout << def->getPokeName() << " has been put to SLEEP" << endl;
                    def->setConditionCool(0,(chance+1),"=");
                    break;
                }
                case 3:
                {
                    if (def->getType(0)!="Fire"&&def->getType(1)!="Fire")
                    {
                        def->setCondition(0,"Burned");
                        cout << def->getPokeName() << " has been BURNED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 4:
                {
                    if ((def->getType(0)!="Poison"&&def->getType(1)!="Poison")&&(def->getType(0)!="Steel"&&def->getType(1)!="Steel"))
                    {
                        def->setCondition(0,"Poisoned");
                        cout << def->getPokeName() << " has been POISONED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 5:
                {
                    if (def->getType(0)!="Ice"&&def->getType(1)!="Ice")
                    {
                        def->setCondition(0,"Frozen");
                        cout << def->getPokeName() << " has been FROZEN" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 6:
                {
                    if ((def->getType(0)!="Poison"&&def->getType(1)!="Poison")&&(def->getType(0)!="Steel"&&def->getType(1)!="Steel"))
                    {
                        def->setCondition(0,"Badly Poisoned");
                        cout << def->getPokeName() << " has been BADLY POISONED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
            }
        }
    }

    if (atk->getMoves(attack)->getConfuse(0)>0)
    {
        chance = rand()%100;
        if (chance<=(atk->getMoves(attack)->getConfuse(1)*serene))
        {
            def->setCondition(1,"Confused");
            cout << def->getPokeName() << " has been CONFUSED" << endl;
            def->setConditionCool(1,1,"=");
        }
    }

    if (atk->getMoves(attack)->getMoveName()=="Giga Drain")
    {
        atk->setCurrent(0,(0.5*damage),"+");
        cout << atk->getPokeName() << " drained " << 0.5*damage << " from " << def->getPokeName() << "!" <<endl << flush;
        usleep(750000);
        if (atk->getCurrent(0)>atk->getBase(0))
        {
            atk->setCurrent(0,atk->getBase(0),"=");
        }
    }

    if (atk->getMoves(attack)->getDeBuff(0)>0&&def->getAbility()!="Clear Body")
    {
        chance = rand()%100;
        if (chance<=(atk->getMoves(attack)->getDeBuff(2)*serene))
        {
            if (atk->getMoves(attack)->getDeBuff(0)==6&&def->getAbility()=="Keen Eye")
            {
                cout << atk->getPokeName() << " ACC Drop had NO Effect and " << def->getPokeName() << " is Keenly watching " << atk->getPokeName() << "!" << endl << flush;
                usleep(750000);
            }
            else
            {
                cout << def->getPokeName() << "'s ";
                if (atk->getMoves(attack)->getDeBuff(0)==1)
                {
                    cout << "ATK";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==2)
                {
                    cout << "DEF";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==3)
                {
                    cout << "SP.ATK";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==4)
                {
                    cout << "SP.DEF";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==5)
                {
                    cout << "SPD";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==6)
                {
                    cout << "ACC";
                }

                cout << " stat has been reduced by " << atk->getMoves(attack)->getDeBuff(1) << " Stages" <<endl << flush;
                usleep(750000);
                def->setStatMultiplier((atk->getMoves(attack)->getDeBuff(0)),atk->getMoves(attack)->getDeBuff(1),"-");
            }
        }
    }

    if (atk->getMoves(attack)->getCooldown()<0&&atk->getCooldown()==0)
    {
        atk->setCooldown((atk->getMoves(attack)->getCooldown()-1),"+");
        return 1;
    }
    //implement weather changes if weather is completely implemented

    return 1;
}

int Battle::turnStatus(Pokemon* atk, Pokemon* def, string user,int attack)
{
    //destiny bond and overall check so can't do moves whilst dead
    if (atk->getCurrent(0)<=0&&def->getCurrent(0)<=0)
    {
        atk->setCurrent(0,0,"=");
        def->setCurrent(0,0,"=");
        return 1;
    }
    else if (atk->getCurrent(0)<=0)
    {
        atk->setCurrent(0,0,"=");
        return 1;
    }
    else if (def->getCurrent(0)<=0)
    {
        def->setCurrent(0,0,"=");
        return 1;
    }

    double chance=0;
    int pressure=1;

    if (def->getAbility()=="Pressure")
    {
        pressure=2;
    }

    cout << user << "'s " << atk->getPokeName() << " uses " << atk->getMoves(attack)->getMoveName() << endl << flush;
    usleep(1500000);

    if (atk->getMoves(attack)->getMoveName()=="Destiny Bond")
    {
        cout << atk->getPokeName() << " is preparing to Take its Enemy Down With It!!" << endl << flush;
        atk->setDestiny(1);
        atk->getMoves(attack)->setMovePP(1*pressure,"-");
        usleep(1500000);
        return 1;
    }

    if (atk->getCondition(0)=="Sleeping"&&atk->getMoves(attack)->getMoveName()=="Sleep Talk")
    {
        int talk=rand()%3;
        if (talk==attack&&attack<3)
        {
            talk++;
        }
        else if (talk==attack&&attack==3)
        {
            talk--;
        }
        atk->getMoves(attack)->setMovePP(1*pressure,"-");

        if (atk->getMoves(talk)->getMoveName()=="Rest")
        {
            atk->getMoves(attack)->setMovePP(1*pressure,"-");
            cout << "Sleep Talk FAILED!" << endl << endl;
            return 0;
        }

        atk->getMoves(talk)->setMovePP(1*pressure,"+");
        if (atk->getMoves(talk)->getMoveType()=="Status")
        {
            turnStatus(atk,def,user,talk);
            return 0;
        }
        else if (atk->getMoves(talk)->getMoveType()=="Special"||atk->getMoves(talk)->getMoveType()=="Physical")
        {
            turnAttack(atk,def,talk,user);
            return 0;
        }
    }
    else if (atk->getCondition(0)!="Sleeping"&&atk->getMoves(attack)->getMoveName()=="Sleep Talk")
    {
        cout << "Sleep Talk FAILED!" << endl << endl;
        atk->getMoves(attack)->setMovePP(1*pressure,"-");
        return 0;
    }

    if (atk->getCurrent(0)==atk->getBase(0)&&atk->getMoves(attack)->getMoveName()=="Rest")
    {
        cout << "Rest FAILED, " << atk->getPokeName() << " is already at FULL HP!" << endl << endl;
        atk->getMoves(attack)->setMovePP(1*pressure,"-");
        return 0;
    }

    if (atk->getProtect()>0&&atk->getMoves(attack)->getMoveName()!="Protect")
    {
        atk->setProtect(0);
    }

    if (atk->getMoves(attack)->getMoveName()=="Protect"&&atk->getProtect()>0)
    {
        chance=rand()%100;
        if ((100.0/(atk->getProtect()))>chance)
        {
            atk->getMoves(attack)->setMovePP(1*pressure,"-");
            cout << atk->getMoves(attack)->getMoveName() << " FAILED!" << endl;
            atk->setProtect(0);
            return 0;
        }
        else
        {
            atk->setProtect(atk->getProtect()+1);
            atk->getMoves(attack)->setMovePP(1*pressure,"-");
            cout << atk->getPokeName() << " has covered itself in a Veil of Protection!" << endl << endl;
            return 0;
        }
    }
    else if (atk->getMoves(attack)->getMoveName()=="Protect")
    {
        atk->setProtect(atk->getProtect()+1);
        atk->getMoves(attack)->setMovePP(1*pressure,"-");
        cout << atk->getPokeName() << " has covered itself in a Veil of Protection!" << endl << endl;
        return 0;
    }

    if (atk->getMoves(attack)->getHeal()>0&&atk->getCurrent(0)>=atk->getBase(0))
    {
        cout << atk->getPokeName() << " " << atk->getMoves(attack)->getMoveName() << " FAILED, " << atk->getPokeName() << " is already at FULL HP!" << endl << endl;
        atk->getMoves(attack)->setMovePP(1*pressure,"-");
        return 0;
    }

    if (atk->getMoves(attack)->getMoveAcc()*atk->getStatMultiplier(5)<100&&atk->getMoves(attack)->getMoveAcc()*atk->getStatMultiplier(5)!=0)
    {
        chance = rand()%100;
        if (chance>atk->getMoves(attack)->getMoveAcc()*atk->getStatMultiplier(5))
        {
            atk->getMoves(attack)->setMovePP(1*pressure,"-");
            cout << atk->getMoves(attack)->getMoveName() << " MISSED!" << endl;
            return 0;
        }
    }

//    if ((atk->getMoves(attack)->getMoveName()=="Curse")&&(atk->getType(0)=="Ghost"||atk->getType(1)=="Ghost"))
//    {
//        // if (atk->getCurrent(0)>=atk->getBase(0))
//        // {
//        //     atk->setCurrent(0,(1/2),"*");
//        //     def->setCurse(1);
//        // }
//        // else
//        {
//            cout << "Unable to use CURSE, not enough HP." << endl;
//        }
//    }

    if (atk->getMoves(attack)->getHeal()>0)
    {
        atk->setCurrent(0,((atk->getMoves(attack)->getHeal()/100.0)*atk->getBase(0)),"+");
        if (atk->getCurrent(0)>atk->getBase(0))
        {
            atk->setCurrent(0,atk->getBase(0),"=");
        }
        cout << atk->getPokeName() << " has Recovered " << atk->getMoves(attack)->getHeal() << "% of its HP!" << endl << flush;
        usleep(750000);
    }

    if (atk->getMoves(attack)->getBuff(0)>0)
    {
        if (chance<=atk->getMoves(attack)->getBuff(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been increased by " << atk->getMoves(attack)->getBuff(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff(0)),atk->getMoves(attack)->getBuff(1),"+");
        }
    }

    if (atk->getMoves(attack)->getBuff2(0)>0)
    {
        if (chance<=atk->getMoves(attack)->getBuff2(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff2(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been increased by " << atk->getMoves(attack)->getBuff2(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff2(0)),atk->getMoves(attack)->getBuff2(1),"+");
        }
    }

    if (atk->getMoves(attack)->getBuff3(0)>0)
    {
        if (chance<=atk->getMoves(attack)->getBuff3(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff3(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been increased by " << atk->getMoves(attack)->getBuff3(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff3(0)),atk->getMoves(attack)->getBuff3(1),"+");
        }
    }

    if (atk->getMoves(attack)->getBuff(0)<0)
    {
        if (chance<=atk->getMoves(attack)->getBuff(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been reduced by " << atk->getMoves(attack)->getBuff(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff(0)),atk->getMoves(attack)->getBuff(1),"-");
        }
    }

    if (atk->getMoves(attack)->getBuff2(0)<0)
    {
        if (chance<=atk->getMoves(attack)->getBuff2(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff2(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff2(0)==6)
            {
                cout << "ACC";
            }
            cout << " stat has been reduced by " << atk->getMoves(attack)->getBuff2(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff2(0)),atk->getMoves(attack)->getBuff2(1),"-");
        }
    }

    if (atk->getMoves(attack)->getBuff3(0)<0)
    {
        if (chance<=atk->getMoves(attack)->getBuff3(2))
        {
            cout << atk->getPokeName() << "'s ";
            if (atk->getMoves(attack)->getBuff3(0)==1)
            {
                cout << "ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==2)
            {
                cout << "DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==3)
            {
                cout << "SP.ATK";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==4)
            {
                cout << "SP.DEF";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==5)
            {
                cout << "SPD";
            }
            else if (atk->getMoves(attack)->getBuff3(0)==6)
            {
                cout << "ACC";
            }

            cout << " stat has been reduced by " << atk->getMoves(attack)->getBuff3(1) << " Stages" <<endl << flush;
            usleep(750000);
            atk->setStatMultiplier((atk->getMoves(attack)->getBuff3(0)),atk->getMoves(attack)->getBuff3(1),"-");
        }
    }

    if (atk->getMoves(attack)->getStatus(0)>0)
    {
        chance = rand()%100;
        if (chance<=atk->getMoves(attack)->getStatus(1))
        {
            switch (atk->getMoves(attack)->getStatus(0))
            {
                case 1:
                {
                    if (def->getType(0)!="Electric"&&def->getType(1)!="Electric")
                    {
                        def->setCondition(0,"Paralyzed");
                        cout << def->getPokeName() << " has been PARALYZED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 2:
                {
                    def->setCondition(0,"Sleeping");
                    chance = rand()%3;
                    cout << def->getPokeName() << " has been put to SLEEP" << endl;
                    def->setConditionCool(0,(chance+1),"=");
                    break;
                }
                case 3:
                {
                    if (def->getType(0)!="Fire"&&def->getType(1)!="Fire")
                    {
                        def->setCondition(0,"Burned");
                        cout << def->getPokeName() << " has been BURNED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 4:
                {
                    if ((def->getType(0)!="Poison"&&def->getType(1)!="Poison")&&(def->getType(0)!="Steel"&&def->getType(1)!="Steel"))
                    {
                        def->setCondition(0,"Poisoned");
                        cout << def->getPokeName() << " has been POISONED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 5:
                {
                    if (def->getType(0)!="Ice"&&def->getType(1)!="Ice")
                    {
                        def->setCondition(0,"Frozen");
                        cout << def->getPokeName() << " has been FROZEN" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
                case 6:
                {
                    if ((def->getType(0)!="Poison"&&def->getType(1)!="Poison")&&(def->getType(0)!="Steel"&&def->getType(1)!="Steel"))
                    {
                        def->setCondition(0,"Badly Poisoned");
                        cout << def->getPokeName() << " has been BADLY POISONED" << endl;
                        def->setConditionCool(0,-1,"=");
                    }
                    break;
                }
            }
        }
    }

    if (atk->getMoves(attack)->getConfuse(0)>0)
    {
        chance = rand()%100;
        if (chance<=atk->getMoves(attack)->getConfuse(1))
        {
            def->setCondition(1,"Confused");
            cout << def->getPokeName() << " has become CONFUSED" << endl;
            def->setConditionCool(1,1,"=");
        }
    }

    if (atk->getMoves(attack)->getDeBuff(0)>0&&def->getAbility()!="Clear Body")
    {
        chance = rand()%100;
        if (chance<=atk->getMoves(attack)->getDeBuff(2))
        {
            if (atk->getMoves(attack)->getDeBuff(0)==6&&def->getAbility()=="Keen Eye")
            {
                cout << atk->getPokeName() << " ACC Drop had NO Effect and " << def->getPokeName() << " is Keenly watching " << atk->getPokeName() << "!" << endl << flush;
                usleep(750000);
            }
            else
            {
                cout << def->getPokeName() << "'s ";
                if (atk->getMoves(attack)->getDeBuff(0)==1)
                {
                    cout << "ATK";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==2)
                {
                    cout << "DEF";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==3)
                {
                    cout << "SP.ATK";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==4)
                {
                    cout << "SP.DEF";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==5)
                {
                    cout << "SPD";
                }
                else if (atk->getMoves(attack)->getDeBuff(0)==6)
                {
                    cout << "ACC";
                }

                cout << " stat has been reduced by " << atk->getMoves(attack)->getDeBuff(1) << " Stages" <<endl << flush;
                usleep(750000);
                def->setStatMultiplier(atk->getMoves(attack)->getDeBuff(0),atk->getMoves(attack)->getDeBuff(1),"-");
            }
        }
    }

    if ((atk->getMoves(attack)->getMoveName()=="Belly Drum"&&atk->getCurrent(0)>0.5*atk->getBase(0))&&atk->getStatMultiplier(0)>=6.0)
    {
        atk->setStatMultiplier(0,6.0,"=");
        atk->setCurrent(0,(0.5*atk->getCurrent(0)),"=");
        cout << "ATK has been increased to 6th Stage, HP reduced by 1/2 its Max HP";
    }

    if (atk->getMoves(attack)->getMoveName()=="Rest")
    {
        atk->setCurrent(0,atk->getBase(0),"=");
        atk->setCondition(0,"Sleeping");
        cout << atk->getPokeName() << " has been put to SLEEP and has recovered its HP and healed all status conditions" << endl;
        atk->setConditionCool(0,2,"=");
    }

    if (atk->getMoves(attack)->getMoveName()=="Reflect")
    {
        if (user=="Player")
        {
            playerReflect=5;
            cout << "A REFLECTIVE SCREEN of light has formed on the Player's side of the field!" << endl;
        }
        else if (user=="Enemy")
        {
            enemyReflect=5;
            cout << "A REFLECTIVE SCREEN of light has formed on the Enemy's side of the field!" << endl;
        }
    }

    if (atk->getMoves(attack)->getMoveName()=="Light Screen")
    {
        if (user=="Player")
        {
            playerLightScreen=5;
            cout << "A SCREEN of LIGHT has formed on the Player's side of the field!" << endl;
        }
        else if (user=="Enemy")
        {
            enemyLightScreen=5;
            cout << "A REFLECTIVE of LIGHT has formed on the Enemy's side of the field!" << endl;
        }
    }

    if (atk->getMoves(attack)->getMoveName()=="Spikes")
    {
        if (user=="Player")
        {
            playerSpikes++;
            cout << "A layer of SPIKES has been placed on the Enemy's side of the field!" << endl;
        }
        else if (user=="Enemy")
        {
            enemySpikes++;
            cout << "A layer of SPIKES has been placed on the Enemy's side of the field!" << endl;
        }
    }

    // if (atk->getMoves(attack)->getMoveName()=="Transform")
    // {
    //     atk->transformed=1;
    //     atk->getTypeNum()=def->getTypeNum();
    //     atk->type[0]=def->type[0]; atk->type[1]=def->type[1];

    //     for (int i=0;i<6;i++)
    //     {
    //         if (i>0)
    //         {
    //             atk->current[i]=def->current[i];
    //             atk->getBase[i]=def->getBase[i];
    //         }
    //         if (i<4)
    //         {
    //             atk->getMoves(i)=def->getMoves(i);
    //             atk->getMoves(i)->movePP=5;
    //         }
    //         atk->statMultiplier[i]=def->statMultiplier[i];
    //     }
    // }

    atk->getMoves(attack)->setMovePP(1*pressure,"-");

    return 1;
}

double Battle::weakness(int typeNum,string type[],string element)
{
    double multiplier=1.0;
    for (int i=0;i<typeNum; i++)
    {
        //all types are in defence, ie pokemon being hit types

        //normal defence
        if (type[i]=="Normal"&&element=="Fighting")
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Normal"&&element=="Ghost")
        {
            multiplier *= 0;
        }

        //fighting
        if (type[i]=="Fighting" && (element=="Flying"||element=="Psychic"||element=="Fairy"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Fighting" && (element=="Rock"||element=="Bug"||element=="Dark"))
        {
            multiplier *= 0.5;
        }

        //flying
        if (type[i]=="Flying" && (element=="Rock"||element=="Ice"||element=="Electric"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Flying" && (element=="Fighting"||element=="Bug"||element=="Grass"))
        {
            multiplier *= 0.5;
        }
        else if (type[i]=="Flying" && element=="Ground")
        {
            multiplier *= 0;
        }

        //poison
        if (type[i]=="Poison" && (element=="Ground"||element=="Psychic"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Poison" && (element=="Fighting"||element=="Bug"||element=="Poison"||element=="Grass"||element=="Fairy"))
        {
            multiplier *= 0.5;
        }

        //Ground
        if (type[i]=="Ground" && (element=="Water"||element=="Ice"||element=="Grass"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Ground" && (element=="Poison"||element=="Rock"))
        {
            multiplier *= 0.5;
        }
        else if (type[i]=="Ground" && element=="Electric")
        {
            multiplier *= 0;
        }

        //Rock
        if (type[i]=="Rock" && (element=="Fighting"||element=="Ground"||element=="Steel"||element=="Water"||element=="Grass"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Rock" && (element=="Normal"||element=="Flying"||element=="Poison"||element=="Fire"))
        {
            multiplier *= 0.5;
        }

        //Bug
        if (type[i]=="Bug" && (element=="Flying"||element=="Rock"||element=="Fire"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Bug" && (element=="Fighting"||element=="Ground"||element=="Grass"))
        {
            multiplier *= 0.5;
        }

        //Ghost
        if (type[i]=="Ghost" && (element=="Ghost"||element=="Dark"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Ghost" && (element=="Poison"||element=="Bug"))
        {
            multiplier *= 0.5;
        }
        else if (type[i]=="Ghost" && (element=="Normal"||element=="Fighting"))
        {
            multiplier *= 0;
        }

        //Steel
        if (type[i]=="Steel" && (element=="Fighting"||element=="Ground"||element=="Fire"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Steel" && (element=="Normal"||element=="Flying"||element=="Rock"||element=="Bug"||element=="Steel"||element=="Grass"||element=="Psychic"||element=="Ice"||element=="Dragon"||element=="Fairy"))
        {
            multiplier *= 0.5;
        }
        else if (type[i]=="Steel" && element=="Poison")
        {
            multiplier *= 0;
        }

        //Fire
        if (type[i]=="Fire" && (element=="Ground"||element=="Rock"||element=="Water"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Fire" && (element=="Bug"||element=="Steel"||element=="Fire"||element=="Grass"||element=="Ice"||element=="Fairy"))
        {
            multiplier *= 0.5;
        }

        //Water
        if (type[i]=="Water" && (element=="Grass"||element=="Electric"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Water" && (element=="Steel"||element=="Fire"||element=="Water"||element=="Ice"))
        {
            multiplier *= 0.5;
        }

        //Grass
        if (type[i]=="Grass" && (element=="Flying"||element=="Poison"||element=="Bug"||element=="Fire"||element=="Ice"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Grass" && (element=="Ground"||element=="Water"||element=="Grass"||element=="Electric"))
        {
            multiplier *= 0.5;
        }

        //Electric
        if (type[i]=="Electric" && element=="Ground")
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Electric" && (element=="Flying"||element=="Steel"||element=="Electric"))
        {
            multiplier *= 0.5;
        }

        //Psychic
        if (type[i]=="Psychic" && (element=="Bug"||element=="Ghost"||element=="Dark"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Psychic" && (element=="Fighting"||element=="Psychic"))
        {
            multiplier *= 0.5;
        }

        //Ice
        if (type[i]=="Ice" && (element=="Fighting"||element=="Rock"||element=="Steel"||element=="Fire"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Ice" && element=="Ice")
        {
            multiplier *= 0.5;
        }

        //Dragon
        if (type[i]=="Dragon" && (element=="Ice"||element=="Dragon"||element=="Fairy"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Dragon" && (element=="Fire"||element=="Water"||element=="Grass"||element=="Electric"))
        {
            multiplier *= 0.5;
        }

        //Dark
        if (type[i]=="Dark" && (element=="Fighting"||element=="Bug"||element=="Fairy"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Dark" && (element=="Dark"||element=="Ghost"))
        {
            multiplier *= 0.5;
        }
        else if (type[i]=="Dark" && element=="Psychic")
        {
            multiplier *= 0;
        }
        //Fairy
        if (type[i]=="Fairy" && (element=="Poison"||element=="Steel"))
        {
            multiplier *= 2.0;
        }
        else if (type[i]=="Fairy" && (element=="Fighting"||element=="Bug"||element=="Dark"))
        {
            multiplier *= 0.5;
        }
        else if (type[i]=="Fairy" && element=="Dragon")
        {
            multiplier *= 0;
        }
    }

    return multiplier;
}

double Battle::stageMulti (int stage, int stat)
{
    if (stat<5&&stat>=0)
    {
        if (stage>=0&&stage<7)
        {
            return ((2+stage)/2);
        }
        else if (stage<=0&&stage>-7)
        {
            return (2/(stage+2));
        }
        else
        return -1;
    }
    else if (stat==5)
    {
        if (stage>=0&&stage<7)
        {
            return ((3+stage)/3);
        }
        else if (stage<=0&&stage>-7)
        {
            return (3/(stage+3));
        }
        else
        return -1;
    }
    else if (stat==-1)
    {
        if (stage==0)
        {
            return (1/24);
        }
        else if (stage==1)
        {
            return (1/8);
        }
        else if (stage==2)
        {
            return (1/2);
        }
        else if (stage>2)
        {
            return 1;
        }
        else
        return -1;
    }

    return -69;
}

int Battle::confusionProc(Pokemon* pokemon,int choice)
{
    if (choice==1&&pokemon->getCondition(1)=="Confused")     //force player pokemon to hurt itself in confusion if confused (50% chance_)
    {
        int chance = rand()%100;
        cout << pokemon->getPokeName() << " Is Confused" << endl << flush;
        usleep(150000);
        if (chance<=50)
        {
            double random = rand()%15+85;
            random/=100;
            pokemon->setCurrent(0,((((((2*50)/5)+2)*40*(pokemon->getCurrent(1)*(stageMulti(pokemon->getStatMultiplier(0),0))/(pokemon->getCurrent(2)*(stageMulti(pokemon->getStatMultiplier(1),1))))/50+2)*random)),"-");
            pokemon->setConditionCool(1,1,"+");
            cout << pokemon->getPokeName() << " Hurt Itself in its Confusion!" << endl;

            if (pokemon->getCurrent(0)<0)
            {
                pokemon->setCurrent(0,0,"=");
            }
            return 1;
        }

        if (pokemon->getConditionCool(1)>=5)
        {
            pokemon->setConditionCool(1,0,"=");
            pokemon->setCondition(1,"Not Confused");
            cout << pokemon->getPokeName() << " has BROKEN OUT of its CONFUSION!" << endl << flush;
            usleep(1500000);
            return 0;
        }
    
        pokemon->setConditionCool(1,1,"+");
    }
    else
    {
        return 0;
    }
    return 0;
}

int Battle::enemyAttack(Player* player,Enemy* enemy,Battle* battle)
{
    return 0;
}


int Battle::enemyItem(Enemy* enemy, Player* player, Battle* battle)
{
    return 0;
}

void Battle::setPlayerSpikes(int change,string operation)
{
    if (operation=="+")
    {
        playerSpikes+=change;
    }
    else if (operation=="-")
    {
        playerSpikes-=change;
    }
    else if (operation=="=")
    {
        playerSpikes=change;
    }
}
int Battle::getPlayerSpikes()
{
    return playerSpikes;
}

void Battle::setPlayerReflect(int change,string operation)
{
    if (operation=="+")
    {
        playerReflect+=change;
    }
    else if (operation=="-")
    {
        playerReflect-=change;
    }
    else if (operation=="=")
    {
        playerReflect=change;
    }
}
int Battle::getPlayerReflect()
{
    return playerReflect;
}

void Battle::setPlayerLightScreen(int change,string operation)
{
    if (operation=="+")
    {
        playerLightScreen+=change;
    }
    else if (operation=="-")
    {
        playerLightScreen-=change;
    }
    else if (operation=="=")
    {
        playerLightScreen=change;
    }
}
int Battle::getPlayerLightScreen()
{
    return playerLightScreen;
}

void Battle::setEnemySpikes(int change,string operation)
{
    if (operation=="+")
    {
        enemySpikes+=change;
    }
    else if (operation=="-")
    {
        enemySpikes-=change;
    }
    else if (operation=="=")
    {
        enemySpikes=change;
    }
}
int Battle::getEnemySpikes()
{
    return enemySpikes;
}

void Battle::setEnemyReflect(int change,string operation)
{
    if (operation=="+")
    {
        enemyReflect+=change;
    }
    else if (operation=="-")
    {
        enemyReflect-=change;
    }
    else if (operation=="=")
    {
        enemyReflect=change;
    }
}
int Battle::getEnemyReflect()
{
    return enemyReflect;
}

void Battle::setEnemyLightScreen(int change,string operation)
{
    if (operation=="+")
    {
        enemyLightScreen+=change;
    }
    else if (operation=="-")
    {
        enemyLightScreen-=change;
    }
    else if (operation=="=")
    {
        enemyLightScreen=change;
    }
}
int Battle::getEnemyLightScreen()
{
    return enemyLightScreen;
}
