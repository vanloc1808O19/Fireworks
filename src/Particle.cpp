#include "../header/Particle.hpp"

Particle::Particle(sf::Vector2f P, sf::Color C)
{
    this->_position = P;
    this->_color = C;
    this->_alphaSub = this->_color.a / (rand() % 15 + 5);
    this->_tick = 0;
    return;
};

Particle::~Particle()
{
    return;
};

sf::Color Particle::getColor()
{
    return this->_color;
};

sf::Vector2f Particle::getPosition()
{
    return this->_position;
};

bool Particle::poll()
{
    if(this->_position.y >= 600 || this->_color.a - this->_alphaSub <= 0)
        return false;
    this->_position = this->_position + sf::Vector2f(rand() % 5 - 3,rand() % 2);
    this->_color.a = this->_color.a - this->_alphaSub;
    if(this->_color.a > 200)
        this->_color.a = 200;
    return true;
};
