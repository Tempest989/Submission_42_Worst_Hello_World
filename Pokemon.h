#ifndef POKEMON
#define POKEMON

#include <string>
#include "Moves.h"
using namespace std;

class Pokemon
{
public:
    //getters and setters for the private variables
    Pokemon();
    Pokemon(int num);

    void setCurrent(int,double,string);
    int getCurrent(int);

    void setBase(int,int,string);
    int getBase(int);

    void setCondition(int,string);
    string getCondition(int);

    void setConditionCool(int,int,string);
    int getConditionCool(int);

    void setStatMultiplier(int,double,string);
    double getStatMultiplier(int);

    string getType(int);
    string *getTypes();

    string getPokeName();

    int getTypeNum();

    string getAbility();

    string getAbilityDescript();

    void setCooldown(int,string);
    int getCooldown();

    void setBadCounter(int,string);
    int getBadCounter();

    void setTurnCount(int,string);
    int getTurnCount();

    void setDamageLast(int,string);
    int getDamageLast();

    void setCritLast(int,string);
    int getCritLast();

    void setImpermeable(int,string);
    int getImpermeable();

    void setProtect(int);
    int getProtect();

    void setRoost(int);
    int getRoost();

    void setOutrage(int);
    int getOutrage();

    void setDestiny(int);
    int getDestiny();

    void setFlinched(int);
    int getFlinched();

    Moves * getMoves(int);


private:
    int current[6]; //stores the pokemon's current stats, 0=hp, 1=atk,2=def,3=sp.atk,4=sp.def,5=spd
    int base[6]; //stores the pokemon's base stats
    string type[2]; //stores the pokemon's type
    string pokeName;
    int typeNum; //stores how many types the pokemon has (1 or 2)
    string condition[2]; //stores status conditions. element 0 = status, element 1 = confusion
    int conditionCool[2];
    string ability;
    string heldItem; //just store the item's name, empty string if no item
    double statMultiplier[6]; //# of stages, 0=atk.....4=spd, 5=acc
    string abilityDescript;
    int impermeable; //if pokemon is currently invicible (protect, dig, fly, ect.)                    //NEED TO DO LATER ONCE ITS WORKING!!!!!
    int cooldown;
    int badCounter; //turn counter for badly poisoned
    //int transformed;

    Moves moveset[4];

    int roost; //if roost was activated last turn or not
    int protect; // if they are protected/used protect, 1=protected, 2+=used protect last turn
    int outrage; // if using outrage, counts how many turns, max 3 min 2
    int destiny; // 0 if nothing, 1 if destiny bond active
    int flinched; //0 is nothing, 1 is flinched

    //stuff max has added
    int turnCount; //number of turns the pokeon has been in battle (resets on switch)
    int damageLast; //damage this pokemon did previous turn
    int critLast; //if this pokemon crit previous turn
    //int seeded; //If this pokemon has been leech seeded
    //int subbed; //integer that stores the precentage health of a substitute, 0 if no sub
    //int veiled; //If this pokemon has a water veil (Aqua Ring)
    //string lastMove; //the move this pokemon used last turn.
    //int switched; //this pokemon has used the move Trick or Switeroo
    };
#endif
