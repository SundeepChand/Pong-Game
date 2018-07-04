#include <Game.h>
#include <Constants.h>
#include <Ball.h>
#include <string>

Game::Game()
{
    //Initialize the variables.
    playing = false;
    gameOver = false;

    //Load the textures.
    bg.loadFromFile("Textures/bg.png");
    playerTexture.loadFromFile("Textures/sprites.png");

    //Load the sounds.
    buffer.loadFromFile("Sounds/blif.wav");
    blif.setBuffer(buffer);

    //Create the window.
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong", sf::Style::Close);

    //Set mouse pointer invisible.
    window.setMouseCursorVisible(false);

    //Set the background image.
    bgRect.setSize(sf::Vector2f(512, 512));
    bgRect.setTexture(&bg);

    //Load the fonts.
    blackcha.loadFromFile("Fonts/blackcha.ttf");
    chlorine.loadFromFile("Fonts/chlorine.ttf");

    //Set the texts.
    titleText = sf::Text("PONG", chlorine, 80);
    titleText.setFillColor(sf::Color(252, 191, 7, 235));
    titleText.setOrigin(sf::Vector2f(titleText.getLocalBounds().width/2, titleText.getLocalBounds().height/2));
    titleText.setPosition(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2-100));

    instructions = sf::Text("Press space to Play.", chlorine, 30);
    instructions.setFillColor(sf::Color(252, 191, 7, 235));
    instructions.setOrigin(sf::Vector2f(titleText.getLocalBounds().width/2, titleText.getLocalBounds().height/2));
    instructions.setPosition(sf::Vector2f(SCREEN_WIDTH/2-45, SCREEN_HEIGHT/2+120));

    gameOverText = sf::Text("Game Over", chlorine, 50);
    gameOverText.setFillColor(sf::Color(252, 191, 7, 235));
    gameOverText.setOrigin(sf::Vector2f(gameOverText.getLocalBounds().width/2, gameOverText.getLocalBounds().height/2));
    gameOverText.setPosition(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2-50));

    //Create the player.
    player1 = Paddle(&playerTexture, sf::Vector2f(SCREEN_WIDTH/2, 10), sf::IntRect(113, 58, 122, 32));   //Upper player is player1.
    player2 = Paddle(&playerTexture, sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT-10), sf::IntRect(113, 110, 122, 32));  //Lower player is player2.

    //Create the ball.
    ball = Ball(&playerTexture, sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2), sf::IntRect(105, 5, 38, 40));

    //Set scores.
    player1_score = 0;
    player2_score = 0;
    player1_scoreText = sf::Text("Score: "+std::to_string(player1_score), blackcha, 30);
    player2_scoreText = sf::Text("Score: "+std::to_string(player2_score), blackcha, 30);
    player1_scoreText.setPosition(sf::Vector2f(20, SCREEN_HEIGHT/2-40-player1_scoreText.getLocalBounds().height));
    player2_scoreText.setPosition(sf::Vector2f(20, SCREEN_HEIGHT/2+40));
    player1_scoreText.setFillColor(sf::Color(74, 244, 32));
    player2_scoreText.setFillColor(sf::Color(250, 63, 254));
}

void Game::processEvents()
{
    //Main event loop
    sf::Event event;
    while(window.pollEvent(event))
    {
        //Request to close the window.
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }
        //Request to start the game.
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
            if(!playing && !gameOver)
            {
                playing = true;
                gameOver = false;
            }
            else if(playing && gameOver)
            {
                reset();
            }
        }

        //Move player2.
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
        {
            player2.move(true);
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
        {
            player2.move(false);
        }
        if(event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right))
        {
            player2.stop();
        }

        //Move player1.
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
        {
            player1.move(true);
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
        {
            player1.move(false);
        }
        if(event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A))
        {
            player1.stop();
        }
    }
}

void Game::runLogic()
{
    if(!playing && !gameOver)
    {

    }
    else if(playing && !gameOver)
    {
        player1.update();
        player2.update();
        ball.update();
        ball.bounce(player1, player2, blif);
        gameOver = ball.checkColloision();
        if(gameOver)
        {
            //Increment the score.
            ball.addScore(player1_score, player2_score);
            player1_scoreText.setString("Score: "+std::to_string(player1_score));
            player2_scoreText.setString("Score: "+std::to_string(player2_score));
        }
    }
}

void Game::drawObjects()
{
    //Draw to the screen.
    window.clear(sf::Color::Black);
    window.draw(bgRect);
    window.draw(player1.image);
    window.draw(player2.image);
    window.draw(ball.image);

    if(!playing && !gameOver)
    {
        window.draw(titleText);
        window.draw(instructions);
    }
    else if(playing)
    {
        //Draw scores.
        window.draw(player1_scoreText);
        window.draw(player2_scoreText);
        if(gameOver)
        {
            window.draw(gameOverText);
            window.draw(instructions);
        }
    }
    window.display();
}


void Game::reset()
{
    //Reset everything.
    playing = true;
    gameOver = false;

    player1 = Paddle(&playerTexture, sf::Vector2f(SCREEN_WIDTH/2, 10), sf::IntRect(113, 58, 122, 32));   //Upper player is player1.
    player2 = Paddle(&playerTexture, sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT-10), sf::IntRect(113, 110, 122, 32));  //Lower player is player2.

    ball = Ball(&playerTexture, sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2), sf::IntRect(105, 5, 38, 40));
}

Game::~Game()
{
    //dtor
}
