#pragma once

#include "player.h"
#include "floor.h"
#include "rock.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
public:
  Game();
  ~Game();
  const bool running() const;
  void update();
  void render();
private:
  void init_variables();
  void init_window();
  void init_objects();
  void poll_events();

  void update_player();

  Player* player;
  Floor* floor;
  Rock* rock;

  sf::RenderWindow* window;
  sf::Event window_event;
  sf::VideoMode video_mode;

  const int window_width = 900;
  const int window_height = 900;
};
