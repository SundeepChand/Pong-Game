#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle
{
    public:
        Paddle();
        Paddle(sf::Texture* texture, sf::Vector2f initPos, sf::IntRect textureRect);
        void move(bool right);
        void stop();
        void update();
        sf::Vector2f getDimensions();
        sf::Vector2f getCurrentPos();
        float getSpeed();
        virtual ~Paddle();

    public:
        sf::RectangleShape image;

    private:
        sf::Vector2f currentPos;
        float dx;
        bool right;
        float paddleSpeed;
        sf::Vector2f dimensions;
};

#endif // PADDLE_H
