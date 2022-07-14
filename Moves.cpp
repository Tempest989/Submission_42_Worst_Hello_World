#include <string>
#include "Moves.h"
using namespace std;

Moves::Moves()
{
    crit_ratio = 0;
    cooldown=0;
    for (int i=0;i<2;i++)
    {
        buff[i]=0;
        deBuff[i]=0;
        status[i]=0;
        confuse[i]=0;
        recoil[i]=0;
        buff2[i]=0;
        buff3[i]=0;
        numHits[i]=1;
    }
    flinch=0;
    buff[2]=0;
    deBuff[2]=0;
    buff2[2]=0;
    buff3[2]=0;
    contact=0;
    movePriority=0;
    or_movePP=0;
    drain=0;
    heal=0;

    moveName = "No move.";
    moveEle = "No Element.";
    moveType = "No Type.";
    moveDescript = "No move is filled here.";
}

Moves::Moves(int num)
{
    crit_ratio = 0;
    cooldown=0;
    for (int i=0;i<2;i++)
    {
        buff[i]=0;
        deBuff[i]=0;
        status[i]=0;
        confuse[i]=0;
        recoil[i]=0;
        buff2[i] = 0;
        buff3[i]=0;
        numHits[i]=0;
    }
    flinch=0;
    buff[2]=0;
    deBuff[2]=0;
    buff2[2]=0;
    buff3[2]=0;
    contact=0;
    movePriority=0;
    or_movePP = 0;
    drain=0;
    heal=0;

    switch (num)
    {
    case 1:
    {
        moveName = "Phantom Force";
        movePow = 90;
        moveAcc = 100;
        movePP = 10;
        moveEle = "Ghost";
        moveType = "Physical";
        moveDescript = "User vanishes for 1 turn upon casting, then attacks enemy the next turn. Ignores all protection moves.";
        cooldown=1; // leave 1
        contact=1;
        break;

    }
    case 2:
    {
        moveName="X-Scissor";
        movePow=80;
        moveAcc=100;
        movePP=15;
        moveEle="Bug";
        moveType="Physical";
        moveDescript = "Slashes enemy in a X formation";
        contact=1;
        break;
    }
    case 3:
    {
        moveName="Shadow Ball";
        movePow=90;
        moveAcc=100;
        movePP=15;
        moveEle="Ghost";
        moveType="Special";
        moveDescript = "Has 20% chance to lower Sp.Def of enemy by 1 stage.";
        deBuff[0]=4;
        deBuff[1]=1;
        deBuff[2]=20;
        break;
    }
    case 4:
    {
        moveName="Hone Claws";
        movePow=0;
        moveAcc=0;
        movePP=15;
        moveEle="Dark";
        moveType="Status";
        moveDescript = "Raises User's ATK and ACC stat by 1 stage.";
        buff[0]=1;
        buff[1]=1;
        buff[2]=100;
        buff2[0]=6;
        buff2[1]=1;
        buff2[2]=100;
        break;
    }
    case 5:
    {
        moveName= "Thunderbolt";
        movePow = 90;
        moveAcc = 100;
        movePP= 15;
        moveEle= "Electric";
        moveType = "Special";
        moveDescript = "Hits enemy with bolt of lightning, 10% chance of inflicting Paralysis.";
        status[0]=1;
        status[1]=10;
        break;

    }
    case 6:
    {
        moveName="Nasty Plot";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Dark";
        moveType="Status";
        moveDescript = "Raises User's Sp.ATK by 2 stages.";
        buff[0]=3;
        buff[1]=2;
        buff[2]=100;
        break;
    }
    case 7:
    {
        moveName="Focus Blast";
        movePow=120;
        moveAcc=70;
        movePP=5;
        moveEle="Fighting";
        moveType="Special";
        moveDescript = "Fires a focused blast, has 10% chance to lower Sp.Def of enemy by 1 stage.";
        deBuff[0]=4;
        deBuff[1]=1;
        deBuff[2]=10;
        break;
    }
    case 8:
    {
        moveName="Dig";
        movePow=80;
        moveAcc=100;
        movePP=10;
        moveEle="Ground";
        moveType="Physical";
        moveDescript = "User digs underground for 1 turn upon casting, then attacks enemy the next turn.";
        contact=1;
        cooldown=1;
        break;
    }
    case 10:
    {
        moveName = "Flare Blitz";
        movePow = 120;
        moveAcc = 100;
        movePP = 15;
        moveEle = "Fire";
        moveType = "Physical";
        moveDescript = "User rams enemy whilst coated in Fire, User takes 1/3 of the damage done to the opponent as recoil.";
        contact=1;
        recoil[0]=1;
        recoil[1]=33;
        break;
    }
    case 11:
    {
        moveName="Dragon Dance";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Dragon";
        moveType="Status";
        moveDescript = "Raises User's ATK and SPD by 1 stage.";
        buff[0]=1;
        buff[1]=1;
        buff[2]=100;
        buff2[0]=5;
        buff2[1]=1;
        buff2[2]=100;
        break;
    }
    case 12:
    {
        moveName="Earthquake";
        movePow=100;
        moveAcc=100;
        movePP=10;
        moveEle="Ground";
        moveType="Physical";
        moveDescript = "Violently shakes the ground beneath enemy, inflicting damage.";
        break;
    }
    case 13:
    {
        moveName="Dragon Claw";
        movePow=80;
        moveAcc=100;
        movePP=15;
        moveEle="Dragon";
        moveType="Physical";
        moveDescript = "Slashs enemy with a dragonic claw, inflicting damage.";
        contact=1;
        break;
    }
    case 14:
    {
        moveName = "Belly Drum";
        movePow = 0;
        moveAcc = 0;
        movePP = 10;
        moveEle = "Normal";
        moveType = "Status";
        moveDescript = "Increases User's ATK stat to +6 stage at the cost of 1/2 their HP, cannot use if User's HP is below 1/2 their MAX HP.";
        break;
    }
    case 15:
    {
        moveName="Rest";
        movePow=0;
        moveAcc=0;
        movePP=10;
        moveEle="Psychic";
        moveType="Status";
        moveDescript = "Recovers User's HP to MAX, User falls asleep for 2-3 turns, includes casting turn.";
        break;
    }
    case 16:
    {
        moveName="Double Edge";
        movePow=120;
        moveAcc=100;
        movePP=15;
        moveEle="Normal";
        moveType="Physical";
        moveDescript = "User tackles enemy full-force, inflicting damage and taking 1/3 of the inflicted damage as recoil.";
        recoil[0]=1;
        recoil[1]=33;
        contact=1;
        break;
    }
    case 17:
    {
        moveName = "Brine";
        movePow = 65;
        moveAcc = 100;
        movePP = 10;
        moveEle = "Water";
        moveType = "Special";
        moveDescript = "Doubles in Power when enemy is at or below 1/2 their MAX HP.";
        break;
    }
    case 18:
    {
        moveName="Ice Beam";
        movePow=90;
        moveAcc=100;
        movePP=10;
        moveEle="Ice";
        moveType="Special";
        moveDescript = "Fires a beam of ice at the opponent, has 10% chance to Freeze.";
        status[0]=5;
        status[1]=10;
        break;
    }
    case 19:
    {
        moveName = "Meteor Mash";
        movePow = 90;
        moveAcc = 90;
        movePP = 10;
        moveEle = "Steel";
        moveType = "Physical";
        moveDescript = "Hits enemy with a Meteor-like punch, 20% chance to increase ATK.";
        contact=1;
        buff[0]=1;
        buff[1]=1;
        buff[2]=20;
        break;
    }
    case 20:
    {
        moveName="Psychic";
        movePow=90;
        moveAcc=100;
        movePP=10;
        moveEle="Psychic";
        moveType="Special";
        moveDescript = "Fires a strong telekinetic force at the opponent, 10% chance to reduce Sp.Def.";
        deBuff[0]=4;
        deBuff[1]=1;
        deBuff[2]=10;
        break;
    }
    case 21:
    {
        moveName="Giga Impact";
        movePow=150;
        moveAcc=90;
        movePP=5;
        moveEle="Normal";
        moveType="Physical";
        moveDescript = "The user charges at the target using every bit of its power. The user must recover their energy next turn.";
        cooldown=-1;
        break;
    }
    case 22:
    {
        moveName = "Steel Wing";
        movePow = 70;
        moveAcc = 90;
        movePP = 25;
        moveEle = "Steel";
        moveType = "Physical";
        moveDescript = "Strikes enemy with a pair of steel wings, 10% chance to increase DEF.";
        contact=1;
        buff[0]=2;
        buff[1]=1;
        buff[2]=10;
        break;
    }
    case 23:
    {
        moveName="Aerial Ace";
        movePow=60;
        moveAcc=0;
        movePP=20;
        moveEle="Flying";
        moveType="Physical";
        moveDescript = "Slashes enemy at extremely high speed, cannot miss unless enemy untouchable (flying, digging etc).";
        contact=1;
        break;
    }
    case 24:
    {
        moveName="Toxic";
        movePow=0;
        moveAcc=90;
        movePP=10;
        moveEle="Poison";
        moveType="Status";
        moveDescript = "Badly poisons enemy, damage increase each turn.";
        status[0]=6;
        status[1]=100;
        break;
    }
    case 25:
    {
        moveName="Spikes";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Ground";
        moveType="Status";
        moveDescript = "Sets spike on enemy's field, damages enemies that switch in.";
        break;
    }
    case 26:
    {
        moveName = "Light Screen";
        movePow = 0;
        moveAcc = 0;
        movePP = 30;
        moveEle = "Psychic";
        moveType = "Status";
        moveDescript = "Puts up screen of light, reduces all incoming Special damage by 1/2.";
        break;
    }
    case 27:
    {
        moveName="Ancient Power";
        movePow=60;
        moveAcc=100;
        movePP=5;
        moveEle="Rock";
        moveType="Special";
        moveDescript = "Enemy is hit with a prehistoric power, 10% chance to increase all stats";
        buff[0]=69;
        buff[1]=1;
        buff[2]=10;
        break;
    }
    case 28:
    {
        moveName="Reflect";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Psychic";
        moveType="Status";
        moveDescript = "Puts up wall of light, reduces all incoming Physical damage by 1/2.";
        break;
    }
    case 29:
    {
        moveName = "Curse";
        movePow = 0;
        moveAcc = 0;
        movePP = 10;
        moveEle = "Ghost";
        moveType = "Status";
        moveDescript = "For non-Ghost type User, will increase ATK & DEF but reduce SPD. For Ghost type user, cuts user's HP in 1/2 to inflict curse on enemy, dealing damage per turn.";
        buff[0]=1;
        buff[1]=1;
        buff[2]=100;
        buff2[0]=2;
        buff2[1]=1;
        buff2[2]=100;
        buff3[0]=5;
        buff3[1]=-1;
        buff3[2]=100;
        break;
    }
    case 30:
    {
        moveName="Head Smash";
        movePow=150;
        moveAcc=80;
        movePP=5;
        moveEle="Rock";
        moveType="Physical";
        moveDescript = "User smashes head-first into enemy, inflicting damage. Takes 1/2 damage dealt as recoil.";
        recoil[0]=1;
        recoil[1]=50;
        contact=1;
        break;
    }
    case 31:
    {
        moveName="Aqua Tail";
        movePow=90;
        moveAcc=90;
        movePP=10;
        moveEle="Water";
        moveType="Physical";
        moveDescript = "User hits the opponent with their swinging tail as if it's were a vicious wave in a raging storm.";
        contact=1;
        break;
    }
    case 32:
    {
        moveName="Confuse Ray";
        movePow=0;
        moveAcc=100;
        movePP=10;
        moveEle="Ghost";
        moveType="Status";
        moveDescript = "Sinister ray that confuses the opponent.";
        confuse[0]=1;
        confuse[1]=100;
        break;

    }
    case 33:
    {
        moveName="Sludge Bomb";
        movePow=90;
        moveAcc=100;
        movePP=10;
        moveEle="Poison";
        moveType="Special";
        moveDescript = "Throws poisonous sludge at the opponent, 30% chance to poison.";
        status[0]=4;
        status[1]=30;
        break;
    }
    case 34:
    {
        moveName="Giga Drain";
        movePow=75;
        moveAcc=100;
        movePP=10;
        moveEle="Grass";
        moveType="Special";
        moveDescript = "Inflicts damage on enemy, User absorbs 50% damage as HP.";
        drain=50;
        break;
    }
    case 35:
    {
        moveName = "Slash";
        movePow = 70;
        moveAcc = 100;
        movePP = 20;
        moveEle = "Normal";
        moveType = "Physical";
        moveDescript = "Slashes the opponent, has a high crit-ratio.";
        contact=1;
        crit_ratio=1;
        break;

    }
    case 36:
    {
        moveName="Water Pulse";
        movePow=60;
        moveAcc=100;
        movePP=20;
        moveEle="Water";
        moveType="Special";
        moveDescript = "Fires a pulsing blast of water at the opponent, 20% chance to confuse.";
        confuse[0]=1;
        confuse[1]=20;
        break;
    }



    //MAXXXXXXX


    case 37:
    {
        moveName="Body Slam";
        movePow=85;
        moveAcc=100;
        movePP=15;
        moveEle="Normal";
        moveType="Physical";
        moveDescript = "User slams their body into the opponent, 30% chance to paralyze.";
        contact=1;
        status[0]=1;
        status[1]=30;
        break;
    }
    case 38:
    {
        moveName="Acrobatics";
        movePow=55;
        moveAcc=100;
        movePP=15;
        moveEle="Flying";
        moveType="Physical";
        moveDescript = "The user nimbly strikes the target. Has double power if the user has no held item.";
        contact=1;
        break;
        //??? damage increases if no held item. If flying gem is held, gem is consumed then move checks if no held item.

    }
    case 39:
    {
        moveName="Air Slash";
        movePow=75;
        moveAcc=95;
        movePP=15;
        moveEle="Flying";
        moveType="Special";
        moveDescript="The user attacks with a blade of air that slices even the sky, 30% chance to cause flinching.";
        flinch=30;
        break;
    }
    case 40:
    {
        moveName="Amnesia";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Psychic";
        moveType="Status";
        moveDescript="The user temporarily empties its mind to forget its concerns, raises Sp. Def by 2 stages.";
        buff[0]=5; buff[1]=2; buff[2]=100;
        break;
    }
    case 41:
    {
        moveName="Aqua Jet";
        movePow=40;
        moveAcc=100;
        movePP=20;
        moveEle="Water";
        moveType="Physical";
        moveDescript="The user lunges at the target at a speed that makes it almost invisible, usually hits first";
        contact=1;
        movePriority=1;
        break;
    }
    case 42:
    {
        moveName="Aqua Ring";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Water";
        moveType="Status";
        moveDescript="The user envelops itself in a veil made of water. It regains some 1/16th of its HP every turn.";
        break;
        //??? heals 1/16th health every turn until pokemon which used it swaps out, is passed with batton pass.
    }
    case 43:
    {
        moveName="Aromatherapy";
        movePow=0;
        moveAcc=0;
        movePP=5;
        moveEle="Grass";
        moveType="Status";
        moveDescript="The user releases a soothing scent. Clears all status conditions affecting the user's party.";
        break;
        //??? remove stat debuffs from entire ally team
}
    case 44:
    {
        moveName="Attack Order";
        movePow=90;
        moveAcc=100;
        movePP=15;
        moveEle="Bug";
        moveType="Physical";
        moveDescript="The user calls out its underlings to pummel the target. Has a high crit-ratio.";
        crit_ratio=1;
        break;
    }
    case 45:
    {
        moveName="Avalanche";
        movePow=60;
        moveAcc=100;
        movePP=15;
        moveEle="Ice";
        moveType="Physical";
        moveDescript="The power of this attack move is doubled if the user has been hurt by the target in the same turn.";
        contact=1;
        movePriority=-4;
        break;
        //??? Damage doubles if user hit on same turn prior to attack going through
    }
    case 46:
    {
        moveName="Baton Pass";
        movePow=0;
        moveAcc=0;
        movePP=40;
        moveEle="Normal";
        moveType="Status";
        moveDescript="The user switches places with a party Pokémon and passes along any stat changes.";
        break;
        //??? stat changes get swapped to the ally
    }
    case 49:
    {
        moveName="Blizzard";
        movePow=110;
        moveAcc=70;
        movePP=5;
        moveEle="Ice";
        moveType="Special";
        moveDescript="A howling blizzard is summoned to strike opposing Pokémon, has a 10% chance to freeze. Always hits in hail";
        status[0]=5; status[1]=10; //Freeze 10%
        break;
        //??? accuracy =0 in hail
    }
    case 50:
    {
        moveName="Brave Bird";
        movePow=120;
        moveAcc=100;
        movePP=15;
        moveEle="Flying";
        moveType="Physical";
        moveDescript="The user tucks in its wings and charges from a low altitude. User takes 1/3 of the damage done to the opponent as recoil.";
        contact=1;
        recoil[0]=1;
        recoil[1]=30;
        break;

    }
    case 51:
    {
        moveName="Brick Break";
        movePow=75;
        moveAcc=100;
        movePP=15;
        moveEle="Fighting";
        moveType="Physical";
        moveDescript="The user attacks with a swift chop destroying barriers, such as Light Screen and Reflect.";
        contact=1;
        break;
        //??? destroys light screen and reflect

    }
    case 52:
    {
        moveName="Bug Buzz";
        movePow=90;
        moveAcc=100;
        movePP=10;
        moveEle="Bug";
        moveType="Special";
        moveDescript="The user generates a damaging sound wave by vibration. 10% chance to lower Sp. Def of enemy by 1 stage.";
        deBuff[0]=4; deBuff[1]=1; deBuff[2]=10; //Special Defense, 1 stage, 10%
        break;
    }
    case 53:
    {
        moveName="Bulk Up";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Fighting";
        moveType="Status";
        moveDescript="The user tenses its muscles to bulk up its body, raises both Attack and Defense by 1 stage.";
        buff[0]=1; buff[1]=1; buff[2]=100; //Attack, 1 stage, 100%
        buff2[0]=2; buff2[1]=1; buff2[2]=100; //Defense, 1 stage, 100%
        break;
    }
    case 54:
    {
        moveName="Bullet Seed";
        movePow=25;
        moveAcc=100;
        movePP=30;
        moveEle="Grass";
        moveType="Physical";
        moveDescript="The user forcefully shoots seeds at the target. Two to five seeds are shot in rapid succession.";
        numHits[0]=2; numHits[1]=5;
        break;
    }
    case 55:
    {
        moveName="Calm Mind";
        movePow=0;
        moveAcc=0;
        movePP=20;
        moveEle="Psychic";
        moveType="Status";
        moveDescript="The user quietly focuses its mind and calms its spirit, raising Sp. Atk and Sp. Def by 1 stage.";
        buff[0]=3; buff[1]=1; buff[2]=100; //Special Attack, 1 stage, 100%
        buff2[0]=4; buff2[1]=1; buff[2]=100; //Special Defense, 1 stage, 100%
        break;
    }
    case 56:
    {
        moveName="Close Combat";
        movePow=120;
        moveAcc=100;
        movePP=5;
        moveEle="Fighting";
        moveType="Physical";
        moveDescript="The user fights the target up close without guarding itself. Lowers the user's Defense and Sp. Def by 1 stage.";
        buff[0]=2; buff[1]=-1; buff[2]=100; //Defense, -1 stage, 100%
        buff2[0]=4; buff[1]=-1; buff[2]=100; //Special Defense, -1 stage, 100%
        break;
    }
    case 57:
    {
        moveName="Crabhammer";
        movePow=100;
        moveAcc=90;
        movePP=10;
        moveEle="Water";
        moveType="Physical";
        moveDescript="The target is hammered with a large pincer. Has a high crit-ratio.";
        contact=1;
        crit_ratio=1;
        break;
    }
    case 58:
    {
        moveName="Cross Posison";
        movePow=70;
        moveAcc=100;
        movePP=20;
        moveEle="Poison";
        moveType="Physical";
        moveDescript="A slashing attack with a poisonous blade, has a 10% to cause poison. Has a high crit-ratio.";
        contact=1;
        crit_ratio=1;
        status[0]=4; status[1]=10; //Poison, 10%
        break;
    }
    case 59:
    {
        moveName="Crunch";
        movePow=80;
        moveAcc=100;
        movePP=15;
        moveEle="Dark";
        moveType="Physical";
        moveDescript="The user crunches up the target with sharp fangs. 20% chance to lower Defence of enemy by 1 stage.";
        contact=1;
        deBuff[0]=2, deBuff[1]=1; deBuff[2]=20; //Defence, 1 stage, 20%
        break;
    }
    case 60:
    {
        moveName="Dark Pulse";
        movePow=80;
        moveAcc=100;
        movePP=15;
        moveEle="Dark";
        moveType="Physical";
        moveDescript="The user releases a horrible aura imbued with dark thoughts. 20% chance to cause flinching.";
        flinch=20;
        break;

    }
    case 61:
    {
        moveName="Dazzling Gleam";
        movePow=80;
        moveAcc=100;
        movePP=10;
        moveEle="Fairy";
        moveDescript="The user damages opposing Pokémon by emitting a powerful flash.";
        break;

    }
    case 62:
    {
        moveName="Defog";
        movePow=0;
        moveAcc=0;
        movePP=15;
        moveEle="Flying";
        moveType="Status";
        moveDescript="A strong wind blows away the all barriers and hazards. This also lowers the target's evasiveness.";
        break;
        //??? removes hazards and barriers
    }
    case 63:
    {
        moveName="Destiny Bond";
        movePow=0;
        moveAcc=0;
        movePP=5;
        moveEle="Ghost";
        moveType="Status";
        moveDescript="When this move is used, if the user faints, the Pokémon that landed the knockout hit also faints.";
        break;
    }
    case 64:
    {
        moveName="Dragon Pulse";
        movePow=85;
        moveAcc=100;
        movePP=10;
        moveEle="Dragon";
        moveType="Special";
        moveDescript="The target is attacked with a shock wave generated by the user's gaping mouth.";
        break;
    }
    case 65:
    {
        moveName="Drain Punch";
        movePow=75;
        moveAcc=100;
        movePP=10;
        moveEle="Fighting";
        moveType="Physical";
        moveDescript="An energy-draining punch. Users absorbs 50% damage as HP.";
        contact=1;
        drain=50;
        break;
    }
    case 66:
    {
        moveName="Earth Power";
        movePow=90;
        moveAcc=100;
        movePP=10;
        moveEle="Ground";
        moveType="Special";
        moveDescript="The user makes the ground under the target erupt with power. 10% chance to lower Sp. Def of enemy by 1 stage.";
        deBuff[0]=4; deBuff[1]=1; deBuff[2]=10; //Sp. Def, 1 stage, 10%
        break;
    }
    case 67:
    {
        moveName="Energy Ball";
        movePow=90;
        moveAcc=100;
        movePP=10;
        moveEle="Grass";
        moveType="Special";
        moveDescript="The user draws power from nature and fires it at the target. 10% chance to lower Sp. Def of enemy by 1 stage.";
        deBuff[0]=4; deBuff[1]=1; deBuff[2]=10; //Sp. Def, 1 stage, 10%
        break;
    }
    case 68:
    {
        moveName="Explosion";
        movePow=250;
        moveAcc=100;
        movePP=5;
        moveEle="Normal";
        moveType="Physical";
        moveDescript="The user attacks everything around it by causing a tremendous explosion. The user faints upon using this move.";
        heal = -100;
        break;
    }
    case 69:
    {
        moveName="Extreme Speed";
        movePow=80;
        moveAcc=100;
        movePP=5;
        moveEle="Normal";
        moveType="Physical";
        moveDescript="The user charges the target at blinding speed. This move always hits first.";
        contact=1;
        movePriority=2;
        break;
    }
    case 70:
    {
        moveName="Facade";
        movePow=70;
        moveAcc=100;
        movePP=20;
        moveEle="Normal";
        moveType="Physical";
        moveDescript="This attack move doubles its power if the user is poisoned, burned, or paralyzed.";
        contact=1;
        break;
        //??? double power if user is poisoned burned or paralyzed
    }
    case 71:
    {
        moveName="Fake Out";
        movePow=40;
        moveAcc=100;
        movePP=10;
        moveEle="Normal";
        moveType="Physical";
        moveDescript="Hits first and makes the target flinch. It only works the first turn each time the user enters battle.";
        contact=1;
        flinch=100;
        break;
        //??? only works on first turn of user
    }
    case 72:
    {
        moveName="Fire Blast";
        movePow=110;
        moveAcc=85;
        movePP=5;
        moveEle="Fire";
        moveType="Special";
        moveDescript="The target is attacked with an intense blast of all-consuming fire, has a 30% chance to cause burn.";
        status[0]=3; status[1]=30; //Burn, 30%
        break;
    }
    case 73:
    {
        moveName="Fire Fang";
        movePow=65;
        moveAcc=95;
        movePP=15;
        moveEle="Fire";
        moveType="Physical";
        moveDescript="The user bites with flame-cloaked fangs, has a 10% chance cause flinching and 10% chance to cause burn.";
        contact=1;
        status[0]=3; status[1]=10; //Burn, 10%
        flinch=10;
        break;
    }
    case 74:
    {
        moveName="Fire Punch";
        movePow=75;
        moveAcc=100;
        movePP=15;
        moveEle="Fire";
        moveType="Phsical";
        moveDescript="The target is punched with a fiery fist, has a 10% chance to cause burn.";
        contact=1;
        status[0]=3; status[1]=10; //Burn, 10%
        break;
    }
    case 75:
    {
        moveName="Flamethrower";
        movePow=90;
        moveAcc=100;
        movePP=15;
        moveEle="Fire";
        moveType="Special";
        moveDescript="The target is scorched with an intense blast of fire, has a 10% chance to cause burn.";
        status[0]=3; status[1]=10; //Burn, 10%
        break;
    }
    case 76:
    {
        moveName="Flash Cannon";
        movePow=80;
        moveAcc=100;
        movePP=10;
        moveEle="Steel";
        moveType="Special";
        moveDescript="The user gathers all its light energy and releases it all at once. 10% chance to lower Sp. Def of enemy by 1 stage.";
        deBuff[0]=4; deBuff[1]=1; deBuff[2]=10; //Sp. Def, 1 stage, 10%
        break;
    }
    case 79:
    {
        moveName="Fling";
        movePow=30; //Every mon that has fling holds a flame orb so i just hard coded that shit :^)
        moveAcc=100;
        movePP=10;
        moveEle="Dark";
        moveType="Physical";
        moveDescript="The user flings its held item at the target to attack. This move's power and effects depend on the item.";
        status[0]=3; status[1]=100; //Burn, 100%
        break;
        //??? can only be used if user is holding an item, item is removed after used for the first time
    }
    case 80:
    {
        moveName="Foul Play";
        movePow=95;
        moveAcc=100;
        movePP=15;
        moveEle="Dark";
        moveType="Physical";
        moveDescript="The user turns the target's power against it. The higher the target's Attack stat, the greater the damage it deals.";
        contact=1;
        break;
        //??? during damage calculations use targets attack stat.
    }
    case 81:
    {
        moveName="Freeze-Dry";
        movePow=70;
        moveAcc=100;
        movePP=20;
        moveEle="Ice";
        moveType="Special";
        moveDescript="The user rapidly cools the target, has 10% chance to Freeze. This move is super effective on Water types";
        status[0]=5; status[1]=10; //Freeze 10%
        break;
        //??? treated as supereffective against water type pokemon.
    }
    case 82:
    {
        moveName="Gunk Shot";
        movePow=120;
        moveAcc=80;
        movePP=5;
        moveEle="Poison";
        moveType="Physical";
        moveDescript="The user shoots filthy garbage at the target to attack, has 30% chance to cause poison";
        status[0]=4; status[1]=10; //Poison 30%
        break;
    }
    case 83:
    {
        moveName="Gyro Ball";
        movePow=0;
        moveAcc=100;
        movePP=5;
        moveEle="Steel";
        moveType="Physical";
        moveDescript="The user tackles the target with a high-speed spin. The slower the user compared to the target, the greater the move's power.";
        contact=1;
        break;
        //??? uses thisformula for power calculation:   Base Power = 25 * (TargetSpeed / UserSpeed)
    }
    case 84:
    {
        moveName="Hammer Arm";
        movePow=100;
        moveAcc=90;
        movePP=10;
        moveEle="Fighting";
        moveType="Physical";
        moveDescript="The user swings and hits with its strong, heavy fist. Lowers the user's Speed by 1 stage";
        contact=1;
        buff[0]=5; buff[1]=-1; buff[2]=100; //Speed, -1 stage, 100%
        break;
    }
    case 85:
    {
        moveName="Haze";
        movePow=0;
        moveAcc=0;
        movePP=30;
        moveEle="Ice";
        moveType="Status";
        moveDescript="The user creates a haze that eliminates the stat changes of all the Pokémon in battle.";
        break;
        //??? reset all stat changes of current pokemon to 0;
    }
    case 86:
    {
        moveName="Heal Bell";
        movePow=0;
        moveAcc=0;
        movePP=5;
        moveEle="Normal";
        moveType="Status";
        moveDescript="The user makes a soothing bell chime to heal the status conditions of all the party Pokémon.";
        break;
        //??? literally the exact same as aromatherapy
    }
    case 87:
    {
        moveName="Heal Order";
        movePow=0;
        moveAcc=0;
        movePP=10;
        moveEle="Bug";
        moveType="Status";
        moveDescript="The user calls out its underlings to heal it. Restores 50% of the user's max HP.";
        heal=50;
        break;
    }
    case 88:
    {
        moveName="Iron Tail";
        movePow=100;
        moveAcc=75;
        movePP=15;
        moveEle="Steel";
        moveType="Physical";
        moveDescript="The target is slammed with a steel-hard tail, has 30% chance to lower target's Defense by 1 stage.";
        contact=1;
        deBuff[0]=2; deBuff[1]=1; deBuff[2]=30; //Defense, 1 stage, 30%
        break;
    }
    case 89:
    {
        moveName="Hex";
        movePow=65;
        moveAcc=100;
        movePP=10;
        moveEle="Ghost";
        moveType="Special";
        moveDescript="This relentless attack has double power against targets affected by status conditions.";
        break;
        //??? power is doubled to 130 if targeting target with burn/poison/paralyze/freeze/sleep
    }
    case 90:
    {
        moveName="Hydro Pump";
        movePow=110;
        moveAcc=80;
        movePP=5;
        moveEle="Water";
        moveType="Special";
        moveDescript="The target is blasted by a huge volume of water launched under great pressure.";
        break;
    }
    case 91:
    {
        moveName="Hyper Voice";
        movePow=90;
        moveAcc=100;
        movePP=10;
        moveEle="Normal";
        moveType="Special";
        moveDescript="The user lets loose a horribly echoing shout with the power to inflict damage.";
        break;
    }
    case 92:
    {
        moveName="Ice Fang";
        movePow=65;
        moveAcc=95;
        movePP=15;
        moveEle="Ice";
        moveType="Physical";
        moveDescript="The user bites with cold-infused fangs, has a 10% chance cause flinching and 10% chance to cause freeze.";
        contact=1;
        status[0]=5; status[1]=10; //Freeze, 10%
        flinch=10;
        break;
    }
    case 93:
    {
        moveName="Ice Punch";
        movePow=75;
        moveAcc=100;
        movePP=15;
        moveEle="Ice";
        moveType="Physical";
        moveDescript="The target is punched with a icy fist, has a 10% chance to cause freeze.";
        contact=1;
        status[0]=5; status[1]=10; //Freeze, 10%
        break;
    }
    case 94:
    {
        moveName="Icicle Crash";
        movePow=85;
        moveAcc=90;
        movePP=10;
        moveEle="Ice";
        moveType="Physical";
        moveDescript="The user attacks by harshly dropping large icicles onto the target, has a 30% chance to cause flinching.";
        flinch=30;
        break;
    }
    case 95:
    {
        moveName="Iron Head";
        movePow=80;
        moveAcc=100;
        movePP=15;
        moveEle="Steel";
        moveType="Physical";
        moveDescript="The user slams the target with its steel-hard head, has a 30% chance to cause flinching.";
        contact=1;
        flinch=30;
        break;
    }
    case 96:
    {
        moveName="Knock Off";
        movePow=65;
        moveAcc=100;
        movePP=20;
        moveEle="Dark";
        moveType="Physical";
        moveDescript="The user slaps down the target's held item, preventing that item from being used in the battle.";
        contact=1;
        break;
        //??? removes target's held item for the rest of the battle
    }
    case 97:
    {
        moveName="Lava Plume";
        movePow=80;
        moveAcc=100;
        movePP=15;
        moveEle="Fire";
        moveType="Special";
        moveDescript="The user torches everything around it in an inferno of scarlet flames. has a 30% chance to cause burn.";
        status[0]=3; status[1]=30; //Burn, 30%
        break;
    }
    case 98:
    {
        moveName="Leaf Blade";
        movePow=90;
        moveAcc=100;
        movePP=15;
        moveEle="Grass";
        moveType="Physical";
        moveDescript="The foe is slashed with a sharp leaf. Has a high crit-ratio.";
        contact=1;
        crit_ratio=1;
        break;
    }
    case 99:
    {
        moveName="Leech Life";
        movePow=80;
        moveAcc=100;
        movePP=10;
        moveEle="Bug";
        moveType="Physical";
        moveDescript="The user drains the target's blood. Users absorbs 50% damage as HP.";
        contact=1;
        drain=50;
        break;
    }
    case 100:
    {
        moveName="Leech Seed";
        movePow=0;
        moveAcc=90;
        movePP=10;
        moveEle="Grass";
        moveType="Status";
        moveDescript="A seed is planted on the target which drains 1/16th of the targets HP every turn.";
        //??? the same as aqua ring but also damages opponent for the same amount
        break;
    }
    case 101:
    {
        moveName="Nuzzle";
        movePow=20;
        moveAcc=100;
        movePP=20;
        moveEle="Electric";
        moveType="Physical";
        moveDescript="User nuzzle up to the enemy with its Electrified Check, paralyzing them.";
        contact=1;
        status[0]=1;
        status[1]=100;
        break;
    }
    case 102:
    {
        moveName="Splash";
        movePow=20;
        break;
    }
    case 103:
    {
        moveName="Fishious Rend";
        movePow=85;
        moveAcc=100;
        movePP=10;
        moveEle="Water";
        moveType="Physical";
        moveDescript="Hits the enemy with user's fishy head, Doubles in Power if user attacks First.";
        contact=1;
        break;
    }
    case 104:
    {
        moveName="Blast Burn";
        movePow=150;
        moveAcc=90;
        movePP=5;
        moveEle="Fire";
        moveType="Special";
        moveDescript="Hits the enemy with Massive Blast of Heat and Fire, User must Cooldown Next Turn.";
        cooldown=-1;
        break;
    }
    case 105:
    {
        moveName="Roost";
        movePow=0;
        moveAcc=0;
        movePP=10;
        moveEle="Flying";
        moveType="Status";
        moveDescript="Restores 50% of Users HP, Flying-type Pokemon lose their Flying type for the turn.";
        heal=50;
        break;
    }
    case 106:
    {
        moveName="Return";
        movePow=102;
        moveAcc=100;
        movePP=20;
        moveEle="Normal";
        moveType="Physical";
        moveDescript="An Attack that grows more Powerful the more the Pokemon like the Trainer.";
        contact=1;
        break;
    }
    case 107:
    {
        moveName="Sleep Talk";
        movePow=0;
        moveAcc=0;
        movePP=10;
        moveEle="Normal";
        moveType="Status";
        moveDescript="Performs one of the Users other Moves at random whilst User is Asleep.";
        break;
    }
    case 108:
    {
        moveName="Surf";
        movePow=90;
        moveAcc=100;
        movePP=15;
        moveEle="Water";
        moveType="Special";
        moveDescript="User creates a Huge Wave and Crashes it Down on the Enemy.";
        break;
    }
    case 109:
    {
        moveName="Protect";
        movePow=0;
        moveAcc=0;
        movePP=10;
        moveEle="Normal";
        moveType="Status";
        moveDescript="User Protects iteself from all Attacks, may Fail if used Consectively.";
        movePriority=4;
        break;
    }
    case 110:
    {
        moveName="Outrage";
        movePow=120;
        moveAcc=100;
        movePP=10;
        moveEle="Dragon";
        moveType="Physical";
        moveDescript="User goes on a Rampage for 2-3 Turns, becomes Confused afterwards.";
        contact=1;
        break;
    }
    case 111:
    {
        moveName="Soft-Boiled";
        movePow=0;
        moveAcc=0;
        movePP=10;
        moveEle="Normal";
        moveType="Status";
        moveDescript="User eats a Soft-Boiled egg, restoring its own HP by up to 50%.";
        heal=50;
        break;
    }
    case 112:
    {
        moveName="Drill Peck";
        movePow=80;
        moveAcc=100;
        movePP=20;
        moveEle="Flying";
        moveType="Physical";
        moveDescript="A Corkscrewing Attack that Hits the Enemy with the Users Sharp Beak acting as a Drill.";
        contact=1;
        break;
    }
    case 113:
    {
        moveName="Rock Slide";
        movePow=75;
        moveAcc=90;
        movePP=10;
        moveEle="Rock";
        moveType="Physical";
        moveDescript="Hits Enemy with an Avalanche of Rocks and Boulders, may cause the Enemy to flinch.";
        flinch=30;
        break;
    }
    }
    or_movePP=movePP;
}

string Moves::getMoveName()
{
    return moveName;
}

int Moves::getMovePow()
{
    return movePow;
}

int Moves::getMoveAcc()
{
    return moveAcc;
}
//changing move PP based on the given change value and operation string value
void Moves::setMovePP(int change,string operation)
{
    if (operation=="+")
    {
        movePP+=change;
    }
    else if (operation=="-")
    {
        movePP-=change;
    }
    else if (operation=="=")
    {
        movePP=change;
    }
}
int Moves::getMovePP()
{
    return movePP;
}

int Moves::getOr_MovePP()
{
    return or_movePP;
}

string Moves::getMoveEle()
{
    return moveEle;
}

string Moves::getMoveType()
{
    return moveType;
}

int Moves::getMovePriority()
{
    return movePriority;
}

string Moves::getMoveDescript()
{
    return moveDescript;
}

int Moves::getContact()
{
    return contact;
}

int Moves::getCrit_Ratio()
{
    return crit_ratio;
}

int Moves::getNumHits(int i)
{
    return numHits[i];
}

int Moves::getFlinch()
{
    return flinch;
}

int Moves::getCooldown()
{
    return cooldown;
}

int Moves::getBuff(int i)
{
    return buff[i];
}

int Moves::getBuff2(int i)
{
    return buff2[i];
}

int Moves::getBuff3(int i)
{
    return buff3[i];
}

int Moves::getDeBuff(int i)
{
    return deBuff[i];
}

int Moves::getConfuse(int i)
{
    return confuse[i];
}

int Moves::getStatus(int i)
{
    return status[i];
}

int Moves::getRecoil(int i)
{
    return recoil[i];
}

int Moves::getDrain()
{
    return drain;
}

int Moves::getHeal()
{
    return heal;
}
