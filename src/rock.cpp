#include "../include/rock.h"

Rock::Rock() {
  shape.setSize(sf::Vector2f(100.f,100.f));
  shape.setPosition(400.f,100.f);
  shape.setFillColor(sf::Color::Yellow);
}
