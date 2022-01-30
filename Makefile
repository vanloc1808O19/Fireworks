CC = g++

all: Particle.o Fireworks.o Explosion.o main.o
	$(CC) Particle.o Fireworks.o Explosion.o main.o -o fireworks -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Particle.o: src/Particle.cpp header/Particle.hpp
	$(CC) -g -c src/Particle.cpp

Fireworks.o: src/Fireworks.cpp header/Fireworks.hpp
	$(CC) -g -c src/Fireworks.cpp

Explosion.o: src/Explosion.cpp header/Explosion.hpp
	$(CC) -g -c src/Explosion.cpp

main.o: header/Particle.hpp header/Fireworks.hpp header/Explosion.hpp src/main.cpp
	$(CC) -g -c src/main.cpp

clean:
	rm *.o

cleanall:
	rm *.o
	rm fireworks