#pragma once

#include "object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>

class Player : public Object {
public:
  enum struct direction {l,r,u,d};
  Player();

  // Movement
  void move(direction dir);
  void move();
  sf::FloatRect get_next_position() const;
  bool left_collision(const Object& object) const;
  bool right_collision(const Object& object) const;
  bool top_collision(const Object& object) const;
  bool bottom_collision(const Object& object) const;
  
  const float speed = 2;
  sf::Vector2f velocity = sf::Vector2f(0.f,0.f);

private:
};
