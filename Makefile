CC = g++

all: Particle.o main.o
	$(CC) Particle.o main.o -o fireworks -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Particle.o: src/Particle.cpp header/Particle.hpp
	$(CC) -g -c src/Particle.cpp

main.o: header/Particle.hpp src/main.cpp
	$(CC) -g -c src/main.cpp

clean:
	rm *.o

cleanall:
	rm *.o
	rm fireworks