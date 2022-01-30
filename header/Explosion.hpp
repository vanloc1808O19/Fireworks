#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include <SFML/Graphics.hpp>

class Explosion {
private:
    sf::Color _color;

    sf::Vector2f _position;

    sf::Vector2f _velocity;

    float _alphaSub;

    unsigned short int _tick;

public:
    Explosion(sf::Color col, sf::Vector2f pos);

    ~Explosion();

    sf::Color getColor();

    void setColor(sf::Color col);

    sf::Vector2f getPosition();

    bool poll();
};

#endif // !_EXPLOSION_H_