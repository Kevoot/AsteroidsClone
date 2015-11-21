#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

//Class ship inherits from Convex shape
class Ship: public sf::ConvexShape
{
  public:
    //Default constructor
    Ship();
    //virtual functions that will be used in all ships
    virtual void rotateRight() = 0;
    virtual void rotateLeft() = 0;
  private:
    //will be used in future versions
    int health;
};

/*
Inherits from ship and convex shape
*/
class playerShip: public Ship
{
  public:
    //constructor
    playerShip();
    void rotateRight();
    void rotateLeft();
    void addVX(float x);
    void addVY(float y);
    float getVX(){return vx;};
    float getVY(){return vy;};
  private:
  protected:
    //Velocity in X and Y directions
    float vx = 0;
    float vy = 0;
};

//Sparse at the moment, when AI is added more functions will need to be added
class enemyShip: public Ship
{
  public:
    enemyShip();
    void scroll();
    //Rotation to be implemented in next version
    void rotateRight();
    void rotateLeft();
  private:
  protected:
};


#endif
