#include "../include/player.h"
#include <SFML/Graphics/Rect.hpp>

Player::Player() : Object() {
  shape.setPosition(425.f,300.f);
  shape.setSize(sf::Vector2f(50.f,50.f));
  shape.setFillColor(sf::Color::Cyan);
}

void Player::move(direction dir) {
  switch(dir) {
    case direction::l:
      shape.move(-11.f,0.f);
      break;
    case direction::r:
      shape.move(11.f,0.f);
      break;
    case direction::u:
      shape.move(0.f,-11.f);
      break;
    case direction::d:
      shape.move(0.f,11.f);
      break;
    default:
      break;
  }
}

void Player::move() {
  shape.move(velocity * speed);
}

sf::FloatRect Player::get_next_position() const {
  sf::FloatRect next_position = get_bounds();
  next_position.left += velocity.x;
  next_position.top += velocity.y;
  return next_position;
}

bool Player::left_collision(const Object& other) const {
  if(
      get_next_position().intersects(other.get_bounds())
      && get_bounds().top < other.get_bounds().top + other.get_bounds().height
      && get_bounds().left < other.get_bounds().left
      && get_bounds().left + get_bounds().width < other.get_bounds().left + other.get_bounds().width
      && get_bounds().top + get_bounds().height > other.get_bounds().top
      )
    return true;
  else
    return false;
}

bool Player::right_collision(const Object& other) const {
  if(
      get_next_position().intersects(other.get_bounds())
      && get_bounds().top < other.get_bounds().top + other.get_bounds().height
      && get_bounds().left > other.get_bounds().left
      && get_bounds().left + get_bounds().width > other.get_bounds().left + other.get_bounds().width
      && get_bounds().top + get_bounds().height > other.get_bounds().top
      )
    return true;
  else
    return false;
}

bool Player::top_collision(const Object& other) const {
  if(
      get_next_position().intersects(other.get_bounds())
      && get_bounds().top + get_bounds().height < other.get_bounds().top + other.get_bounds().height
      && get_bounds().top < other.get_bounds().top
      && get_bounds().left < other.get_bounds().left + other.get_bounds().width
      && get_bounds().left + get_bounds().width > other.get_bounds().left
      )
    return true;
  else
    return false;
}

bool Player::bottom_collision(const Object& other) const {
  if(
      get_next_position().intersects(other.get_bounds())
      && get_bounds().top + get_bounds().height > other.get_bounds().top + other.get_bounds().height
      && get_bounds().top > other.get_bounds().top
      && get_bounds().left < other.get_bounds().left + other.get_bounds().width
      && get_bounds().left + get_bounds().width > other.get_bounds().left
      )
    return true;
  else
    return false;
}
