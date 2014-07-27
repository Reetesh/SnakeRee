#include "snakeBody.h"


snakeBody::snakeBody(float width, float height)
{
	setWidth(width);
	setHeight(height);
	setLength(0);
	head = addPiece();
	
}

snakeBody::body* snakeBody::addPiece(void)
{
	struct body *piece = new struct body;
	sf::RectangleShape  *block = new sf::RectangleShape;
	*block = sf::RectangleShape(sf::Vector2f(getWidth(), getHeight()));
	block->setScale(-1,1);
	
	piece->piece = block;
	piece->next = NULL;
	setLength(getLength()+1);
	tail  = piece;
	return piece;
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

/*
** Write Cleanup of body
snakeBody::~snakeBody(void)
{
}
*/
