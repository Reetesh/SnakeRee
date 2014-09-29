#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "food.h"

#define BLOCK_SIZE 10;
#define START_X 50;
#define START_Y 50;
#define WINDOW_X 400;
#define WINDOW_Y 300;

int main()
{
	// Using moveDeck to move each body piece individually.
	// body is a deck of pieces.

    int score = 1;
	bool isGameOver = false;
	
	float blockSize= BLOCK_SIZE;
	float startX = START_X;
	float startY = START_Y;
	int windowX = WINDOW_X;
	int windowY = WINDOW_Y;

	int dir = 0;	
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

	sf::Text gameOverText("Game Over!", verdana, 20);
	gameOverText.setFont(verdana);
	gameOverText.setPosition(windowX/2, windowY/2);

	sf::FloatRect headBox, bodyBox, foodBox;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "ReeSnake!");
	
	sf::FloatRect boundary(sf::Vector2f(0,0), sf::Vector2f(windowX-blockSize, windowY-blockSize));

	snakeBody snake(blockSize, startX, startY);	
	sf::RectangleShape *head = snake.body.front();
	sf::RectangleShape *neck = snake.body.back();
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
			if (event.type == sf::Event::MouseButtonPressed){
				dir = (dir + 1) % 4;	
			}
        }
        window.clear();
		/* All Draw Stuff here */
		
		headBox = head->getGlobalBounds();
		window.draw(nom.foodPiece);
		scoreText.setString("Score: " + std::to_string(score) );
		window.draw(scoreText);
		//see if snake's head is inside the window boundary
		if( !isGameOver && boundary.intersects(headBox) )
		{
			//if head touches food piece
			if( headBox.intersects(nom.foodPiece.getGlobalBounds() )) {
				//add a piece to snake, grow in lenght
				snake.addPiece(snake.moveDeck.back());
				snake.moveDeck.push_back(dir);
				
				//place food piece some other place.
				nom.placeFoodPiece(windowX, windowY);
				
				//increase score
				score++;
			}

			snake.moveDeck.push_front(dir);
			std::deque<int>::iterator dp = snake.moveDeck.begin();
			//got through each piece of snake's body
			for( snaker = snake.body.begin(); snaker != snake.body.end(); ++snaker)
			{	
				//move snake according to the moveDeck
				(*snaker)->move(directions[*dp][0],directions[*dp][1]);
				window.draw(**snaker);
				dp++;
				//if snake tries to eat itself, it dies.
				if( (*snaker != head) && (*snaker != neck) && headBox.intersects((*snaker)->getGlobalBounds()) ) {
					isGameOver = true;
				}
			}
			snake.moveDeck.pop_back();
		}
		//snake dies if it goes outside the boundary.
		else 
		{
			gameOverText.setColor(sf::Color::Color(rand()*255,rand()*255,rand()*255));
			window.draw(gameOverText);
		}
		_sleep(100);
        window.display();
    }

    return 0;
}