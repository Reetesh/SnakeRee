#include "food.h"
#include <stdlib.h>
#include <time.h>

void food::placeFoodPiece(int windowX, int windowY)
{
	int randX, randY;
	
	srand(time(NULL));
	randX = (rand()*365) % (windowX);// - (int) ceil(width));
	srand(time(NULL));
	randY = (rand()*455) % (windowY);// - (int) ceil(height));

	foodPiece.setPosition(randX, randY);
	foodPiece.setFillColor(sf::Color::Color(rand()*255,rand()*255, 255));
}

food::food(float width, float height)
{
	foodPiece.setSize(sf::Vector2f(width, height));
}

food::food(void)
{
}

food::~food(void)
{
}
