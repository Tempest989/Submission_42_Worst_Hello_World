#include "Pokemon.h"
#include <ctime>
#include <iostream>
using namespace std;

Pokemon::Pokemon()
{
    cooldown=0;
    badCounter=1;
    //transformed=0;
    condition[0]="None";
    condition[1]="Not Confused";
    conditionCool[0]=0; conditionCool[1]=0;
    typeNum=1;
    type[0]="None"; type[1]="None";
    pokeName="dead";
    damageLast=0; critLast=0;
    turnCount = 0;
    heldItem = "";
    impermeable=0;
    protect=0;
    roost=0;
    outrage=0;
    flinched=0;
    for (int i=0;i<6;i++)
    {
        statMultiplier[i]=0;
    }

    pokeName="No Pokemon";
    typeNum=2;
    type[0]="Ghost"; type[1]="Bug";

    moveset[0]=Moves(1);
    moveset[1]=Moves(2);
    moveset[2]=Moves(3);
    moveset[3]=Moves(4);
    //moves phantom force, x-scisor, shadow ball and hone claws

    current[0]=0; current[1]=85+rand()%71; current[2]=45+rand()%61; current[3]=31+rand()%59; current[4]=31+rand()%59; current[5]=40+rand()%61;
    ability = "Wonder Guard";
    abilityDescript = "Only Super-Effective moves can cause damage to this Pokemon.";

    for (int i=0;i<6;i++)
    {
        base[i]=current[i];
    }
}

Pokemon::Pokemon(int num)
{
    cooldown=0;
    badCounter=1;
    //transformed=0;
    condition[0]="None";
    condition[1]="Not Confused";
    conditionCool[0]=0; conditionCool[1]=0;
    typeNum=1;
    type[0]="None"; type[1]="None";
    pokeName="dead";
    damageLast=0; critLast=0;
    turnCount = 0;
    heldItem = "";
    impermeable=0;
    protect=0;
    roost=0;
    outrage=0;
    flinched=0;
    for (int i=0;i<6;i++)
    {
        statMultiplier[i]=0;
    }

    switch (num)
    {
    case 1:
    {
        pokeName="Raichu";
        type[0]="Electric"; type[1]="";
        typeNum=1;

        moveset[0]=Moves(5);
        moveset[1]=Moves(6);
        moveset[2]=Moves(7);
        moveset[3]=Moves(8);
        //moves thunderbolt, dig, focus blast, nasty plot

        current[0]=120+rand()%48; current[1]=85+rand()%99; current[2]=54+rand()%64; current[3]=85+rand()%72; current[4]=76+rand()%70; current[5]=103+rand()%76;
        ability = "Static";
        abilityDescript = "Inflict Paralysis on enemy upon being hit by a Physical type move.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];

        }
        break;
    }
    case 2:
    {
        pokeName="Shedinja";
        typeNum=2;
        type[0]="Ghost"; type[1]="Bug";

        moveset[0]=Moves(1);
        moveset[1]=Moves(2);
        moveset[2]=Moves(3);
        moveset[3]=Moves(4);
        //moves phantom force, x-scissor, shadow ball and hone claws

        current[0]=1; current[1]=85+rand()%72; current[2]=45+rand()%62; current[3]=31+rand()%60; current[4]=31+rand()%60; current[5]=40+rand()%62;
        ability = "Wonder Guard";
        abilityDescript = "Only Super-Effective moves can cause damage to this Pokemon.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }

        break;
    }
    case 3:
    {
        pokeName="Charizard";
        type[0]="Fire"; type[1]="Flying";
        typeNum=2;

        moveset[0]=Moves(75);
        moveset[1]=Moves(104);
        moveset[2]=Moves(12);
        moveset[3]=Moves(105);
        //move flare blitz, dragon dance, earthquake, dragon claw (change to flamethrower, blast burn, earthquake,roost)

        current[0]=138+rand()%47; current[1]=80+rand()%69; current[2]=74+rand()%69; current[3]=102+rand()%75; current[4]=81+rand()%69; current[5]=94+rand()%73;
        ability = "Blaze";
        abilityDescript = "Increases Power of User's Fire type moves by 50% when User is at or below 1/3 HP.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 4:
    {
        pokeName="Snorlax";
        type[0]="Normal"; type[1]="";
        typeNum=1;

        moveset[0]=Moves(106);
        moveset[1]=Moves(15);
        moveset[2]=Moves(107);
        moveset[3]=Moves(12);
        //move belly drum, rest, double edge, body slam (return, rest, sleep talk, earthquake)

        current[0]=220+rand()%48; current[1]=103+rand()%76; current[2]=63+rand()%66; current[3]=63+rand()%66; current[4]=103+rand()%76; current[5]=31+rand()%60;
        ability = "Thick Fat";
        abilityDescript = "User take 1/2 damage taken from Fire and Ice type moves.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 5:
    {
        pokeName="Lapras";
        type[0]="Water"; type[1]="Ice";
        typeNum=2;

        moveset[0]=Moves(17);
        moveset[1]=Moves(18);
        moveset[2]=Moves(109);
        moveset[3]=Moves(108);
        //move brine, rest, ice beam, thunderbolt (change thunderbolt to surf, rest to protect)

        current[0]=190+rand()%48; current[1]=81+rand()%70; current[2]=76+rand()%70; current[3]=81+rand()%70; current[4]=90+rand()%72; current[5]=58+rand()%66;
        ability = "Shell Armour";
        abilityDescript = "User Cannot be Critically Hit.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];

        }
        break;
    }
    case 6:
    {
        pokeName="Dracovish";
        type[0]="Water"; type[1]="Dragon";
        typeNum=2;

        moveset[0]=Moves(103);
        moveset[1]=Moves(59);
        moveset[2]=Moves(109);
        moveset[3]=Moves(110);
        //fishious rend, brine, ancient power, body slam (fishious rend, crunch, protect, outrage)

        current[0]=150+rand()%48; current[1]=85+rand()%72; current[2]=94+rand()%74; current[3]=67+rand()%68; current[4]=76+rand()%70; current[5]=72+rand()%68;
        ability = "Water Absorb";
        abilityDescript = "When user is hit by a Water type damaging move, user recovers 25% Max HP and absorbs the attack.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 7:
    {
        pokeName="Blissey";
        type[0]="Normal"; type[1]="Fairy";
        typeNum=2;

        moveset[0]=Moves(26);
        moveset[1]=Moves(111);
        moveset[2]=Moves(5);
        moveset[3]=Moves(18);
        //light screen, soft boiled, thunderbolt, ice beam

        current[0]=315+rand()%48; current[1]=13+rand()%56; current[2]=13+rand()%56; current[3]=72+rand()%68; current[4]=126+rand()%80; current[5]=54+rand()%64;
        ability = "Serene Grace";
        abilityDescript = "Doubles the Chance of Secondary Effects Activating for all Users Moves.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 8:
    {
        pokeName="Gyarados";
        type[0]="Water"; type[1]="Flying";
        typeNum=2;

        moveset[0]=Moves(12);
        moveset[1]=Moves(11);
        moveset[2]=Moves(92);
        moveset[3]=Moves(31);
        //earthquake, dragon dance, ice fang, aqua tail 

        current[0]=155+rand()%48; current[1]=117+rand()%78; current[2]=75+rand()%70; current[3]=58+rand()%66; current[4]=94+rand()%74; current[5]=77+rand()%70;
        ability = "Intimidate";
        abilityDescript = "When user enters the battle, all Enemy Pokemon have their ATK reduced by 1 Stage.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 9:
    {
        pokeName="Gengar";
        type[0]="Ghost"; type[1]="Poison";
        typeNum=2;

        moveset[0]=Moves(63);
        moveset[1]=Moves(109);
        moveset[2]=Moves(3);
        moveset[3]=Moves(33);
        // destiny bond, protect, shadow ball, sludge bomb

        current[0]=120+rand()%48; current[1]=63+rand()%66; current[2]=58+rand()%66; current[3]=121+rand()%80; current[4]=72+rand()%68; current[5]=103+rand()%76;
        ability = "Levitate";
        abilityDescript = "User is Floating above the Ground, making it Immune to all Ground-type Moves.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 10:
    {
        pokeName="Corviknight";
        type[0]="Steel"; type[1]="Flying";
        typeNum=2;

        moveset[0]=Moves(112);
        moveset[1]=Moves(105);
        moveset[2]=Moves(50);
        moveset[3]=Moves(95);
        //Drill peck, roost, brave bird, iron head

        current[0]=158+rand()%48; current[1]=82+rand()%71; current[2]=99+rand()%74; current[3]=52+rand()%64; current[4]=81+rand()%70; current[5]=64+rand()%67;
        ability = "Pressure";
        abilityDescript = "All Moves used against this Pokemon use Double the PP Cost.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 11:
    {
        pokeName="Braviary";
        type[0]="Normal"; type[1]="Flying";
        typeNum=2;

        moveset[0]=Moves(4);
        moveset[1]=Moves(105);
        moveset[2]=Moves(50);
        moveset[3]=Moves(106);
        //hone claws, roost, brave bird, return

        current[0]=160+rand()%48; current[1]=115+rand()%78; current[2]=72+rand()%68; current[3]=55+rand()%65; current[4]=72+rand()%68; current[5]=76+rand()%70;
        ability = "Keen Eye";
        abilityDescript = "Prevents Enemy Pokemon from lowering this Pokemon's ACC Stat Stages.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 69:
    {
        pokeName="MagikarpGOD";
        type[0]="Water"; type[1]="Dragon";
        typeNum=2;

        moveset[0]=Moves(10);
        moveset[1]=Moves(11);
        moveset[2]=Moves(23);
        moveset[3]=Moves(101);
        //moves flare blitz, dragon dance, aerial ace,nuzzle

        current[0]=200; current[1]=300; current[2]=50; current[3]=300; current[4]=50; current[5]=100;
        ability = "Shell Armour";
        abilityDescript = "User cannot be critically hit.";

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 111:
    {
        pokeName="Metagross";
        type[0]="Steel"; type[1]="Psychic";
        typeNum=2;

        moveset[0]=Moves(19);
        moveset[1]=Moves(20);
        moveset[2]=Moves(21);
        moveset[3]=Moves(12);
        //moves meteor mash, psychic, hyper beam, earthquake

        //notes: meteor 20% chance raise user ATK by 1, psychic 10% chance lowering SP.DEF by 1.

        current[0]=140+rand()%48; current[1]=126+rand()%80; current[2]=121+rand()%80; current[3]=90+rand()%72; current[4]=85+rand()%72; current[5]=67+rand()%68;
        ability = "Clear Body";
        //prevents stat reduction from enemy moves, but not self-inflicted reductions.

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    
    case 112:
    {
        pokeName="Skarmory";
        type[0]="Steel"; type[1]="Flying";
        typeNum=2;

        moveset[0]=Moves(22);
        moveset[1]=Moves(23);
        moveset[2]=Moves(50);
        moveset[3]=Moves(113);
        //moves steel wing, aerial ace, toxic, spikes (changed toxic brave bird and spikes to rock slide)

        //notes: steel wing 10% chance raise user DEF by 1, check toxic formula (same as normal poison?), spikes hurts for 12.5% HP upon switch in (can be stacked up to 25% for 3 check online).

        current[0]=125+rand()%48; current[1]=76+rand()%70; current[2]=130+rand()%82; current[3]=40+rand()%62; current[4]=67+rand()%68; current[5]=67+rand()%68;
        ability = "Sturdy";
        //prevents OHKO moves while at full health, leaves with 1HP remaining.

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 113:
    {
        pokeName="Claydol";
        type[0]="Ground"; type[1]="Psychic";
        typeNum=2;

        moveset[0]=Moves(26);
        moveset[1]=Moves(27);
        moveset[2]=Moves(28);
        moveset[3]=Moves(12);
        //moves light screen, reflect, ancient power, earthquake

        //notes: light doubles SP.DEF of users for 5 turns & relfect doubles DEF users 5 turns, Ancient 10% chance increaing all stat multi by 1 stage (not ACC).

        current[0]=120+rand()%48; current[1]=67+rand()%68; current[2]=99+rand()%74; current[3]=67+rand()%68; current[4]=112+rand()%78; current[5]=72+rand()%68;
        ability = "Levitate";
        //Immunity to ground type moves.

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 114:
    {
        pokeName="Aggron";
        type[0]="Steel"; type[1]="Rock";
        typeNum=2;

        moveset[0]=Moves(29);
        moveset[1]=Moves(30);
        moveset[2]=Moves(31);
        moveset[3]=Moves(12);
        //moves curses, head smash, aqua tail, earthquake

        //notes: thunder 30% chance paralyze, solar charges first turn then fires second.

        current[0]=130+rand()%48; current[1]=103+rand()%76; current[2]=166+rand()%90; current[3]=58+rand()%66; current[4]=58+rand()%66; current[5]=49+rand()%64;
        ability = "Rock Head";
        //No recoil damage.

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 115:
    {
        pokeName="Cradily";
        type[0]="Grass"; type[1]="Rock";
        typeNum=2;

        moveset[0]=Moves(32);
        moveset[1]=Moves(33);
        moveset[2]=Moves(34);
        moveset[3]=Moves(27);
        //moves confuse ray, sludge bomb, giga drain, ancient power

        //notes: confuse if hits confuses, Sludge 30% to poison, giga heals 50% of damage dealt, Ancient 10% chance increaing all stat multi by 1 stage (not ACC).

        current[0]=146+rand()%48; current[1]=77+rand()%70; current[2]=91+rand()%73; current[3]=77+rand()%70; current[4]=100+rand()%75; current[5]=43+rand()%62;
        ability = "Suction Cups";
        //cannot be forced to leave by enemy moves, only user initiated moves.

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    case 116:
    {
        pokeName="Armaldo";
        type[0]="Bug"; type[1]="Rock";
        typeNum=2;

        moveset[0]=Moves(27);
        moveset[1]=Moves(35);
        moveset[2]=Moves(36);
        moveset[3]=Moves(23);
        //moves slash, water pulse, ancient power, aerial ace

        //notes: slash increased crit chance (maybe 1.5X??), pulse 20% to confuse enemy, Ancient 10% chance increaing all stat multi by 1 stage (not ACC).

        current[0]=135+rand()%48; current[1]=117+rand()%78; current[2]=94+rand()%74; current[3]=67+rand()%68; current[4]=76+rand()%70; current[5]=45+rand()%62;
        ability = "Battle Armour";
        //Immuned to critical hits, only takes normal damage.

        for (int i=0;i<6;i++)
        {
            base[i]=current[i];
        }
        break;
    }
    }
}

void Pokemon::setCurrent(int i,double change,string operation)
{
    if (operation=="+")
    {
        current[i]+=change;
    }
    else if (operation=="-")
    {
        current[i]-=change;
    }
    else if (operation=="=")
    {
        current[i]=change;
    }
    else if (operation=="*")
    {
        current[i]*=change;
    }
    else if (operation=="/")
    {
        current[i]/=change;
    }
}

int Pokemon::getCurrent(int i)
{
    return current[i];
}

void Pokemon::setBase(int i,int change,string operation)
{
    if (operation=="+")
    {
        base[i]+=change;
    }
    else if (operation=="-")
    {
        base[i]-=change;
    }
    else if (operation=="=")
    {
        base[i]=change;
    }
}
int Pokemon::getBase(int i)
{
    return base[i];
}

void Pokemon::setCondition(int i,string set)
{
    condition[i]=set;
}
string Pokemon::getCondition(int i)
{
    return condition[i];
}

void Pokemon::setConditionCool(int i,int change,string operation)
{
    if (operation=="+")
    {
        conditionCool[i]+=change;
    }
    else if (operation=="-")
    {
        conditionCool[i]-=change;
    }
    else if (operation=="=")
    {
        conditionCool[i]=change;
    }
}
int Pokemon::getConditionCool(int i)
{
    return conditionCool[i];
}

void Pokemon::setStatMultiplier(int i,double change,string operation)
{
    if (operation=="+")
    {
        statMultiplier[i]+=change;
    }
    else if (operation=="-")
    {
        statMultiplier[i]-=change;
    }
    else if (operation=="=")
    {
        statMultiplier[i]=change;
    }
}
double Pokemon::getStatMultiplier(int i)
{
    return statMultiplier[i];
}

string Pokemon::getType(int i)
{
    return type[i];
}

string Pokemon::getPokeName()
{
    return pokeName;
}

int Pokemon::getTypeNum()
{
    return typeNum;
}

string Pokemon::getAbility()
{
    return ability;
}

string Pokemon::getAbilityDescript()
{
    return abilityDescript;
}

void Pokemon::setCooldown(int change,string operation)
{
    if (operation=="+")
    {
        cooldown+=change;
    }
    else if (operation=="-")
    {
        cooldown-=change;
    }
    else if (operation=="=")
    {
        cooldown=change;
    }
}
int Pokemon::getCooldown()
{
    return cooldown;
}

void Pokemon::setBadCounter(int change,string operation)
{
    if (operation=="+")
    {
        badCounter+=change;
    }
    else if (operation=="-")
    {
        badCounter-=change;
    }
    else if (operation=="=")
    {
        badCounter=change;
    }
}
int Pokemon::getBadCounter()
{
    return badCounter;
}

void Pokemon::setTurnCount(int change,string operation)
{
    if (operation=="+")
    {
        turnCount+=change;
    }
    else if (operation=="-")
    {
        turnCount-=change;
    }
    else if (operation=="=")
    {
        turnCount=change;
    }
}
int Pokemon::getTurnCount()
{
    return turnCount;
}

void Pokemon::setDamageLast(int change,string operation)
{
    if (operation=="+")
    {
        damageLast+=change;
    }
    else if (operation=="-")
    {
        damageLast-=change;
    }
    else if (operation=="=")
    {
        damageLast=change;
    }
}
int Pokemon::getDamageLast()
{
    return damageLast;
}

void Pokemon::setCritLast(int change,string operation)
{
    if (operation=="+")
    {
        critLast+=change;
    }
    else if (operation=="-")
    {
        critLast-=change;
    }
    else if (operation=="=")
    {
        critLast=change;
    }
}
int Pokemon::getCritLast()
{
    return critLast;
}

Moves* Pokemon::getMoves(int i)
{
    return &moveset[i];
}

string* Pokemon::getTypes()
{
    return type;
}

void Pokemon::setImpermeable(int change,string operation)
{
    if (operation=="+")
    {
        impermeable+=change;
    }
    else if (operation=="-")
    {
        impermeable-=change;
    }
    else if (operation=="=")
    {
        impermeable=change;
    }
}
int Pokemon::getImpermeable()
{
    return impermeable;
}

void Pokemon::setProtect(int i)
{
    protect=i;
}

int Pokemon::getProtect()
{
    return protect;
}

void Pokemon::setRoost(int i)
{
    roost=i;
}

int Pokemon::getRoost()
{
    return roost;
}

void Pokemon::setOutrage(int i)
{
    outrage=i;
}

int Pokemon::getOutrage()
{
    return outrage;
}

void Pokemon::setDestiny(int i)
{
    destiny=i;
}

int Pokemon::getDestiny()
{
    return destiny;
}

void Pokemon::setFlinched(int i)
{
    flinched=i;
}

int Pokemon::getFlinched()
{
    return flinched;
}


