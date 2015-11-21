//Ship.cpp
#include <iostream>
#include "Ship.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

using namespace std;

//Default constructor, unused
Ship::Ship()
{
}

//Sets location of ship, also creates the general shape of the ship
playerShip::playerShip()
{
  float x = 1000.0;
  float y = 500.0;
  //Sets origin to be used later
  setOrigin(sf::Vector2f(x, y));

  //Sets the initial position
  setPosition(sf::Vector2f(x, y));

  //Creates 8 vector points to create shape of ship
  setPointCount(8);

  //This chunk actually forms the ship
  setPoint(0, (sf::Vector2f(x + 20, y)));
  setPoint(1, (sf::Vector2f(x, y - 10)));
  setPoint(2, (sf::Vector2f(x - 20, y - 5)));
  setPoint(3, (sf::Vector2f(x - 10, y - 5)));
  setPoint(4, (sf::Vector2f(x - 10, y + 5)));
  setPoint(5, (sf::Vector2f(x - 20, y + 5)));
  setPoint(6, (sf::Vector2f(x, y + 10)));
  setPoint(7, (sf::Vector2f(x + 20, y)));
}

//Simply rotates the ship
//Steering is taken care of in GameEngine
void playerShip::rotateLeft()
{
  rotate((float)-15.0);
}

void playerShip::rotateRight()
{
  rotate((float)15.0);
}

//Used to add horizontal velocity
//Uses Cos and getRotation in GameEngine to determine amount
void playerShip::addVX(float x)
{
    vx += x / 0.4;
}

//Used to add vertical velocity
//Uses Sin and getRotation in GameEngine to determine amount
void playerShip::addVY(float y)
{
  if(vy > 10)
  {
    //do nothing
  }
  else
    vy += y / 0.4;
}

//enemy ship constructor
//Simply layout and coloring of enemy ship
enemyShip::enemyShip()
{
  float x = 700.0;
  float y = 100.0;
  //Sets origin to be used later
  setOrigin(sf::Vector2f(x, y));

  setFillColor(sf::Color(255, 0, 0));

  //Sets the initial position
  setPosition(sf::Vector2f(x, y));

  //Creates 8 vector points to create shape of ship
  setPointCount(6);

  //This chunk actually forms the ship
  setPoint(0, (sf::Vector2f(x - 10, y - 10)));
  setPoint(1, (sf::Vector2f(x + 10, y - 10)));
  setPoint(2, (sf::Vector2f(x + 10, y + 10)));
  setPoint(3, (sf::Vector2f(x, y)));
  setPoint(4, (sf::Vector2f(x - 10, y + 10)));
  setPoint(5, (sf::Vector2f(x - 10, y - 10)));
}

//Scrolls the enemy ship across the top of the window
void enemyShip::scroll()
{
  move(4, 0);
  if(getPosition().x > 1500)
  {
    setPosition(0, getPosition().y);
  }
}

void enemyShip::rotateRight()
{
  //To be implemented in next assignment for chasing player
}

void enemyShip::rotateLeft()
{
  //To be implemented in next assignment for chasing player
}
