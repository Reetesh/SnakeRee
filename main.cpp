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
		{1,0},
		{0,1},
		{-1,0},
		{0,-1}
	};
	std::deque<int> moveDeck;
	

	sf::FloatRect headBox, bodyBox, foodBox;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "ReeSnake!");
	
	sf::FloatRect boundary(sf::Vector2f(0,0), sf::Vector2f(windowX-blockSize, windowY-blockSize));

	snakeBody snake(blockSize, startX, startY);
	food nom(blockSize, blockSize);
	sf::RectangleShape *head  = snake.body.front();
	std::list<sf::RectangleShape*>::iterator snaker;
	
	
	
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

     	    
			for( snaker = snake.body.begin(); snaker != snake.body.end(); ++snaker)
			{
				(*snaker)->move(dir[t][0],dir[t][1]);
				window.draw(**snaker);
			}
			_sleep(10);
		}
		else
		{
			snake.body.front()->setPosition(startX,startY);
		}
        window.display();
    }

    return 0;
}