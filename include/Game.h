#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <Paddle.h>
#include <Ball.h>

class Game
{
    public:
        Game();
        void processEvents();
        void runLogic();
        void drawObjects();
        ~Game();

    private:
        void reset();

    public:
        sf::RenderWindow window;

    private:
        Paddle player1, player2;

        sf::Font chlorine, blackcha;
        sf::Text titleText, instructions, gameOverText;

        Ball ball;
        bool playing, gameOver;
        sf::Texture playerTexture, bg;
        sf::RectangleShape bgRect;

        //Variables for scores.
        int player1_score, player2_score;
        sf::Text player1_scoreText, player2_scoreText;
};

#endif // GAME_H
