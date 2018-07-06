#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <Constants.h>
#include <Score.h>

Paddle::Paddle()
{
    //dummy ctor.
}

Paddle::Paddle(sf::Texture* texture, sf::Vector2f initPos, sf::IntRect textureRect)
{
    dimensions.x = 100.0f;
    dimensions.y = float(PADDLE_HEIGHT);
    currentPos = initPos;
    dx = 0;
    paddleSpeed = PADDLE_SPEED;

    //Set the player image.
    image.setSize(dimensions);
    image.setOrigin(sf::Vector2f(dimensions.x/2, dimensions.y/2));
    image.setPosition(currentPos);
    image.setTexture(texture);
    image.setTextureRect(textureRect);
}

void Paddle::move(bool right)
{
    if(right)
    {
        if(image.getPosition().x +dimensions.x/2 < SCREEN_WIDTH)
        {
            dx = paddleSpeed;
        }
        else
        {
            dx = 0;
        }
    }
    else if(!right)
    {
        if(image.getPosition().x - dimensions.x/2 > 0)
        {
            dx = -paddleSpeed;
        }
        else
        {
            dx = 0;
        }
    }
}

void Paddle::stop()
{
    dx = 0;
}

void Paddle::update()
{
    currentPos.x += dx;
    if(currentPos.x+dimensions.x/2 > SCREEN_WIDTH)
    {
        currentPos.x = SCREEN_WIDTH-dimensions.x/2;
    }
    else if(currentPos.x-dimensions.x/2 < 0)
    {
        currentPos.x = dimensions.x/2;
    }
    image.setPosition(currentPos);
}

sf::Vector2f Paddle::getDimensions()
{
    return dimensions;
}

sf::Vector2f Paddle::getCurrentPos()
{
    return currentPos;
}

Paddle::~Paddle()
{
    //dtor
}
