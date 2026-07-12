#include "../include/object.h"

void Object::render(sf::RenderTarget& target) const {
  target.draw(shape);
}

bool Object::intersects(const Object& other) const {
  return shape.getGlobalBounds().intersects(
      other.shape.getGlobalBounds());
}

void Object::set_position(float x, float y) {
  shape.setPosition(x,y);
}

sf::Vector2f Object::get_position() const {
  return shape.getPosition();
}

sf::Vector2f Object::get_lateral_bounds() const {
  return sf::Vector2f(
      get_position().x,
      get_position().x + shape.getGlobalBounds().width
      );
}

sf::Vector2f Object::get_vertial_bounds() const {
  return sf::Vector2f(
      get_position().y,
      get_position().y + shape.getGlobalBounds().height
      );
}

float Object::get_width() const {
  return shape.getGlobalBounds().width;
}

float Object::get_height() const {
  return shape.getGlobalBounds().height;
}

sf::FloatRect Object::get_bounds() const {
  return shape.getGlobalBounds();
}
