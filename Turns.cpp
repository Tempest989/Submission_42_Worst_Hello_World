#include "Turns.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <limits>
using namespace std;

Turns::Turns()
{

}

double Turns::turn(Player* player, Enemy* enemy, Battle *battle)
{
    int turnCounter=0;
    int checker=0;
    double results=0;

    while (checker==0)
    {
        //player turn
        turnCounter++;
        cout << endl << endl << endl << endl << flush;
        usleep(1500000);
        cout << "---------------------------" << endl;
        cout << "      Turn Number: " << turnCounter << endl;
        cout << "---------------------------" << endl;
        cout << endl << endl << endl << endl << flush;
        usleep(1500000);

        //initialising variables
        int check=2;
        int checkP=1;
        int checkE=1;
        int choice;
        int choices;
        double chance;
        int enemyCheck=0;
        int switchedP=0;
        int switchedE=0;

        int confusedP=0;
        int confusedE=0;

        player->getParty(player->getCurrent())->setDamageLast(0,"=");
        enemy->getParty(enemy->getCurrent())->setDamageLast(0,"=");

        if ((player->getParty(player->getCurrent())->getAbility()=="Intimidate"&&enemy->getParty(enemy->getCurrent())->getAbility()!="Clear Body")&&(turnCounter==1))
        {
            cout << player->getParty(player->getCurrent())->getPokeName() <<" Intimidate Ability has lowered " << enemy->getParty(enemy->getCurrent())->getPokeName() << " ATK!" <<endl << flush;
            usleep(750000);
            enemy->getParty(enemy->getCurrent())->setStatMultiplier(0,1,"-");
        }
        else if ((player->getParty(player->getCurrent())->getAbility()=="Intimidate"&&enemy->getParty(enemy->getCurrent())->getAbility()=="Clear Body")&&(turnCounter==1))
        {
            cout << player->getParty(player->getCurrent())->getPokeName() <<" Intimidate Ability has No Effect on " << enemy->getParty(enemy->getCurrent())->getPokeName() << "!" << endl << flush;
            usleep(750000);
        }

        if ((enemy->getParty(enemy->getCurrent())->getAbility()=="Intimidate"&&enemy->getParty(enemy->getCurrent())->getAbility()!="Clear Body")&&(turnCounter==1))
        {
            cout << enemy->getParty(enemy->getCurrent())->getPokeName() <<" Intimidate Ability has lowered " << enemy->getParty(enemy->getCurrent())->getPokeName() << " ATK!" <<endl << flush;
            usleep(750000);
            player->getParty(player->getCurrent())->setStatMultiplier(0,1,"-");
        }
        else if ((enemy->getParty(enemy->getCurrent())->getAbility()=="Intimidate"&&enemy->getParty(enemy->getCurrent())->getAbility()=="Clear Body")&&(turnCounter==1))
        {
            cout << enemy->getParty(enemy->getCurrent())->getPokeName() <<" Intimidate Ability has No Effect on " << enemy->getParty(enemy->getCurrent())->getPokeName() << "!" << endl << flush;
            usleep(750000);
        }

        if (player->getParty(player->getCurrent())->getDestiny()!=0)
        {
            player->getParty(player->getCurrent())->setDestiny(0);
        }
        if (enemy->getParty(enemy->getCurrent())->getDestiny()!=0)
        {
            enemy->getParty(enemy->getCurrent())->setDestiny(0);
        }

        if (player->getParty(player->getCurrent())->getFlinched()!=0)
        {
            player->getParty(player->getCurrent())->setFlinched(0);
        }
        if (enemy->getParty(enemy->getCurrent())->getFlinched()!=0)
        {
            enemy->getParty(enemy->getCurrent())->setFlinched(0);
        }

        // //do checks for cooldown >0 and cooldown <0 to perform certain moves etc.
        // if (player->getParty(player->getCurrent())->getCooldown()>0)
        // {
        //     player->getParty(player->getCurrent())->setCooldown(1,"-");
        // }
        // if (enemy->getParty(enemy->getCurrent())->getCooldown()>0)
        // {
        //     enemy->getParty(enemy->getCurrent())->setCooldown(1,"-");
        // }
        //reducing light screen timers by 1 per turn for players and changing stats if its active

        if (player->getParty(player->getCurrent())->getOutrage()==1)
        {
            player->getParty(player->getCurrent())->setOutrage(2);
        }
        else if (player->getParty(player->getCurrent())->getOutrage()==2)
        {
            int outrage=rand()%2;
            if (outrage==0)
            {
                player->getParty(player->getCurrent())->setOutrage(3);
            }
            else
            {
                player->getParty(player->getCurrent())->setOutrage(0);
                player->getParty(player->getCurrent())->setCondition(1,"Confused");
                cout << player->getParty(player->getCurrent())->getPokeName() << " has become Confused!" << endl << endl; 
            }
        }
        else if (player->getParty(player->getCurrent())->getOutrage()==3)
        {
            player->getParty(player->getCurrent())->setOutrage(0);
            player->getParty(player->getCurrent())->setCondition(1,"Confused");            
            cout << player->getParty(player->getCurrent())->getPokeName() << " has become Confused!" << endl << endl; 
        }


        if (enemy->getParty(enemy->getCurrent())->getOutrage()==1)
        {
            enemy->getParty(enemy->getCurrent())->setOutrage(2);
        }
        else if (enemy->getParty(enemy->getCurrent())->getOutrage()==2)
        {
            int outrage=rand()%2;
            if (outrage==0)
            {
                enemy->getParty(enemy->getCurrent())->setOutrage(3);
            }
            else
            {
                enemy->getParty(enemy->getCurrent())->setOutrage(0);
                enemy->getParty(enemy->getCurrent())->setCondition(1,"Confused");
                cout << enemy->getParty(enemy->getCurrent())->getPokeName() << " has become Confused!" << endl << endl; 
            }
        }
        else if (enemy->getParty(enemy->getCurrent())->getOutrage()==3)
        {
            enemy->getParty(enemy->getCurrent())->setOutrage(0);
            enemy->getParty(enemy->getCurrent())->setCondition(1,"Confused");            
            cout << enemy->getParty(enemy->getCurrent())->getPokeName() << " has become Confused!" << endl << endl; 
        }

        if (battle->getPlayerLightScreen()==5)
        {
            player->getParty(player->getCurrent())->setCurrent(4,1.5,"*");
            battle->setPlayerLightScreen(1,"-");
        }
        else if (battle->getPlayerLightScreen()>0)
        {
            battle->setPlayerLightScreen(1,"-");
            if (battle->getPlayerLightScreen()==0)
            {
                player->getParty(player->getCurrent())->setCurrent(4,1.5,"/");
            }
        }
        //reducing reflect timers by 1 per turn for players and changing stats if its active
        if (battle->getPlayerReflect()==5)
        {
            player->getParty(player->getCurrent())->setCurrent(2,1.5,"*");
            battle->setPlayerReflect(1,"-");
        }
        else if (battle->getPlayerReflect()>0)
        {
            battle->setPlayerReflect(1,"-");
            if (battle->getPlayerReflect()==0)
            {
                player->getParty(player->getCurrent())->setCurrent(2,1.5,"/");
            }
        }
        //reducing light screen timers by 1 per turn for enemy AI and changing stats if its active
        if (battle->getEnemyLightScreen()==5)
        {
            enemy->getParty(enemy->getCurrent())->setCurrent(4,1.5,"*");
            battle->setEnemyLightScreen(1,"-");
        }
        else if (battle->getEnemyLightScreen()>0)
        {
            battle->setEnemyLightScreen(1,"-");
            if (battle->getEnemyLightScreen()==0)
            {
                enemy->getParty(enemy->getCurrent())->setCurrent(4,1.5,"/");
            }
        }
        //reducing ref;ect timers by 1 per turn for enemy AI and changing stats if its active
        if (battle->getEnemyReflect()==5)
        {
            enemy->getParty(enemy->getCurrent())->setCurrent(2,1.5,"*");
            battle->setEnemyReflect(1,"-");
        }
        else if (battle->getEnemyReflect()>0)
        {
            battle->setEnemyReflect(1,"-");
            if (battle->getEnemyReflect()==0)
            {
                enemy->getParty(enemy->getCurrent())->setCurrent(2,1.5,"/");
            }
        }

        if (player->getParty(player->getCurrent())->getOutrage()!=0)
        {
            cout << endl << enemy->getName() << "'s Pokemon:" << endl;
            cout << enemy->getParty(enemy->getCurrent())->getPokeName() << "'s HP: "<< enemy->getParty(enemy->getCurrent())->getCurrent(0) << "/" <<enemy->getParty(enemy->getCurrent())->getBase(0)<< endl;
            cout << "Status Condition: " << enemy->getParty(enemy->getCurrent())->getCondition(0) << ", " << enemy->getParty(enemy->getCurrent())->getCondition(1) << endl;

            //print if light screen and/or reflect are up or not
            if (battle->getEnemyLightScreen()>0)
            {
                cout << "Enemy's Side of the field is covered in a Screen of Light" << endl;
            }

            if (battle->getEnemyReflect()>0)
            {
                cout << "Enemy's Side of the field is protected by a Wall of Reflecting Light" << endl;
            }
            
            cout << endl;

            //dispaying player's currnet pokemon's stats and conditions
            cout << player->getName() << "'s Pokemon:" << endl;
            cout << player->getParty(player->getCurrent())->getPokeName() << "'s HP: "<< player->getParty(player->getCurrent())->getCurrent(0) << "/" << player->getParty(player->getCurrent())->getBase(0) << endl;
            cout << "Status Condition: " << player->getParty(player->getCurrent())->getCondition(0) << ", " << player->getParty(player->getCurrent())->getCondition(1) << endl;

            if (battle->getPlayerLightScreen()>0)
            {
                cout << "Player's Side of the field is covered in a Screen of Light" << endl;
            }

            if (battle->getPlayerReflect()>0)
            {
                cout << "Player's Side of the field is protected by a Wall of Reflecting Light" << endl;
            }
            
            cout << endl << endl;
        }

        while (check!=0&&player->getParty(player->getCurrent())->getOutrage()==0)
        {
            //dispaying enemy AI's currnet pokemon's stats and conditions
            cout << endl << enemy->getName() << "'s Pokemon:" << endl;
            cout << enemy->getParty(enemy->getCurrent())->getPokeName() << "'s HP: "<< enemy->getParty(enemy->getCurrent())->getCurrent(0) << "/" <<enemy->getParty(enemy->getCurrent())->getBase(0)<< endl;
            cout << "Status Condition: " << enemy->getParty(enemy->getCurrent())->getCondition(0) << ", " << enemy->getParty(enemy->getCurrent())->getCondition(1) << endl;

            //print if light screen and/or reflect are up or not
            if (battle->getEnemyLightScreen()>0)
            {
                cout << "Enemy's Side of the field is covered in a Screen of Light" << endl;
            }

            if (battle->getEnemyReflect()>0)
            {
                cout << "Enemy's Side of the field is protected by a Wall of Reflecting Light" << endl;
            }
            
            cout << endl;

            //dispaying player's currnet pokemon's stats and conditions
            cout << player->getName() << "'s Pokemon:" << endl;
            cout << player->getParty(player->getCurrent())->getPokeName() << "'s HP: "<< player->getParty(player->getCurrent())->getCurrent(0) << "/" << player->getParty(player->getCurrent())->getBase(0) << endl;
            cout << "Status Condition: " << player->getParty(player->getCurrent())->getCondition(0) << ", " << player->getParty(player->getCurrent())->getCondition(1) << endl;

            if (battle->getPlayerLightScreen()>0)
            {
                cout << "Player's Side of the field is covered in a Screen of Light" << endl;
            }

            if (battle->getPlayerReflect()>0)
            {
                cout << "Player's Side of the field is protected by a Wall of Reflecting Light" << endl;
            }
            
            cout << endl;

            if (player->getParty(player->getCurrent())->getCooldown()==0)
            {
                cout << "What would you like to do?: (1 = Attack, 2 = Use Item, 3 = Switch) ";
                cin >> choice;

                while ((choice<1||choice>3)||(cin.fail()==true))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // prevents crashing by ignoring invalid inputs
                    cout << "Please Try again: (1 = Attack, 2 = Use Item, 3 = Switch) ";
                    cin >> choice;
                    if ((!cin.fail())&&(choice>=1&&choice<=3))
                    {
                        break;
                    }
                }

                //accepting input from user (attack item or switch)
                cout << endl;
                if (choice==1)
                {
                    choices = battle->playerBattle(player);
                }
                else if (choice==2)
                {

                    choices = battle->playerItem(player);
                }
                else if (choice==3)
                {

                    choices = battle->playerSwitch(player,enemy);
                }
            }
            else if (player->getParty(player->getCurrent())->getCooldown()!=0)
            {
                if (player->getParty(player->getCurrent())->getCooldown()<0)    //if a move has a cooldown force the user to not be able to do anything this turn
                {
                    cout << player->getParty(player->getCurrent())->getPokeName() << " is still RECOVERING" << endl << flush;
                    usleep(1500000);
                }

                break;
            }

            if (choices!=-1)
            {
                check=0;
                if (choice==3)
                {
                    switchedP=1;
                }
            }

            if (choices==-1)
            {
                check=1;
            }
        }
        //player switching into spikes increasing damage per amount of spikes laid
        if (battle->getEnemySpikes()>0&&choice==3)
        {
            switch (battle->getEnemySpikes())
            {
                case 1:
                {
                    player->getParty(player->getCurrent())->setCurrent(0,((1/8)*player->getParty(player->getCurrent())->getBase(0)),"-");
                    break;
                }
                case 2:
                {
                    player->getParty(player->getCurrent())->setCurrent(0,((1/6)*player->getParty(player->getCurrent())->getBase(0)),"-");
                    break;
                }
                default:
                {
                    player->getParty(player->getCurrent())->setCurrent(0,((1/4)*player->getParty(player->getCurrent())->getBase(0)),"-");
                    break;
                }
            }
        }


        //enemy turn
        //once teams have been created, call what team their versing, which champions team, the have functions within for what pokemon is out and what moves it will do.


        //check if player and enemy can even move (status conditions etc).
        
        enemyCheck = battle->enemySwitch(player,enemy);

        if (enemyCheck!=-1)
        {
            enemyCheck = battle->enemyItem(enemy,player,battle);
            if (enemyCheck!=-2)
            {
                enemyCheck = battle->enemyAttack(player,enemy,battle);
            }
        }
        else if (enemyCheck==-1)
        {
            switchedE=2;
        }

        if (enemyCheck==-1&&battle->getPlayerSpikes()>0)
        {
            switch (battle->getPlayerSpikes())
            {
                case 1:
                {
                    enemy->getParty(enemy->getCurrent())->setCurrent(0,((1/8)*enemy->getParty(enemy->getCurrent())->getBase(0)),"-");
                    break;
                }
                case 2:
                {
                    enemy->getParty(enemy->getCurrent())->setCurrent(0,((1/6)*enemy->getParty(enemy->getCurrent())->getBase(0)),"-");
                    break;
                }
                default:
                {
                    enemy->getParty(enemy->getCurrent())->setCurrent(0,((1/4)*enemy->getParty(enemy->getCurrent())->getBase(0)),"-");
                    break;
                }
            }
        }


        //condition cooldowns, wkaing player pokemon up/un-freezing if the conditincool down number of turns have passed
        if (player->getParty(player->getCurrent())->getConditionCool(0)>0)
        {
            player->getParty(player->getCurrent())->setConditionCool(0,1,"-");
            if (player->getParty(player->getCurrent())->getConditionCool(0)==0&&player->getParty(player->getCurrent())->getCondition(0)=="Sleeping")
            {
                cout << player->getParty(player->getCurrent())->getPokeName() << " is no longer ASLEEP!" << endl;
                player->getParty(player->getCurrent())->setCondition(0,"None");
            }
        }

        if (choice==1&&player->getParty(player->getCurrent())->getCondition(0)=="Frozen")
        {
            chance = rand()%100;
            if (chance<=20)
            {
                player->getParty(player->getCurrent())->setCondition(0,"None");
                choice=-10;
            }
        }

        if (player->getParty(player->getCurrent())->getCondition(0)=="Sleeping"||player->getParty(player->getCurrent())->getCondition(0)=="Frozen")
        {
            if (player->getParty(player->getCurrent())->getCondition(0)=="Sleeping"&&(choice==1&&player->getParty(player->getCurrent())->getMoves(choices)->getMoveName()=="SleepTalk"))
            {
                //skip this choice, if break might break while loop for whole turns thing, come up with another solution later?
            }
            else
            {
                choice=-10;
            }
        }

        if (player->getParty(player->getCurrent())->getCondition(0)=="Paralyzed")   //force player pokemon to be unable to move if paralyzed (25% chance)
        {
            chance = rand()%100;
            if (chance<=25&&player->getName()!="TestMAN")
            {
                cout << player->getParty(player->getCurrent())->getPokeName() << "'s is Paralyzed and unable to move!" << endl;
                choice=-10;
            }
        }

//        confusedP=battle->confusionProc(player->getParty(player->getCurrent()),choice);
        //condition cooldowns, wkaing enemy AI pokemon up/un-freezing if the conditincool down number of turns have passed

        if (enemy->getParty(enemy->getCurrent())->getConditionCool(0)>0)
        {
            enemy->getParty(enemy->getCurrent())->setConditionCool(0,1,"-");
            if (enemy->getParty(enemy->getCurrent())->getConditionCool(0)==0&&enemy->getParty(enemy->getCurrent())->getCondition(0)=="Sleeping")
            {
                cout << enemy->getParty(enemy->getCurrent())->getPokeName() << " is no longer ALSEEP!" << endl;
                enemy->getParty(enemy->getCurrent())->setCondition(0,"None");
                choice=-10;
            }
        }

        if (enemyCheck>=0&&enemy->getParty(enemy->getCurrent())->getCondition(0)=="Frozen")
        {
            chance = rand()%100;
            if (chance<=20)
            {
                enemy->getParty(enemy->getCurrent())->setCondition(0,"None");
            }
        }

        if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Sleeping"||enemy->getParty(enemy->getCurrent())->getCondition(0)=="Frozen")
        {
            enemyCheck=-10;
        }

        if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Paralyzed")     //force enemy AI pokemon to be unable to move if paralyzed (25% chance)
        {
            chance = rand()%100;
            if (chance<=25&&player->getName()!="TestMAN")
            {
                cout << enemy->getParty(enemy->getCurrent())->getPokeName() << "'s is Paralyzed and unable to move!" << endl;
                enemyCheck=-10;
            }
        }

//        if (enemyCheck>=0)
//        {
//            confusedE=battle->confusionProc(enemy->getParty(enemy->getCurrent()),1);
//        }

        //death system which forces switcihng and checks for end states
        if (player->getParty(player->getCurrent())->getCurrent(0)<=0)
        {
            checkP = battle->playerSwitch(player,enemy);
            switchedP=1;                                //if current player pokemon dies force them to switch
        }
        if (checkP==-1)
        {
            cout << "Player is out of usable POKEMON, PLAYER LOSES!!" << endl;      //return 0 if player is out of usuable pokemon (Player lose state)
            return results;
        }

        if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
        {
            checkE = battle->enemySwitch(player,enemy);
            switchedE=1;                                //if current enemy pokemon dies force them to switch
        }
        if (checkE==-1)
        {
            cout << "Enemy is out of usable POKEMON, PLAYER WINS!!" << endl;         //return 1 if enemy AI is out of usuable pokemon (Player win state)
            int counter=0;
            for (int i=0;i<6;i++)
            {
                if (player->getParty(i)->getCurrent(0)>0)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
            results=1;

            if (counter==6)
            {
                results=1.5;
            }
            return results;
        }

        //figuring out who moves first
        if (player->getParty(player->getCurrent())->getCurrent(0)>0&&enemy->getParty(enemy->getCurrent())->getCurrent(0)>0)
        {
            if (enemyCheck>=0&&choice!=1)
            {
                if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()!="Status")
                {
                    if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                    {
                        battle->turnAttack(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),enemyCheck,"Enemy");
                    }
                }
                else if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()=="Status")
                {
                    if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                    {
                        battle->turnStatus(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),"Enemy",enemyCheck);
                    }                
                }
            }
            else if (enemyCheck<0&&choice==1)
            {
                if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()!="Status")
                {
                    if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                    {
                        battle->turnAttack(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),choices,"Player");
                    }
                }
                else if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()=="Status")
                {
                    if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                    {
                        battle->turnStatus(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),"Player",choices);
                    }
                }
            }
            else if (enemyCheck>=0&&choice==1)
            {
                if (player->getParty(player->getCurrent())->getMoves(choices)->getMovePriority()>enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMovePriority())
                {
                    confusedP=battle->confusionProc(player->getParty(player->getCurrent()),choice);

                    if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()!="Status")
                    {
                        if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                        {
                            battle->turnAttack(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),choices,"Player");
                        }
                    }
                    else if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()=="Status")
                    {
                        if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                        {
                            battle->turnStatus(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),"Player",choices);
                        }
                    }

                    if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
                    {
                        checkE = battle->enemySwitch(player,enemy);
                        switchedE=1;
                        confusedE=0;
                    }

                    if (enemyCheck>=0)
                    {
                        confusedE=battle->confusionProc(enemy->getParty(enemy->getCurrent()),1);
                    }

                    if (checkE!=-10&&switchedE==0)
                    {
                        if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()!="Status")
                        {
                            if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                            {
                                battle->turnAttack(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),enemyCheck,"Enemy");
                            }
                        }
                        else if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()=="Status")
                        {
                            if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                            {
                                battle->turnStatus(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),"Enemy",enemyCheck);
                            }
                        }
                    }
                }
                else if (player->getParty(player->getCurrent())->getMoves(choices)->getMovePriority()<enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMovePriority())
                {
                    if (enemyCheck>=0)
                    {
                        confusedE=battle->confusionProc(enemy->getParty(enemy->getCurrent()),1);
                    }

                    if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()!="Status")
                    {
                        if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                        {
                            battle->turnAttack(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),enemyCheck,"Enemy");
                        }
                    }
                    else if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()=="Status")
                    {
                        if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                        {
                            battle->turnStatus(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),"Enemy",enemyCheck);
                        }
                    }

                    if (player->getParty(player->getCurrent())->getCurrent(0)<=0)
                    {
                        checkP = battle->playerSwitch(player,enemy);
                        switchedP=1;
                        confusedP=0;
                    }

                    confusedP=battle->confusionProc(player->getParty(player->getCurrent()),choice);

                    if (checkP!=-10&&switchedP==0)
                    {
                        if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()!="Status")
                        {
                            if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                            {
                                battle->turnAttack(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),choices,"Player");
                            }
                        }
                        else if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()=="Status")
                        {
                            if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                            {
                                battle->turnStatus(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),"Player",choices);
                            }
                        }
                    }
                }
                else if (player->getParty(player->getCurrent())->getMoves(choices)->getMovePriority()==enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMovePriority())
                {
                    double speedPlayer = player->getParty(player->getCurrent())->getCurrent(5)*battle->stageMulti(player->getParty(player->getCurrent())->getStatMultiplier(4),4);
                    double speedEnemy = enemy->getParty(enemy->getCurrent())->getCurrent(5)*battle->stageMulti(enemy->getParty(enemy->getCurrent())->getStatMultiplier(4),4);

                    if (player->getParty(player->getCurrent())->getCondition(0)=="Paralyzed")
                    {
                        speedPlayer *= (1/2);
                    }
                    if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Paralyzed")
                    {
                        speedEnemy *= (1/2);
                    }

                    if (speedPlayer>speedEnemy)
                    {
                        confusedP=battle->confusionProc(player->getParty(player->getCurrent()),choice);

                        if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()!="Status")
                        {
                            if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                            {
                                battle->turnAttack(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),choices,"Player");
                            }
                        }
                        else if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()=="Status")
                        {
                            if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                            {
                                battle->turnStatus(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),"Player",choices);
                            }
                        }

                        if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
                        {
                            checkE = battle->enemySwitch(player,enemy);
                            switchedE=1;
                            confusedE=0;
                        }

                        if (enemyCheck>=0)
                        {
                            confusedE=battle->confusionProc(enemy->getParty(enemy->getCurrent()),1);
                        }

                        if (checkE!=-10&&switchedE==0)
                        {
                            if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()!="Status")
                            {
                                if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnAttack(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),enemyCheck,"Enemy");
                                }
                            }
                            else if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()=="Status")
                            {
                                if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnStatus(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),"Enemy",enemyCheck);
                                }
                            }
                        }
                    }
                    else if (speedPlayer==speedEnemy)
                    {
                        int flip = rand()%2;
                        if (flip==0)
                        {
                            confusedP=battle->confusionProc(player->getParty(player->getCurrent()),choice);

                            if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()!="Status")
                            {
                                if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnAttack(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),choices,"Player");
                                }
                            }
                            else if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()=="Status")
                            {
                                if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnStatus(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),"Player",choices);
                                }
                            }

                            if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
                            {
                                checkE = battle->enemySwitch(player,enemy);
                                switchedE=1;
                                confusedE=0;
                            }

                            if (enemyCheck>=0)
                            {
                                confusedE=battle->confusionProc(enemy->getParty(enemy->getCurrent()),1);
                            }

                            if (checkE!=-10&&switchedE==0)
                            {
                                if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()!="Status")
                                {
                                    if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                                    {
                                        battle->turnAttack(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),enemyCheck,"Enemy");
                                    }
                                }
                                else if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()=="Status")
                                {
                                    if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                                    {
                                        battle->turnStatus(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),"Enemy",enemyCheck);
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (enemyCheck>=0)
                            {
                                confusedE=battle->confusionProc(enemy->getParty(enemy->getCurrent()),1);
                            }

                            if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()!="Status")
                            {
                                if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnAttack(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),enemyCheck,"Enemy");
                                }
                            }
                            else if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()=="Status")
                            {
                                if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnStatus(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),"Enemy",enemyCheck);
                                }
                            }

                            if (player->getParty(player->getCurrent())->getCurrent(0)<=0)
                            {
                                checkP = battle->playerSwitch(player,enemy);
                                switchedP=1;
                                confusedP=0;
                            }
                            
                            confusedP=battle->confusionProc(player->getParty(player->getCurrent()),choice);

                            if (checkP!=-10&&switchedP==0)
                            {
                                if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()!="Status")
                                {
                                    if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                                    {
                                        battle->turnAttack(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),choices,"Player");
                                    }
                                }
                                else if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()=="Status")
                                {
                                    if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                                    {
                                        battle->turnStatus(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),"Player",choices);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (enemyCheck>=0)
                        {
                            confusedE=battle->confusionProc(enemy->getParty(enemy->getCurrent()),1);
                        }

                        if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()!="Status")
                        {
                            if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                            {
                                battle->turnAttack(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),enemyCheck,"Enemy");
                            }
                        }
                        else if (enemy->getParty(enemy->getCurrent())->getMoves(enemyCheck)->getMoveType()=="Status")
                        {
                            if (confusedE==0&&enemy->getParty(enemy->getCurrent())->getFlinched()==0)
                            {
                                battle->turnStatus(enemy->getParty(enemy->getCurrent()),player->getParty(player->getCurrent()),"Enemy",enemyCheck);
                            }
                        }

                        if (player->getParty(player->getCurrent())->getCurrent(0)<=0)
                        {
                            checkP = battle->playerSwitch(player,enemy);
                            switchedP=1;
                            confusedP=0;
                        }

                        confusedP=battle->confusionProc(player->getParty(player->getCurrent()),choice);

                        if (checkP!=-10&&switchedP==0)
                        {
                            if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()!="Status")
                            {
                                if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnAttack(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),choices,"Player");
                                }
                            }
                            else if (player->getParty(player->getCurrent())->getMoves(choices)->getMoveType()=="Status")
                            {
                                if (confusedP==0&&player->getParty(player->getCurrent())->getFlinched()==0)
                                {
                                    battle->turnStatus(player->getParty(player->getCurrent()),enemy->getParty(enemy->getCurrent()),"Player",choices);
                                }
                            }
                        }
                    }
                }
            }
        }

        if (enemy->getParty(enemy->getCurrent())->getFlinched()!=0)
        {
            cout << enemy->getParty(enemy->getCurrent())->getPokeName() << " FLINCHED and was Unable to Attack!" << endl << flush;
            usleep(750000);
        }
        if (player->getParty(player->getCurrent())->getFlinched()!=0)
        {
            cout << player->getParty(player->getCurrent())->getPokeName() << " FLINCHED and was Unable to Attack!" << endl << flush;
            usleep(750000);
        }

        //damaging status effects on Player pokemon (Poison, Burned)
        if (player->getParty(player->getCurrent())->getCurrent(0)>0)
        {
            if (player->getParty(player->getCurrent())->getCondition(0)=="Poisoned"||player->getParty(player->getCurrent())->getCondition(0)=="Burned")
            {
                player->getParty(player->getCurrent())->setCurrent(0,((1/16)*player->getParty(player->getCurrent())->getBase(0)),"-");

                if (player->getParty(player->getCurrent())->getCondition(0)=="Poisoned")
                {
                    cout << player->getParty(player->getCurrent())->getPokeName() << " has been hurt by the POISON" << endl;
                }
                else if (player->getParty(player->getCurrent())->getCondition(0)=="Burned")
                {
                    cout << player->getParty(player->getCurrent())->getPokeName() << " has been hurt by the BURN" << endl;
                }
                if (player->getParty(player->getCurrent())->getCurrent(0)<0)
                {
                    player->getParty(player->getCurrent())->setCurrent(0,0,"=");
                }
            }
            //damaging status effects on Player pokemon (badly Poisoned)
            if (player->getParty(player->getCurrent())->getCondition(0)=="Badly Poisoned")
            {
                player->getParty(player->getCurrent())->setCurrent(0,(((1/16)*player->getParty(player->getCurrent())->getBadCounter())*player->getParty(player->getCurrent())->getBase(0)),"-");
                player->getParty(player->getCurrent())->setBadCounter(1,"+");
                cout << player->getParty(player->getCurrent())->getPokeName() << " has been hurt by the POISON" << endl;
                if (player->getParty(player->getCurrent())->getCurrent(0)<0)
                {
                    player->getParty(player->getCurrent())->setCurrent(0,0,"=");
                }
            }
        }
        //damaging status effects on Enemy AI pokemon (Poison, Burned)
        if (enemy->getParty(player->getCurrent())->getCurrent(0)>0)
        {
            if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Poisoned"||enemy->getParty(enemy->getCurrent())->getCondition(0)=="Burned")
            {
                enemy->getParty(enemy->getCurrent())->setCurrent(0,((1/16)*enemy->getParty(enemy->getCurrent())->getBase(0)),"-");

                if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Poisoned")
                {
                    cout << enemy->getParty(enemy->getCurrent())->getPokeName() << " has been hurt by the POISON" << endl;
                }
                else if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Burned")
                {
                    cout << enemy->getParty(enemy->getCurrent())->getPokeName() << " has been hurt by the BURN" << endl;
                }
                if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<0)
                {
                    enemy->getParty(enemy->getCurrent())->setCurrent(0,0,"=");
                }
            }
            //damaging status effects on enemy AI pokemon (badly Poisoned)
            if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Badly Poisoned")
            {
                enemy->getParty(enemy->getCurrent())->setCurrent(0,(((1/16)*enemy->getParty(enemy->getCurrent())->getBadCounter())*enemy->getParty(enemy->getCurrent())->getBase(0)),"-");
                enemy->getParty(enemy->getCurrent())->setBadCounter(1,"+");
                cout << enemy->getParty(enemy->getCurrent())->getPokeName() << " has been hurt by the POISON" << endl;
                if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<0)
                {
                    enemy->getParty(enemy->getCurrent())->setCurrent(0,0,"=");
                }
            }
        }

        //second death check in case of pokemon death after moves have been used. (smae as above death systm)
        if (player->getParty(player->getCurrent())->getCurrent(0)<=0)
        {
            checkP = battle->playerSwitch(player,enemy);
        }
        if (checkP==-10)
        {
            cout << "Player is out of usable POKEMON, ENEMY WINS!!" << endl;
            return results;
        }
        if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<=0)
        {
            checkE = battle->enemySwitch(player,enemy);
        }
        if (checkE==-10)
        {
            cout << "Enemy is out of usable POKEMON, PLAYER WINS!!" << endl;
            int counter=0;
            for (int i=0;i<6;i++)
            {
                if (player->getParty(i)->getCurrent(0)>0)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
            results=1;

            if (counter==6)
            {
                results=1.5;
            }
            return results;
        }
    }

    return results;
}
