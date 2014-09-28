#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "food.h"

#define BLOCK_SIZE 10;
#define START_X 50;
#define START_Y 50;
#define WINDOW_X 200;
#define WINDOW_Y 200;

int main()
{
	// Using moveDeck to move each body piece individually.
	// body is a deck of pieces.

    sf::Int32 score = 1;
	
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
		
		//see if snake's head is inside the window boundary
		if( boundary.intersects(headBox) )
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
					exit(-1);
				}
			}
			_sleep(100);
			snake.moveDeck.pop_back();
		}
		//snake dies if it goes outside the boundary.
		else
		{
			exit(-1);
		}

        window.display();
    }

    return 0;
}