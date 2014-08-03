#include "snakeBody.h"


snakeBody::snakeBody(float width, float height)
{
	setWidth(width);
	setHeight(height);
	setLength(0);
	addPiece();
	
}

void snakeBody::addPiece(void)
{
	sf::RectangleShape *block = new sf::RectangleShape;
	*block = sf::RectangleShape(sf::Vector2f(getWidth(), getHeight()));
	block->setScale(-1,1);
	
	body.push_back(block);
	
	setLength(getLength()+1);	

}

void snakeBody::setWidth(float width)
{
	this->width = width;
}

void snakeBody::setHeight(float height)
{
	this->height = height;
}
void snakeBody::setLength(int length)
{
	this->length = length;
}

float snakeBody::getHeight()
{
	return this->height;
}

float snakeBody::getWidth()
{
	return this->width;
}
int snakeBody::getLength()
{
	return this->length;
}

/* TODO Write Cleanup of body */
snakeBody::~snakeBody(void)
{
}

