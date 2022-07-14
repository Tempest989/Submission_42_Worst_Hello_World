# Submission for 42 Worst Hello World Competition
This Project was my Submission for the 42 Worst Hello World Competition, which was about creating the worst way possible to print "Hello World" to the user.  
The Method I choose was to make the user complete 3 games back to back in a gaunlet format, where if the user beats the game with certain conditions, then "Hello World" will be printed to terminal.  
This was written in C++.

## The 3 Games
1. Rock, Paper, Scissors.
2. BlackJack.
3. Pokemon Battle Simulator.

## Makefile Utility
- `make` and `make Gaunlet` will compile the Gaunlet part of the Project into the executable `gaunlet`.
- `make RPS` will compile the Rock, Paper, Scissors part of the Project into its own, standalone game, as the executable `rps`. 
- `make BlackJack` will compile the BlackJack part of the Project into its own, standalone game, as the executable `blackjack`.
- `make Poke` will compile the Pokemon part of the Project into its own, standalone game, as the executable `poke`.
- `make clean` will delete, if possible, the executables `gaunlet`, `rps`, `blackjack` and `poke`.
- `make compile` will run `make Gaunlet`, `make RPS`, `make BlackJack` and `make Poke`.

## Known Bugs / Issues
- BlackJack, the Hidden Objective can be achieved early than it should be, due to the checks for if the Hidden Objective has been passed correctly not being accurate enough.
- Pokemon, any stat increasing move will update the wrong stat, so for example, an ATK buff will actually buff DEF.
- Pokemon, Frozen Pokemon can still attack / move on the turn that they were Frozen.
- Pokemon, needs more in-depth explanations of what going on for some moves, Giga Impact being an example.
- Pokemon, have yet to test if the Confusion status effect and Sleep Talk work correctly.   
  
If there are any major progression bugs, checked Gaunlet.cpp and Controller.cpp since they are the progession files, if its specially game related,
such as results and playing the games, then look through the specific game files, which are all listed in the "Makefile" under the appropiate rule for each game.
## How To Run
- `./gaunlet` will run the Gaunlet part of the Project.
- `./rps` will run the Rock, Paper, Scissors part of the Project.
- `./blackjack` will run the BlackJack part of the Project.
- `./poke` will run the Pokemon part of the Project.
