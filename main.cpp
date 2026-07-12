#include "include/game.h"

int main() {
  Game  g;
  while (g.running()) {
    g.update();
    g.render();
  }
  return 0;
}
