#include "../include/floor.h"

Floor::Floor() {
  shape.setSize(sf::Vector2f(500.f,50.f));
  shape.setPosition(200.f,750.f);
  shape.setFillColor(sf::Color::Green);
}
