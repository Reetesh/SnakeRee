#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "food.h"

int main()
{

    sf::Int32 score = 1;
	sf::Vector2f currPos;
	float width=10.0, height=10.0;
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

	sf::FloatRect headBox, bodyBox, foodBox;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "My Window!");
	sf::RectangleShape head(sf::Vector2f(width, height));
	sf::FloatRect boundary(sf::Vector2f(0,0), sf::Vector2f(windowX-30, windowY-30));

	snakeBody body(width, height);
	food nom(width, height);
	
	head.setPosition(startX, startY);
    head.setFillColor(sf::Color::Green);

	
	body.head->piece->setPosition(startX,startY);
	body.head->piece->setFillColor(sf::Color::Red);
	
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
		window.draw(*body.head->piece);	
        window.draw(head);	
		window.draw(nom.foodPiece);
		// see if head intersects with the window borders
		//currPos = head.getPosition();
		if( boundary.intersects(headBox) )
		{
     	    head.move(dir[t][0], dir[t][1]);
			body.head->piece->move(dir[t][0],dir[t][1]);
			_sleep(10);

		}
		else
		{
			head.setPosition(startX, startY);
			body.head->piece->setPosition(startX,startY);
		}
        window.display();
    }

    return 0;
}