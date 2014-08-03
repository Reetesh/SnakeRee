#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "food.h"
#include <deque> 

int main()
{

    sf::Int32 score = 1;
	sf::Vector2f currPos;
	float blockWidth=10.0, blockHeight=10.0;
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
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "My Window!");
	sf::RectangleShape head(sf::Vector2f(blockWidth, blockHeight));
	sf::FloatRect boundary(sf::Vector2f(0,0), sf::Vector2f(windowX-blockWidth, windowY-blockHeight));

	snakeBody snake(blockWidth, blockHeight);
	food nom(blockWidth, blockHeight);

	std::list<sf::RectangleShape*>::iterator snaker;
	
	head.setPosition(startX, startY);
    head.setFillColor(sf::Color::Green);
	
	snake.body.front()->setPosition(startX,startY);
	snake.body.front()->setFillColor(sf::Color::Red);
	
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
		headBox = head.getGlobalBounds();
		//bodyBox	= body.getGlobalBounds();

		//if(headBox.intersects(bodyBox)
		window.draw(*snake.body.front());	
        window.draw(head);	
		window.draw(nom.foodPiece);
		// see if head intersects with the window borders
		//currPos = head.getPosition();
		if( boundary.intersects(headBox) )
		{
			moveDeck.push_front(t);

     	    head.move(dir[t][0], dir[t][1]);
			for( snaker = snake.body.begin(); snaker != snake.body.end(); ++snaker)
			{
				(*snaker)->move(dir[t][0],dir[t][1]);
			}
			_sleep(10);
		}
		else
		{
			head.setPosition(startX, startY);
			snake.body.front()->setPosition(startX,startY);
		}
        window.display();
    }

    return 0;
}