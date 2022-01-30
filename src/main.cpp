#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../header/Fireworks.hpp"
#include "../header/Particle.hpp"
#include "../header/Explosion.hpp"

int main () {
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(800,600,32),"Happy Lunar New Year!");

    sf::Event event;

    std::vector<Firework*> fireworks;
    std::vector<Particle*> particles;
    std::vector<Explosion*> explosions;

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(2,2));

    sf::Clock pollTimer;

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    fireworks.push_back(new Firework(&particles));
                }
            }
        }

        window.clear(sf::Color(0,0,0));

        rect.setSize(sf::Vector2f(1,1));

        for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
            rect.setFillColor((*it)->getColor());

            rect.setPosition((*it)->getPosition());

            window.draw(rect);
        }

        rect.setSize(sf::Vector2f(2,2));

        for (std::vector<Explosion*>::iterator it = explosions.begin(); it != explosions.end(); ++it) {
            rect.setFillColor((*it)->getColor());

            rect.setPosition((*it)->getPosition());

            window.draw(rect);
        }

        for (std::vector<Firework*>::iterator it = fireworks.begin(); it != fireworks.end(); ++it) {
            rect.setFillColor((*it)->getColor());

            rect.setPosition((*it)->getPosition());

            window.draw(rect);
        }

        if (pollTimer.getElapsedTime().asMilliseconds() >= 50) {
            for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end();) {
                if((*it)->poll() == false) {
                    delete *it;
                    it = particles.erase(it);
                }
					 else
						 ++it;
            }

            for( std::vector<Firework*>::iterator it = fireworks.begin(); it != fireworks.end();) {
                if((*it)->poll() == false) {
                    for(int i = 0; i < 50; i++)
                        explosions.push_back(new Explosion((*it)->getPosition(),(*it)->getColor()));

                    delete *it;
                    it = fireworks.erase(it);
                }
					 else
						++it;
            }

            for( std::vector<Explosion*>::iterator it = explosions.begin(); it != explosions.end();) {
                if((*it)->poll() == false) {
                    particles.push_back(new Particle((*it)->getPosition(),(*it)->getColor()));
                    delete *it;
                    it = explosions.erase(it);
                }
					 else
						 ++it;
            }

            pollTimer.restart();
        }

        window.display();
    }

    return 0;
}
