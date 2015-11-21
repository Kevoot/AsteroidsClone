#include "GameEngine.hpp"
#include "Ship.hpp"
#include <iostream>
#include <string>

using namespace std;


#define DEF_WIDTH 1500
#define DEF_HEIGHT 900

//Default constructor

GameEngine::GameEngine()
{
}

//Sets up Window
GameEngine::GameEngine(string windowName, int width, int height)
{
  window.create(sf::VideoMode(width, height), windowName);
}

void GameEngine::runGame()
{
  if (!theShip.buffer.loadFromFile("whoosh.wav"))
  {
    cout << "Couldn't load sound file, exiting!" << endl;
    exit(1);
  }
  theShip.sound.setBuffer(theShip.buffer);

  while (window.isOpen())
    {
      //Handles key input
      handleEvents();
      window.clear();
      //Updates player ship location, and if boundary of window is reached
      //sets back to the other side
      theShip.move(5, 0);
      if(theShip.getPosition().x > 1500)
      {
        theShip.setPosition(0, theShip.getPosition().y);
      }
      //Draws and displays the ship
      window.draw(theShip);
      theShip.sound.play();
      window.display();
    }
}

//Handles events from key input, or window closing
void GameEngine::handleEvents()
{
  while (window.pollEvent(event))
  {
    switch(event.type)
    {
      case sf::Event::Closed:
        window.close();
        break;
    }
  }
}
