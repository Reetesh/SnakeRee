#include "snakeBody.h"


snakeBody::snakeBody(float width, float height)
{
	
	bodyPiece.setSize(sf::Vector2f(width, height));
	bodyPiece.setScale(-4,1);
}

/*void snakeBody::addPiece(void)
{

}
*/

snakeBody::snakeBody(void)
{
}

snakeBody::~snakeBody(void)
{
}
