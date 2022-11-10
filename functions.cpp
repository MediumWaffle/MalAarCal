/**
 * @file functions.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Function list for game
 * @date 10-24-2022
 */
#include "header.h"

void Objects::makeFloor(int s)
{
    one.setSize(sf::Vector2f(s, 50));
    one.setFillColor(Color::Blue);
    two.setSize(sf::Vector2f(s,50));
    two.setFillColor(Color::Red);
    three.setSize(Vector2f(s,50));
    three.setFillColor(Color::Green);

    floor1 = 0;
    floor2 = floor1-s;
    floor3 = floor1-(s*2);

    one.setOrigin(floor1,-150);
    two.setOrigin(floor2,-150);
    three.setOrigin(floor3,-150);

}

void Objects::moveFloor(int s)
{
     if(floor1 > s)
       {
            floor2 = 0;
            floor3 = 0-s;
            floor1 = 0-(s*2);
       }
       if(floor2 > s)
       {
            floor3 = 0;
            floor1 = 0-s;
            floor2 = 0-(s*2);
       }
       if(floor3 > s)
       {
            floor1 = 0;
            floor2 = 0-s;
            floor3 = 0-(s*2);
       }
        
        one.setOrigin(floor1,-150);
        two.setOrigin(floor2,-150);
        three.setOrigin(floor3,-150);

        floor1 += 10;
        floor2 += 10;
        floor3 += 10;

}

void Objects::jump(int height, int falls, int rises)
{
     if(Keyboard::isKeyPressed(Keyboard::Key::Space) and playerY < height)
        {
            playerY += rises;
            player.setOrigin(playerX, playerY);

        }
        if(playerY > -130 and !Keyboard::isKeyPressed(Keyboard::Key::Space))
        {
            playerY -= falls;
            player.setOrigin(playerX, playerY);
        }
}

void Objects::makePlayer()
{
     player.setRadius(25/2);
     player.setFillColor(Color(255,255,255));
     player.setOrigin(playerX,playerY);
}
