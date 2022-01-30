#include "../header/Particle.hpp"

Particle::Particle(sf::Vector2f pos, sf::Color col) {
    this->_position = pos;

    this->_color = col;

    this->_alphaSub = this->_color.a / (rand() % 15 + 5);

    this->_tick = 0;
}

Particle::~Particle() {
    
}

sf::Color Particle::getColor() {
    return this->_color;
}

sf::Vector2f Particle::getPosition() {
    return this->_position;
}

bool Particle::poll() {
    if (this->_position.y >= 600 || this->_color.a - this->_alphaSub <= 0) {
        return false;
    }
        
    this->_position = this->_position + sf::Vector2f(rand() % 5 - 3,rand() % 2);

    this->_color.a = this->_color.a - this->_alphaSub;

    if (this->_color.a > 200) {
        this->_color.a = 200;
    }
        
    return true;
}