#include "../include/game.h"

////////////////////////////////////////
// PUBLIC
////////////////////////////////////////

Game::Game() {
  init_variables();
  init_objects();
  init_window();
}

Game::~Game() {
  delete window;
}

const bool Game::running() const {
  return window->isOpen();
}

void Game::update() {
  poll_events();
  update_player();
}

void Game::render() { 
  window->clear();
  player->render(*window);
  floor->render(*window);
  rock->render(*window);
  window->display();
}

////////////////////////////////////////
// PRIVATE
////////////////////////////////////////

void Game::init_variables() {
  window = nullptr;
  player = nullptr;
  floor = nullptr;
  rock = nullptr;
}

void Game::init_window() {
  video_mode.width = window_width;
  video_mode.height = window_height;
  window = new sf::RenderWindow(
      video_mode,
      "Second game",
      sf::Style::Titlebar
      );
  window->setVerticalSyncEnabled(true);
  window->setFramerateLimit(60);
}

void Game::poll_events() {
  while(window->pollEvent(window_event)) {
    switch(window_event.type) {
      case sf::Event::Closed:
        window->close();
        break;
      case sf::Event::KeyPressed:
        if(window_event.key.code == sf::Keyboard::Escape)
          window->close();
        break;
      default:
        break;
    }
  }
}

void Game::init_objects() {
  player = new Player;
  floor = new Floor;
  rock = new Rock;
}

void Game::update_player() {

  // Basic intersection detection

  if(player->intersects(*rock)
      || player->intersects(*floor))
    std::cout << 1 << std::endl;
  else
    std::cout << 0 << std::endl;

  // Set velocity

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
      player->velocity = sf::Vector2f(-5.f,0.f);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
      player->velocity = sf::Vector2f(5.f,0.f);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
      player->velocity = sf::Vector2f(0.f,5.f);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
      player->velocity = sf::Vector2f(0.f,-5.f);
  }

  // Object collision
  
  if(player->left_collision(*rock)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        rock->get_bounds().left - player->get_bounds().width,
        player->get_bounds().top);
    std::cout << "Left collision" << std::endl;
  }

  else if(player->right_collision(*rock)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        rock->get_bounds().left + rock->get_bounds().width,
        player->get_bounds().top);
    std::cout << "Right collision" << std::endl;
  }
  
  else if(player->top_collision(*rock)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        player->get_bounds().left,
        rock->get_bounds().top - player->get_bounds().height);
    std::cout << "Top collision" << std::endl;
  }
  
  else if(player->bottom_collision(*rock)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        player->get_bounds().left,
        rock->get_bounds().top + rock->get_bounds().height);
    std::cout << "Bottom collision" << std::endl;
  }

  if(player->left_collision(*floor)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        floor->get_bounds().left - player->get_bounds().width,
        player->get_bounds().top);
    std::cout << "Left collision" << std::endl;
  }

  else if(player->right_collision(*floor)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        floor->get_bounds().left + floor->get_bounds().width,
        player->get_bounds().top);
    std::cout << "Right collision" << std::endl;
  }
  
  else if(player->top_collision(*floor)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        player->get_bounds().left,
        floor->get_bounds().top - player->get_bounds().height);
    std::cout << "Top collision" << std::endl;
  }
  
  else if(player->bottom_collision(*floor)) {
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->set_position(
        player->get_bounds().left,
        floor->get_bounds().top + floor->get_bounds().height);
    std::cout << "Bottom collision" << std::endl;
  }
  
  player->move();

  // Screen collision

  if(player->get_position().x < 0)
    player->set_position(0.f,player->get_position().y);
  if(player->get_position().y < 0)
    player->set_position(player->get_position().x,0.f);
  if(player->get_lateral_bounds().y > window_width)
    player->set_position(window_width - player->get_width(),player->get_position().y);
  if(player->get_vertial_bounds().y > window_height)
    player->set_position(player->get_position().x,window_height - player->get_height());

  // Reset velocity
  
  player->velocity = sf::Vector2f(0.f,0.f);
}
