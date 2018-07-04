#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Paddle.h>

class Ball
{
    public:
        Ball();
        Ball(sf::Texture* texture, sf::Vector2f initPos, sf::IntRect textureRect);
        void update();
        void bounce(Paddle player1, Paddle player2, sf::Sound &blif);
        bool checkColloision();
        void addScore(int &score1, int &score2);
        ~Ball();

    public:
        sf::CircleShape image;

    private:
        sf:: Vector2f currentPos;
        float radius;
        float dx, dy;
};

#endif // BALL_H
