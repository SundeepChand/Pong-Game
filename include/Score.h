#ifndef SCORE_H
#define SCORE_H
#include "SFML/Graphics.hpp"

class Score
{
    public:
        Score();
        void update();
        void setFont(sf::Font font);
        void setPosition(sf::Vector2f pos);
        ~Score();

    private:
        int score;
        sf::String str;

    public:
        sf::Text scoreText;
};

#endif // SCORE_H
