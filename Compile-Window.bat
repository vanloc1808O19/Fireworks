mingw32-g++.exe -std=c++20 -Wall -DSFML_STATIC -c src\Explosion.cpp -o Explosion.o
mingw32-g++.exe -std=c++20 -Wall -DSFML_STATIC -c src\Fireworks.cpp -o Firework.o
mingw32-g++.exe -std=c++20 -Wall -DSFML_STATIC -c src\Main.cpp -o Main.o
mingw32-g++.exe -std=c++20 -Wall -DSFML_STATIC -c src\Particle.cpp -o Particle.o
mingw32-g++.exe -o fireworks.exe Explosion.o Firework.o Main.o Particle.o -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -static-libgcc -static-libstdc++ -s -mwindows
del Explosion.o
del Firework.o
del Main.o
del Particle.o