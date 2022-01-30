#include "../header/Explosion.hpp"

Explosion::Explosion(sf::Color col, sf::Vector2f pos) {
    this->_position = pos;

    if (rand() % 2 == 1) {
        this->_velocity.x = rand() % 10;
        this->_velocity.y = rand() % 10;
    } else {
        this->_velocity.x = rand() % 10 * (-1);
        this->_velocity.y = rand() % 10 * (-1);
    }

    this->_color = col;

    this->_alphaSub = this->_color.a / (rand() % 50 + 5);

    this->_tick = 0;
}

Explosion::~Explosion() {

}

sf::Color Explosion::getColor() {
    return this->_color;
}

void Explosion::setColor(sf::Color col) {
    this->_color = col;
}

sf::Vector2f Explosion::getPosition() {
    return this->_position;
}

bool Explosion::poll() {
    if (this->_color.a <= this->_alphaSub || this->_tick >= 50) {
        return false;
    }

    this->_position += this->_velocity;

    this->_color.a -= this->_alphaSub;

    if (this->_color.a > 200) {
        this->_color.a = 200;
    }

    this->_tick++;

    return true;
}