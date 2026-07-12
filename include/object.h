# pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
  void render(sf::RenderTarget& target) const;
  bool intersects(const Object& other) const;

  void set_position(float x, float y);
  sf::Vector2f get_position() const;
  sf::Vector2f get_lateral_bounds() const;
  sf::Vector2f get_vertial_bounds() const;
  float get_width() const;
  float get_height() const;
  sf::FloatRect get_bounds() const;

protected:
  sf::RectangleShape shape;
};
