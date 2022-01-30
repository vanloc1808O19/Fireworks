#!/bin/bash
g++ src/main.cpp src/Fireworks.cpp src/Particle.cpp src/Explosion.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 -o fireworks