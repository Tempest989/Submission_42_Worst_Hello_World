#ifndef BATTLE
#define BATTLE
#include "Enemy.h"
#include "Player.h"
#include <string>
using namespace std;

class Battle
{
public:
    //getters and setters for the private variables
    Battle();
    int enemySwitch(Player*,Enemy*);
    int playerBattle(Player*);       // might delete
    int playerItem(Player*);         // might delete
    int playerSwitch(Player*,Enemy*);       // might delete
    int turnAttack(Pokemon*,Pokemon*,int,string);
    int turnStatus(Pokemon*,Pokemon*,string,int);
    static double weakness(int,string[],string);
    static double stageMulti(int,int);
    virtual int enemyAttack(Player*,Enemy*,Battle*);
    virtual int enemyItem(Enemy*,Player*,Battle*);

    int confusionProc(Pokemon*,int);

    void setPlayerSpikes(int,string);
    int getPlayerSpikes();

    void setPlayerReflect(int,string);
    int getPlayerReflect();

    void setPlayerLightScreen(int,string);
    int getPlayerLightScreen();

    void setEnemySpikes(int,string);
    int getEnemySpikes();

    void setEnemyReflect(int,string);
    int getEnemyReflect();

    void setEnemyLightScreen(int,string);
    int getEnemyLightScreen();

protected:
    //string weatherCondition;
    int playerSpikes;   //if the player has laid down spikes (0 to 3 where 0 is no spikes)
    int enemySpikes;    //if the AI has laid down spikes (0 to 3)
    int playerReflect;  //if the player has a reflect up
    int enemyReflect;   //if the AI has a reflect up
    int playerLightScreen;  //Same as above but for lightscreen
    int enemyLightScreen;   //Same as above but for lightscreen
    //string first;
};
#endif
