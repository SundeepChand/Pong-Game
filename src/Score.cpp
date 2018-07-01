#include "Score.h"
#include "SFML/Graphics.hpp"
#include "string"

Score::Score()
{
    score = 0;
    str = sf::String("Score: "+std::to_string(score));
    scoreText.setString(str);
}

void Score::setFont(sf::Font font)
{
    scoreText.setFont(font);
}

void Score::setPosition(sf::Vector2f pos)
{
    scoreText.setPosition(pos);
}

void Score::update()
{
    score++;
    str.replace(std::to_string(score-1), std::to_string(score));
    scoreText.setString(str);
}

Score::~Score()
{
    //dtor
}
