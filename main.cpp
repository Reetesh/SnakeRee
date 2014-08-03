#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "food.h"
#include <deque> 

int main()
{

    sf::Int32 score = 1;
	sf::Vector2f currPos;
	float blockSize=10.0;
	float startX = 50, startY = 50;
	int windowX = 200, windowY = 200;
	int *foodXY;
	int t = 0;
	int dir[4][2] = {
		{blockSize,0},
		{0,blockSize},
		{-blockSize,0},
		{0,-blockSize}
	};	
	

	sf::FloatRect headBox, bodyBox, foodBox;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "ReeSnake!");
	
	sf::FloatRect boundary(sf::Vector2f(0,0), sf::Vector2f(windowX-blockSize, windowY-blockSize));

	snakeBody snake(blockSize, startX, startY);
	food nom(blockSize, blockSize);
	sf::RectangleShape *head  = snake.body.front();
	std::list<sf::RectangleShape*>::iterator snaker;
	
	std::deque<int> moveDeck;
	moveDeck.push_back(0);
	moveDeck.push_back(0);
	moveDeck.push_back(0);
	
	nom.placeFoodPiece(windowX, windowY);
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::MouseButtonReleased)
                t = (t + 1) % 4;
        }

        window.clear();
		// All Draw Stuff here
		headBox = head->getGlobalBounds();
		//bodyBox	= body.getGlobalBounds();

		//if(headBox.intersects(bodyBox)
		window.draw(nom.foodPiece);
		// see if head intersects with the window borders
		//currPos = head.getPosition();
		if( boundary.intersects(headBox) )
		{
			moveDeck.push_front(t);
			std::deque<int>::iterator dp = moveDeck.begin();
			
			for( snaker = snake.body.begin(); snaker != snake.body.end(); ++snaker)
			{	
				(*snaker)->move(dir[*dp][0],dir[*dp][1]);
				window.draw(**snaker);
				dp++;
			}
			_sleep(100);
			moveDeck.pop_back();
		}
		else
		{
			snake.body.front()->setPosition(startX,startY);
		}
        window.display();
    }

    return 0;
}