CC = g++

all: Particle.o Fireworks.o main.o
	$(CC) Particle.o Fireworks.o main.o -o fireworks -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Particle.o: src/Particle.cpp header/Particle.hpp
	$(CC) -g -c src/Particle.cpp

Fireworks.o: src/Fireworks.cpp header/Fireworks.hpp
	$(CC) -g -c src/Fireworks.cpp

main.o: header/Particle.hpp header/Fireworks.hpp src/main.cpp
	$(CC) -g -c src/main.cpp

clean:
	rm *.o

cleanall:
	rm *.o
	rm fireworks