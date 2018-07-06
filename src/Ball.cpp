#include "Ball.h"
#include <Constants.h>
#include <Paddle.h>

Ball::Ball()
{
    //dummy ctor.
}

Ball::Ball(sf::Texture* texture, sf::Vector2f initPos, sf::IntRect textureRect)
{
    //Initialize the values.
    currentPos = initPos;
    radius = BALL_RADIUS;
    //Set ball speed.
    dx = BALL_DX;
    dy = BALL_DY;

    //Set the image properties.
    image.setOrigin(radius, radius);
    image.setRadius(radius);
    image.setPosition(currentPos);
    image.setTexture(texture);
    image.setTextureRect(textureRect);
}

void Ball::update()
{
    currentPos.x += dx;
    currentPos.y += dy;
    image.setPosition(currentPos);
}

void Ball::bounce(Paddle player1, Paddle player2, sf::Sound &blif)
{
    //Wall collisions.
    if(currentPos.x-radius < 0 || currentPos.x+radius > SCREEN_WIDTH)
    {
        blif.play();
        dx = -dx;
    }
    //Collision with paddle
    if(this->image.getPosition().y - this->image.getRadius() <= 5)
    {
        if(this->image.getPosition().x >= player1.image.getPosition().x - player1.image.getSize().x/2 && this->image.getPosition().x <= player1.image.getPosition().x + player1.image.getSize().x/2)
        {
            blif.play();
            dy = -dy;
        }
    }
    else if(this->image.getPosition().y + this->image.getRadius() >= SCREEN_HEIGHT-5)
    {
        if(this->image.getPosition().x >= player2.image.getPosition().x - player2.image.getSize().x/2 && this->image.getPosition().x <= player2.image.getPosition().x + player2.image.getSize().x/2)
        {
            blif.play();
            dy = -dy;
        }
    }
}

bool Ball::checkColloision()
{
    //Function returns true if ball goes out of screen else false.
    if(currentPos.y - radius > SCREEN_HEIGHT || currentPos.y + radius < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Ball::addScore(int &score1, int &score2)
{
    if(currentPos.y+radius < 0)
    {
        score2++;
    }
    else
    {
        score1++;
    }
}

Ball::~Ball()
{
    //dtor
}
