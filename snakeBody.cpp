#include "snakeBody.h"


snakeBody::snakeBody(float size, float startX, float startY)
{
	setSize(size);
	head = new sf::RectangleShape(sf::Vector2f(getSize(), getSize()));
	head->setPosition(startX, startY);
    head->setFillColor(sf::Color::Green);
	body.push_back(head);
	setLength(1);
	addPiece(0);
	moveDeck.push_back(0);
	moveDeck.push_back(0);
}

void snakeBody::addPiece(int direction)
{
	sf::RectangleShape *block = new sf::RectangleShape;
	*block = sf::RectangleShape(sf::Vector2f(getSize(), getSize()));
	sf::Vector2f tailPos = body.back()->getPosition();;
	
	switch (direction){
		case 0:
			block->setPosition(tailPos.x - getSize(), tailPos.y);
			break;
		case 1:
			block->setPosition(tailPos.x, tailPos.y - getSize());
			break;
		case 2:
			block->setPosition(tailPos.x + getSize(), tailPos.y);
			break;
		case 3:
			block->setPosition(tailPos.x, tailPos.y + getSize());
			break;
	}

	sf::Color pieceColor(rand()*255, rand()*255, rand()*255);
	block->setFillColor(pieceColor);
	
	body.push_back(block);
	setLength(getLength()+1);	

}

void snakeBody::setSize(float size)
{
	this->size = size;
}

void snakeBody::setLength(int length)
{
	this->length = length;
}

float snakeBody::getSize()
{
	return this->size;
}

int snakeBody::getLength()
{
	return this->length;
}

/* TODO Write Cleanup of body */
snakeBody::~snakeBody(void)
{
}

