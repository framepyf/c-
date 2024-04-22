#include "snake.h"
#include <stdlib.h>


Snake::Snake(Wall & tempWall, Food & tmpFood) : wall(tempWall), food(tmpFood)
{
	pHead = NULL;
	isRool = false;
}


void Snake::initSnake()
{
	destroyPoint();

	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

void Snake::destroyPoint()
{
	Point * pCur = pHead;

	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete pHead;

		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{

	Point * newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;



	if (pHead != NULL)
	{
		wall.setWall(pHead->x, pHead->y, '=');
	}

	newPoint->next = pHead;
	pHead = newPoint; 


	wall.setWall(pHead->x, pHead->y, '@');


}

void Snake::delPoint()
{
	
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}

	Point * pCur = pHead->next;
	Point * pPre = pHead;

	while (pCur->next !=NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}


	wall.setWall(pCur->x, pCur->y, ' ');

	delete pCur;
	pCur = NULL;
	pPre->next = NULL;

}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y; 

	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN :
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}


	Point * pCur = pHead->next;
	Point * pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	
	if (pCur->x == x && pCur->y == y)
	{
		isRool = true;
	}
	else
	{
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			addPoint(x, y);
			delPoint();
			system("clear");
			wall.drawWall();
			cout << "GAME OVER!!!" << endl;
			return false;
		}
	}


	if (wall.getWall(x,y) == '#')
	{
		addPoint(x, y);

		food.setFood();
	}
	else
	{
		addPoint(x, y);
		delPoint();
		if (isRool == true)
		{
			wall.setWall(x, y, '@');
		}
		
	}

	return true;
}

