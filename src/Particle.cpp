#include "../header/Particle.hpp"

Particle::Particle(sf::Color col, sf::Vector2f pos)
{
    this->_color = col;
    
    this->_position = pos;

    this->_alphaSub = this->_color.a / (rand() % 15 + 5);
    
    this->_tick = 0;
}

Particle::~Particle() {
    