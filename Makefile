.PHONY: all Compile Gaunlet Poke RPS BlackJack clean

all: Gaunlet

Compile: Gaunlet Poke RPS BlackJack

Gaunlet:
	g++ Controller.cpp Battle.cpp cpuRock.cpp dealer.cpp Enemy.cpp Moves.cpp Person.cpp personBlackJack.cpp PersonRock.cpp Player.cpp playerBlackJack.cpp playerRock.cpp Pokemon.cpp ref.cpp Steven.cpp Turns.cpp Gaunlet.cpp -o gaunlet

Poke:
	g++ Battle.cpp Moves.cpp Enemy.cpp Person.cpp Player.cpp Steven.cpp Turns.cpp Pokemon.cpp mainPoke.cpp -o poke

RPS:
	g++ mainRock.cpp cpuRock.cpp PersonRock.cpp playerRock.cpp ref.cpp -o rps

BlackJack:
	g++ 42BlackJack.cpp dealer.cpp personBlackJack.cpp playerBlackJack.cpp -o blackjack

clean:
	@if [ -f "gaunlet" ]; then\
		rm gaunlet;\
		printf "rm gaunlet\n";\
	else\
		printf "gaunlet Doesn't Exist so It Cannot Be Removed\n";\
	fi
	@if [ -f "poke" ]; then\
		rm poke;\
		printf "rm poke\n";\
	else\
		printf "poke Doesn't Exist so It Cannot Be Removed\n";\
	fi
	@if [ -f "rps" ]; then\
		rm rps;\
		printf "rm rps\n";\
	else\
		printf "rps Doesn't Exist so It Cannot Be Removed\n";\
	fi
	@if [ -f "blackjack" ]; then\
		rm blackjack;\
		printf "rm blackjack\n";\
	else\
		printf "blackjack Doesn't Exist so It Cannot Be Removed\n";\
	fi
