#ifndef MOVES
#define MOVES
#include <string>
using namespace std;

class Moves
{
public:

    //getters and setters for the private variables
    Moves();
    Moves(int);
    string getMoveName();
    int getMovePow();
    int getMoveAcc();
    void setMovePP(int,string);
    int getMovePP();
    int getOr_MovePP();
    string getMoveEle();
    string getMoveType();
    int getMovePriority();
    string getMoveDescript();
    int getContact();
    int getCrit_Ratio();
    int getNumHits(int);
    int getFlinch();
    int getCooldown();
    int getBuff(int);
    int getBuff2(int);
    int getBuff3(int);
    int getDeBuff(int);
    int getConfuse(int);
    int getStatus(int);
    int getRecoil(int);
    int getDrain();
    int getHeal();

private:
    string moveName;
    int movePow;    //stores the power of the move
    int moveAcc;    //stores the accuracy of the move
    int movePP;     //stores the current remaining PP of a move
    int or_movePP;  //stores how many times a move can be used
    string moveEle;     //stores the moves elemental type
    string moveType;    //Physical, Special, Status
    int movePriority;   //stores whether a move has priority
    string moveDescript;    //stores the moves description
    int contact;    //whether the move makes contact
    int crit_ratio;     //if a move has a high crit ration 0/1
    int numHits[2];     //0 element = minimum hits, 1 element = maximum hits
    int flinch; // percent chance to cause flinch
    int cooldown; //-1 means wait 1 turn before attack, 1 means wait 1 turn after attack

    //buffs/debuffs element 0 = buff type, element 1 = buff amount, element 2 = chance to occur
    int buff[3];  /// 1 = ATK, 2 = DEF, 3 = SP.ATK, 4 = SP.DEF, 5 = SPD, 6 = ACC, 69 = ancient power
    int buff2[3];
    int buff3[3];
    int deBuff[3]; //if debuff element 1 is negative ==> actually buffs the opponent stats
    int confuse[2];
    //first element = type of status, second element = chance to occur
    int status[2];  //0= no status, 1= paralyze, 2= sleep, 3 = burn, 4 = poison, 5 = freeze, 6 = badly poison
    int recoil[2]; //element 0 = yes or no, element 1 = recoil %

    //stuff that max has added
    int drain; //moves that drain % of damage done, just store % in variable
    int heal; //percentage that the move heals the user (% of health healed);
};
#endif
