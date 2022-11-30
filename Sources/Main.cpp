#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <format>

#include "Objects.h"
#include "Utils.h"

using namespace std;
using namespace sf;

int main()
{
    const float G = 9.807;

    RenderWindow window(VideoMode(640, 480), "Ball Shooter");
    window.setFramerateLimit(60);

    Texture tBackground, tPlayer;
    tBackground.loadFromFile("Resources/Background.png");
    tPlayer.loadFromFile("Resources/Player.png");

    Sprite sprBackground(tBackground);
    Sprite sprPlayer(tPlayer);

    Player player;

    CircleShape hoop;
    int dir = 0;
    hoop.setRadius(50.f);
    hoop.setFillColor(Color::Black);
    hoop.setOutlineThickness(2.f);
    hoop.setOutlineColor(Color::Blue);
    hoop.setPosition(400,100);

    CircleShape ball;
    bool isShot = false;
    ball.setRadius(20.f);
    ball.setFillColor(Color::Red);
    ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius() * 3));





    /*Texture tBackground, tPlayer, rPlatform, tBall;
    tBackground.loadFromFile("Resources/Map.png");
    tPlayer.loadFromFile("Resources/mario.png");
    tBall.loadFromFile("Resources/goomba.png");

    Sprite sprBackground(tBackground);
    Sprite sprPlayer(tPlayer);
    Sprite sprball(tBall);

    Player player;*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        //update enemy(aka hoop)
        if (hoop.getPosition().x <= 0)
            dir = 1;
        else if (hoop.getPosition().x + hoop.getRadius()*2 >= window.getSize().x)
            dir = 0;
        if (dir == 0) 
        {
            hoop.move(-5.f, 0);

        }
        else 
        {
            hoop.move(5.f, 0);
        }

        //update ball
        if (Mouse::isButtonPressed(Mouse::Left))
            isShot = true;
        if(!isShot)
            ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
        else
            ball.move(0, -5.f);
        
        //Collision ball
        if (ball.getPosition().y < 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
        {
            //reset ball
            isShot = false;
            ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
        }



        //draw
        window.clear(Color::White);
        window.draw(hoop);
        window.draw(ball);

        window.display();
    }


    return 0;
}