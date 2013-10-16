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

	
	sf::FloatRect headBox, bodyBox, foodBox;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "My Window!");
	sf::RectangleShape head(sf::Vector2f(width, height));
	sf::FloatRect boundary(sf::Vector2f(0,0), sf::Vector2f(windowX-30, windowY-30));

	snakeBody body(width, height);
	food nom(width, height);
	
	head.setPosition(startX, startY);
    head.setFillColor(sf::Color::Green);

	body.bodyPiece.setFillColor(sf::Color::Red);
	body.bodyPiece.setPosition(startX,startY);

	nom.placeFoodPiece(windowX, windowY);
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		// All Draw Stuff here
		headBox = head.getGlobalBounds();
		//bodyBox	= body.getGlobalBounds();

		//if(headBox.intersects(bodyBox)
		window.draw(body.bodyPiece);	
        window.draw(head);	
		window.draw(nom.foodPiece);
		// see if head intersects with the window borders
		//currPos = head.getPosition();
		if( boundary.intersects(head.getGlobalBounds()) )
		{
			head.move(1,0);	
			_sleep(10);

		}
        window.display();
    }

    return 0;
}