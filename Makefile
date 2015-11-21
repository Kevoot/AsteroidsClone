SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CFLAGS =  -Wall -pedantic
CC = g++

all: main

main: main.o GameEngine.o Ship.o
	$(CC) $^ -o $@ $(CFLAGS) $(SFMLFLAGS)

GameEngine.o: GameEngine.cpp GameEngine.hpp
	$(CC) GameEngine.cpp GameEngine.hpp -c $(CFLAGS) $(SFMLFLAGS)

main.o: main.cpp
	$(CC) main.cpp -c $(CFLAGS) $(SFMLFLAGS)

Ship.o: Ship.cpp Ship.hpp
	$(CC) Ship.cpp Ship.hpp -c $(CFLAGS) $(SFMLFLAGS)

clean:
	rm -f *.o *~
