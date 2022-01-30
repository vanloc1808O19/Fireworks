#ifndef _FIREWORKS_H_
#define _FIREWORKS_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Particle.hpp"

class Firework {
private:
    sf::Color _color;

    sf::Vector2f _velocity;

    sf::Vector2f _position;

    unsigned short int _tick;

    std::vector<Particle*> *_particles;

public:
    Firework(std::vector<Particle*>* p);

    ~Firework();

    sf::Color getColor();

    sf::Vector2f getPosition();
    
    bool poll();
};

#endif // !_FIREWORKS_H_