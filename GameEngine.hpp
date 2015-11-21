#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "SFML/Graphics.hpp"
#include "Ship.hpp"
#include <string>

using std::string;

//Class has only a few functions to handle and run the game, most
//of the heavy lifting is done by sfml functions
class GameEngine
{
public:
  GameEngine();
  GameEngine(string windowName, int width, int height);
  void runGame();
  void handleEvents();
  float degreesToRadians(float num);
protected:
  sf::RenderWindow window;
  sf::Event event;
  playerShip theShip;
};

#endif
