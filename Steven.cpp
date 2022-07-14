#include <iostream>
#include "Steven.h"
#include <string>
#include <unistd.h>
using namespace std;

Steven::Steven():Battle()
{

}

int Steven::enemyAttack(Player* player, Enemy* enemy, Battle* battle)
{
    double stab=1.0;
    double burn=1.0;
    double weather=1.0;
    double effective=1.0;

    //implement weather changes if weather is completely implemented

//    for (int i=0;i<4;i++)
//    {
//        double random=rand()%15+85;
//        if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()!="Status"&&enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePP()>0)
//        {
//            effective = weakness(player->getParty(player->getCurrent())->getTypeNum(),player->getParty(player->getCurrent())->getTypes(),enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveEle());
//            for (int j=0;j<enemy->getParty(enemy->getCurrent())->getTypeNum();j++)
//            {
//                if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveEle()==enemy->getParty(enemy->getCurrent())->getType(j))
//                {
//                    stab=1.5;
//                    break;
//                }
//            }
//            if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()=="Physical")
//            {
//                if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Burned")
//                {
//                    burn=0.5;
//                }
//                damage[i]= (((((2*50)/5)+2)*enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePow()*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4)))/50+2)*weather*stab*random*(enemy->getParty(enemy->getCurrent())->getCurrent(1)/player->getParty(player->getCurrent())->getCurrent(2))*burn*effective;
//            }
//            else
//            damage[i]= (((((2*50)/5)+2)*enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePow()*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4)))/50+2)*weather*stab*random*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4))*burn*effective;
//        }
//        else
//        leave++;
//    }
//
//    if (leave==4)
//    {
//        return -1;
//    }

    double damage=0.0;
    int ppCheck=0;
    double Effect[2]={0,1.0};
    for (int i=0;i<4;i++)
    {
        if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()!="Status"&&enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePP()>0)
        {
            effective = weakness(player->getParty(player->getCurrent())->getTypeNum(),player->getParty(player->getCurrent())->getTypes(),enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveEle());
            if (effective>Effect[0])
            {
                Effect[1]=effective;
                Effect[0]=i;
            }
            for (int j=0;j<enemy->getParty(enemy->getCurrent())->getTypeNum();j++)
            {
                if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveEle()==enemy->getParty(enemy->getCurrent())->getType(j))
                {
                    stab=1.5;
                    break;
                }
            }
            if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()=="Physical")
            {
                if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Burned")
                {
                    burn=0.5;
                }
                damage= (((((2*50)/5)+2)*enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePow()*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4)))/50+2)*weather*stab*0.85*(enemy->getParty(enemy->getCurrent())->getCurrent(1)/player->getParty(player->getCurrent())->getCurrent(2))*burn*effective;
            }
            else if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()=="Special")
            {
            damage= (((((2*50)/5)+2)*enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePow()*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4)))/50+2)*weather*stab*0.85*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4))*burn*effective;
            }

            if (damage>=player->getParty(player->getCurrent())->getCurrent(0))
            {
                return i;
            }
        }
        if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePP()>0)
        {
            ppCheck++;
        }
    }

    if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Cradily")
    {
        if (player->getParty(player->getCurrent())->getCondition(1)=="Not Confused"&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
        {
            return 0;
        }
    }

    if (Effect[1]>1.0&&enemy->getParty(enemy->getCurrent())->getMoves(Effect[0])->getMovePP()>0)
    {
        return Effect[0];
    }

    while (ppCheck>0)
    {
        int chance=rand()%4;
        if (enemy->getParty(enemy->getCurrent())->getMoves(chance)->getMovePP()>0)
        {
            return chance;   
        }
    }

    //damage = (((((2*50)/5)+2)*power*(atk/def))/50+2)*modifier

    //modifier = weather*crit*(random between 85 and 100)*STAB*effective*burn*any other condition

    ///REWRITE!!! compare moves based on damage and then have conditions for certain moves (hyper beam, status moves etc)

//put unique requirements here

//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Aggron")
//    {
//        int chance=rand()%10;
//        if (chance==0&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
//        {
//            return 0;
//        }
//    }
//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Claydol")
//    {
//        if (battle->getEnemyLightScreen()==0&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
//        {
//            return 0;
//        }
//        else if (battle->getEnemyReflect()==0&&enemy->getParty(enemy->getCurrent())->getMoves(2)->getMovePP()>0)
//        {
//            return 2;
//        }
//    }
//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Skarmory")
//    {
//        if (battle->getEnemySpikes()==0&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
//        {
//            return 3;
//        }
//        else if ((battle->getEnemySpikes()>0&&battle->getEnemySpikes()<4)&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
//        {
//            int chance=rand()%10;
//            if (chance<2)
//            {
//                return 3;
//            }
//            else if ((player->getParty(player->getCurrent())->getCondition(0)!="Badly Poisoned"&&(chance>=2&&chance<5))&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
//            {
//                return 2;
//            }
//        }
//    }

//    double max[3]={0.0,0.0,0.0};
//    int maxCount=0;
//    int ppCount=0;
//    for (int i=0;i<4;i++)
//    {
//        if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePP()>0&&enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()!="Status")
//        {
//            maxCount++;
//            effective = weakness(player->getParty(player->getCurrent())->getTypeNum(),player->getParty(player->getCurrent())->getTypes(),enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveEle());
//            for (int j=0;j<enemy->getParty(enemy->getCurrent())->getTypeNum();j++)
//            {
//                if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveEle()==enemy->getParty(enemy->getCurrent())->getType(j))
//                {
//                    stab=1.5;
//                    break;
//                }
//            }
//            if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()=="Physical")
//            {
//                if (enemy->getParty(enemy->getCurrent())->getCondition(0)=="Burned")
//                {
//                    burn=0.5;
//                }
//                max[0]= (((((2*50)/5)+2)*enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePow()*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4)))/50+2)*weather*stab*0.85*(enemy->getParty(enemy->getCurrent())->getCurrent(1)/player->getParty(player->getCurrent())->getCurrent(2))*burn*effective;
//            }
//            else if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveType()=="Special")
//            {
//            max[0]= (((((2*50)/5)+2)*enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePow()*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4)))/50+2)*weather*stab*0.85*(enemy->getParty(enemy->getCurrent())->getCurrent(3)/player->getParty(player->getCurrent())->getCurrent(4))*burn*effective;
//            }
//
//            if (max[0]>2*max[1]&&enemy->getParty(enemy->getCurrent())->getMoves(i)->getMoveName()=="Giga Impact")
//            {
//                max[2]=i;
//            }
//            else if (max[0]>max[1])
//            {
//                max[2]=i;
//            }
//        }
//        else if (enemy->getParty(enemy->getCurrent())->getMoves(i)->getMovePP()>0)
//        {
//            ppCount++;
//        }
//    }
//    
//    if (maxCount>0)
//    {
//        return max[2];
//    }
//    else if (ppCount>0)
//    {
//        while (true)
//        {
//            int chance=rand()%4;
//            if (enemy->getParty(enemy->getCurrent())->getMoves(chance)->getMovePP()>0)
//            {
//                return chance;
//            }
//        }
//    }

//
//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Cradily")
//    {
//
//        if (player->getParty(player->getCurrent())->getCondition(1)=="Not Confused"&&enemy->getParty(enemy->getCurrent())->getMoves(1)->getMovePP()>0)
//        {
//            return 1;
//        }
//
//        if (((enemy->getParty(enemy->getCurrent())->getCurrent(0)<((1/3)*enemy->getParty(enemy->getCurrent())->getBase(0))) && (damage[3]>((3/5)*player->getParty(player->getCurrent())->getCurrent(0)))) && enemy->getParty(enemy->getCurrent())->getMoves(3)->getMovePP()>0)
//        {
//            return 3;
//        }
//
//        int max=0;
//        for (int i=0;i<4;i++)
//        {
//            if (damage[i]>damage[max])
//            {
//                max=i;
//            }
//        }
//
//        return max;
//
//    }
//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Armaldo")
//    {
//        int max=0;
//        for (int i=0;i<4;i++)
//        {
//            if (damage[i]>damage[max])
//            {
//                max=i;
//            }
//        }
//        return max;
//    }
//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Aggron")
//    {
//
//        int max=0;
//        for (int i=0;i<4;i++)
//        {
//            if (damage[i]>damage[max])
//            {
//                max=i;
//            }
//        }
//
//        if (((damage[max]<((3/5)*player->getParty(player->getCurrent())->getCurrent(0)))&&(enemy->getParty(enemy->getCurrent())->getCurrent(0)>=((3/4)*enemy->getParty(enemy->getCurrent())->getBase(0))))&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
//        {
//            return 0;
//        }
//
//        if ((enemy->getParty(enemy->getCurrent())->getMoves(max)->getMoveName()=="Head Smash"&&(enemy->getParty(enemy->getCurrent())->getMoves(max)->getMovePP()>0))&&((damage[max]>=((7/10)*player->getParty(player->getCurrent())->getBase(0)))||damage[max]>=player->getParty(player->getCurrent())->getCurrent(0)))
//        {
//            return max;
//        }
//
//        return max;
//
//    }
//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Claydol")
//    {
//        int max=0;
//        for (int i=0;i<4;i++)
//        {
//            if (damage[i]>damage[max])
//            {
//                max=i;
//            }
//        }
//
//        if (((damage[max]<((3/5)*enemy->getParty(enemy->getCurrent())->getCurrent(0)))&&enemyReflect==0)&&enemy->getParty(enemy->getCurrent())->getMoves(2)->getMovePP()>0)
//        {
//            return 2;
//        }
//        else if (((damage[max]<((3/5)*enemy->getParty(enemy->getCurrent())->getCurrent(0)))&&enemyLightScreen==0)&&enemy->getParty(enemy->getCurrent())->getMoves(1)->getMovePP()>0)
//        {
//            return 1;
//        }
//
//        return max;
//    }
//    else if (enemy->getParty(enemy->getCurrent())->getPokeName()=="Skarmory")
//    {
//        int max=0;
//        for (int i=0;i<4;i++)
//        {
//            if (damage[i]>damage[max])
//            {
//                max=i;
//            }
//        }
//
//        if (enemySpikes==0&&enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0)
//        {
//            return 0;
//        }
//
//        if (((damage[max]<((65/100)*player->getParty(player->getCurrent())->getCurrent(0)))&&player->getParty(player->getCurrent())->getCondition(0)=="None")&&enemy->getParty(enemy->getCurrent())->getMoves(1)->getMovePP()>0)
//        {
//            return 1;
//        }
//
//        if (((damage[max]<((55/100)*player->getParty(player->getCurrent())->getCurrent(0)))&&enemySpikes<=3)&&(enemy->getParty(enemy->getCurrent())->getMoves(0)->getMovePP()>0))
//        {
//            return 0;
//        }
//
//        return max;
//    }
//
//    return -69;

    return 0;
}

int Steven::enemyItem(Enemy* enemy,Player* player, Battle* battle)
{

//    //revive
//    if (enemy->getParty(0)->getCurrent(0)==0&&enemy->getItemUse(3)>0)
//    {
//        enemy->getParty(0)->setCurrent(0,((1/2)*enemy->getParty(0)->getBase(0)),"=");
//        enemy->setItemUse(3,1,"-");
//        return -2;
//    }
//    else if (enemy->getParty(3)->getCurrent(0)==0&&enemy->getItemUse(3)>0)
//    {
//        enemy->getParty(3)->setCurrent(0,((1/2)*enemy->getParty(3)->getBase(0)),"=");
//        enemy->setItemUse(3,1,"-");
//        return -2;
//    }

    if (enemy->getParty(enemy->getCurrent())->getCurrent(0)<((35.0/100.0)*enemy->getParty(enemy->getCurrent())->getBase(0)))
    {
        double weak=1.0;
        for (int i=0;i<player->getParty(player->getCurrent())->getTypeNum();i++)
        {
            weak *= battle->weakness(enemy->getParty(enemy->getCurrent())->getTypeNum(), enemy->getParty(enemy->getCurrent())->getTypes(),player->getParty(player->getCurrent())->getType(i));
        }
        if (weak<=1.0)
        {
            if ((enemy->getParty(enemy->getCurrent())->getCondition(0)!="None"||enemy->getParty(enemy->getCurrent())->getCondition(1)!="Not Confused")&&enemy->getItemUse(0)>0)
            {
                enemy->getParty(enemy->getCurrent())->setCurrent(0,enemy->getParty(enemy->getCurrent())->getBase(0),"=");
                enemy->getParty(enemy->getCurrent())->setCondition(0,"None");
                enemy->getParty(enemy->getCurrent())->setCondition(1,"Not Confused");
                enemy->setItemUse(0,1,"-");            
                cout << "Steven used a FULL RESTORE on " << enemy->getParty(enemy->getCurrent())->getPokeName() << ", Healing it to FULL HP and clearing all STATUS CONDITIONS!" << endl << flush;
                usleep(1500000);
                return -2;
            }
            else if (enemy->getItemUse(1)>0)
            {
                enemy->getParty(enemy->getCurrent())->setCurrent(0,200,"+");
                cout << "Steven used a HYPER POTION on " << enemy->getParty(enemy->getCurrent())->getPokeName() << ", Healing it for ";
                if (enemy->getParty(enemy->getCurrent())->getCurrent(0)>enemy->getParty(enemy->getCurrent())->getBase(0))
                {
                    cout << 200-(enemy->getParty(enemy->getCurrent())->getCurrent(0)-enemy->getParty(enemy->getCurrent())->getBase(0)) << " HP!" << endl << flush;
                    usleep(1500000);
                    enemy->getParty(enemy->getCurrent())->setCurrent(0,enemy->getParty(enemy->getCurrent())->getBase(0),"=");
                }
                else
                {
                    cout << "200 HP!" << endl << flush;
                    usleep(1500000);
                }
                enemy->setItemUse(1,1,"-");
                return -2;
            }
            else if (enemy->getItemUse(0)>0)
            {
                enemy->getParty(enemy->getCurrent())->setCurrent(0,enemy->getParty(enemy->getCurrent())->getBase(0),"=");
                enemy->getParty(enemy->getCurrent())->setCondition(0,"None");
                enemy->getParty(enemy->getCurrent())->setCondition(1,"Not Confused");
                enemy->setItemUse(0,1,"-");
                cout << "Steven used a FULL RESTORE on " << enemy->getParty(enemy->getCurrent())->getPokeName() << ", Healing it to FULL HP and clearing all STATUS CONDITIONS!" << endl << flush;
                usleep(1500000);
                return -2;
            }
        }
    }
    int last=0;
    for (int i=0;i<6;i++)
    {
        if (enemy->getParty(i)->getCurrent(0)<=0)
        {
            last++;
        }
    }

    if (last==5&&enemy->getParty(enemy->getCurrent())->getCurrent(0)<((55.0/100.0)*enemy->getParty(enemy->getCurrent())->getBase(0)))
    {
        if ((enemy->getParty(enemy->getCurrent())->getCondition(0)!="None"||enemy->getParty(enemy->getCurrent())->getCondition(1)!="Not Confused")&&enemy->getItemUse(0)>0)
        {
            enemy->getParty(enemy->getCurrent())->setCurrent(0,enemy->getParty(enemy->getCurrent())->getBase(0),"=");
            enemy->getParty(enemy->getCurrent())->setCondition(0,"None");
            enemy->getParty(enemy->getCurrent())->setCondition(1,"Not Confused");
            enemy->setItemUse(0,1,"-");
            cout << "Steven used a FULL RESTORE on " << enemy->getParty(enemy->getCurrent())->getPokeName() << ", Healing it to FULL HP and clearing all STATUS CONDITIONS!" << endl << flush;
            usleep(1500000);
            return -2;
        }
        else if (enemy->getItemUse(1)>0)
        {
            enemy->getParty(enemy->getCurrent())->setCurrent(0,200,"+");
            cout << "Steven used a HYPER POTION on " << enemy->getParty(enemy->getCurrent())->getPokeName() << ", Healing it for ";
            if (enemy->getParty(enemy->getCurrent())->getCurrent(0)>enemy->getParty(enemy->getCurrent())->getBase(0))
            {
                cout << 200-(enemy->getParty(enemy->getCurrent())->getCurrent(0)-enemy->getParty(enemy->getCurrent())->getBase(0)) << " HP!" << endl << flush;
                usleep(1500000);
                enemy->getParty(enemy->getCurrent())->setCurrent(0,enemy->getParty(enemy->getCurrent())->getBase(0),"=");
            }
            else
            {
                cout << "200 HP!" << endl << flush;
                usleep(1500000);
            }
            enemy->setItemUse(1,1,"-");
            
            return -2;
        }
        else if (enemy->getItemUse(0)>0)
        {
            enemy->getParty(enemy->getCurrent())->setCurrent(0,enemy->getParty(enemy->getCurrent())->getBase(0),"=");
            enemy->getParty(enemy->getCurrent())->setCondition(0,"None");
            enemy->getParty(enemy->getCurrent())->setCondition(1,"Not Confused");
            enemy->setItemUse(0,1,"-");
            cout << "Steven used a FULL RESTORE on " << enemy->getParty(enemy->getCurrent())->getPokeName() << ", Healing it to FULL HP and clearing all STATUS CONDITIONS!" << endl << flush;
            usleep(1500000);
            return -2;
        }
    }
    return 1;


    //full restore

//    if (enemy->getItemUse(0)>0)
//    {
//        
//    }
//
//    if (lowHealthStat[0]>=2.0)
//    {
//        enemy->getParty(0)->setCurrent(0,enemy->getParty(0)->getBase(0),"=");
//        enemy->getParty(0)->setCondition(0,"None");
//        enemy->getParty(0)->setCondition(1,"Not Confused");
//        enemy->setItemUse(0,1,"-");
//        return -2;
//    }
//
//    //hyper potion
//
//
//    if (healthStat[0]>=2.0)
//    {
//        enemy->getParty(0)->setCurrent(0,200,"+");
//        if (enemy->getParty(0)->getCurrent(0)>enemy->getParty(0)->getBase(0))
//        {
//            enemy->getParty(0)->setCurrent(0,enemy->getParty(0)->getBase(0),"=");
//        }
//        enemy->setItemUse(1,1,"-");
//        return -2;
//    }
//
//    return 1;
//
}
