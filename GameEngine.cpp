#include "GameEngine.hpp"
#include "Ship.hpp"
#include <iostream>
#include <string>
#include <math.h>

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
  while (window.isOpen())
    {
      //Handles key input
      handleEvents();
      window.clear();
      //Updates enemy location
      enemy.scroll();
      //Updates player ship location, and if boundary of window is reached
      //sets back to the other side
      theShip.move(theShip.getVX(), theShip.getVY());
      if(theShip.getPosition().y > 900)
      {
        theShip.setPosition(theShip.getPosition().x, 0);
      }
      if(theShip.getPosition().y < 0)
      {
        theShip.setPosition(theShip.getPosition().x, 900);
      }
      if(theShip.getPosition().x > 1500)
      {
        theShip.setPosition(0, theShip.getPosition().y);
      }
      if(theShip.getPosition().x < 0)
      {
        theShip.setPosition(1500, theShip.getPosition().y);
      }


      //Draws and displays both ships
      window.draw(theShip);
      window.draw(enemy);
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

      case sf::Event::KeyPressed:
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
            theShip.rotateLeft();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
            /*These two lines add direction velocity across the X & Y
            axis' using sin and cos to determine heading*/
            theShip.addVX(cos(degreesToRadians(theShip.getRotation())));
            theShip.addVY(sin(degreesToRadians(theShip.getRotation())));
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            theShip.rotateRight();
          }
    }
  }
}
//Simple conversion from degrees to radians, returns the value for heading
float GameEngine::degreesToRadians(float num)
{
	return num * 3.14159 / 180;
}
