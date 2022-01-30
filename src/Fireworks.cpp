#include "../header/Fireworks.hpp"

Firework::Firework(std::vector<Particle*> *p) {
    this->_color = sf::Color(rand() % 256, rand() % 256, rand() % 256);

    this->_position = sf::Vector2f(rand() % 801,600);

    this->_velocity = sf::Vector2f(rand() % 5 + 1, (rand() % 8 + 3)*(-1));

    if(this->_position.x >= 400) {
        this->_velocity.x = this->_velocity.x * (-1);
    }
        
    this->_tick = 0;

    this->_particles = p;
}

Firework::~Firework() {
    for (int i = 0; i < this->_particles->size(); i++) {
        delete this->_particles->at(i);
        this->_particles->at(i) = nullptr;
    }

    delete this->_particles;
    this->_particles = nullptr;
}

sf::Color Firework::getColor() {
    return this->_color;
}

sf::Vector2f Firework::getPosition() {
    return this->_position;
}

bool Firework::poll () {
    this->_position = this->_position + this->_velocity;

    for(int i = 0; i < this->_velocity.y * (-1); i++) {
        for(int j = 0; j < 5; j++) {
            this->_particles->push_back(new Particle(sf::Vector2f(this->getPosition().x,this->getPosition().y + i),this->getColor()));
        }
    }
          
    if(this->_tick >= 50) {
        return false;
    }

    this->_tick++;
    return true;
}
