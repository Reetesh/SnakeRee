#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "food.h"

#define BLOCK_SIZE 10;
#define START_X 50;
#define START_Y 50;
#define WINDOW_X 400;
#define WINDOW_Y 300;
#define INIT_DELAY 100;

int main()
{
	// Using moveDeck to move each body piece individually.
	// body is a deck of pieces.

    int score = 0;
	bool isGameOver = false;
	int frameDelay = INIT_DELAY;
	
	float blockSize= BLOCK_SIZE;
	float startX = START_X;
	float startY = START_Y;
	int windowX = WINDOW_X;
	int windowY = WINDOW_Y;

	int dir = 0;	
	//directions are Right, Down, Left, Up respectively
	int directions[4][2] = {
		{blockSize,0},
		{0,blockSize},
		{-blockSize,0},
		{0,-blockSize}
	};	
	
	sf::Font verdana;
	verdana.loadFromFile("verdana.ttf");
	
	sf::Text scoreText("Score: ", verdana, 20);
	scoreText.setPosition(10,10);
	scoreText.setColor(sf::Color::White);

	sf::Text controlsText("Use directions, space or mouseclick.", verdana, 10);
	controlsText.setPosition(windowX/2, windowY - 10);
	controlsText.setColor(sf::Color::White);

	sf::Text gameOverText("Game Over!", verdana, 20);
	gameOverText.setPosition(windowX/2, windowY/2);

	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "ReeSnake!");
	
	sf::FloatRect boundary(sf::Vector2f(0,0), sf::Vector2f(windowX-blockSize, windowY-blockSize));
	
	snakeBody snake(blockSize, startX, startY);	
	sf::RectangleShape *head = snake.body.front();
	sf::FloatRect headBox;
	
	std::list<sf::RectangleShape*>::iterator snaker;
	
	food nom(blockSize, blockSize);
	nom.placeFoodPiece(windowX, windowY);
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::MouseButtonPressed)
				dir = (dir + 1) % 4;
			if (event.type == sf::Event::KeyPressed ){
				switch (event.key.code){
					case sf::Keyboard::Right:
						dir = 0;
						break;
					case sf::Keyboard::Down:
						dir = 1;
						break;
					case sf::Keyboard::Left:
						dir = 2;
						break;
					case sf::Keyboard::Up:
						dir = 3;
						break;
					case sf::Keyboard::Space:
						dir = (dir + 1) % 4;
						break;
					default:
						break;
				}
			}
        }
        window.clear();
		/* All Draw Stuff here */
		
		headBox = head->getGlobalBounds();
		window.draw(nom.foodPiece);
		window.draw(controlsText);
		scoreText.setString("Score: " + std::to_string(score) );
		window.draw(scoreText);
		//see if snake's head is inside the window boundary
		if( !isGameOver && boundary.intersects(headBox) )
		{

			std::deque<int>::iterator dp = snake.moveDeck.begin();
			//got through each piece of snake's body
			for( snaker = snake.body.begin(); snaker != snake.body.end(); ++snaker)
			{	
				//if snake tries to eat itself, it dies.
				if( (*snaker != head) &&  ( head->getPosition() == (*snaker)->getPosition()) )  {
					isGameOver = true;
				}

				//move snake according to the moveDeck
				(*snaker)->move(directions[*dp][0],directions[*dp][1]);
				window.draw(**snaker);
				dp++;

			}
			snake.moveDeck.push_front(dir);
			snake.moveDeck.pop_back();

			//if head touches food piece
			if( headBox.intersects(nom.foodPiece.getGlobalBounds() )) {
				//add a piece to snake, grow in lenght
				snake.addPiece(snake.moveDeck.back());
				snake.moveDeck.push_back(snake.moveDeck.back());
				window.draw(*snake.body.back());
				
				//place food piece some other place.
				nom.placeFoodPiece(windowX, windowY);
				
				//increase score
				score++;
			}
		}
		//snake dies if it goes outside the boundary.
		else 
		{
			gameOverText.setColor(sf::Color::Color(rand()*255,rand()*255,rand()*255));
			window.draw(gameOverText);
		}
		
		_sleep(frameDelay - (score*2));
        window.display();
    }

    return 0;
}