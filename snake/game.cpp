#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/select.h>

/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>



void changemode(int dir)
{
  static struct termios oldt, newt;
 
  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
int kbhit (void)
{
  struct timeval tv;
  fd_set rdfs;
 
  tv.tv_sec = 0;
  tv.tv_usec = 0;
 
  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);
 
  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
 
}



int main(){

	changemode(1);

	//添加随机种子
	srand((unsigned int)time(NULL));

	//是否死亡标示
	bool isDead = false;

	char preKey = 0;

	Wall wall;
	wall.initWall();
	
	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();

	//snake.move('w');
	//snake.move('w');
	//snake.move('a');

	wall.drawWall();


	//接受用户输入


	while (!isDead)
	{
		char key = getchar();

		//判断 如果是第一次按了 左键 才不能激活游戏
		// 判断 上一次 移动方向
		if (preKey == 0 && key == snake.LEFT)
		{
			continue;
		}

		do 
		{
			if (key == snake.UP || key  == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//判断本次按键 是否与上次冲突
				if ( (key == snake.LEFT && preKey == snake.RIGHT)  ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;
				}
				else
				{
					preKey = key; //不是冲突按键  可以更新按键
				}


				if (snake.move(key) == true)
				{
					//移动成功 代码
					system("clear");
					wall.drawWall();
					usleep(100000);
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey; //强制将错误按键变为 上一次移动的方向
			}
			

		} while (!kbhit()); //当没有键盘输入的时候 返回0

	
	}

	

	


	////测试
	//wall.setWall(5, 4, '=');
	//wall.setWall(5, 5, '=');
	//wall.setWall(5, 6, '@');

	//

	//cout << wall.getWall(0, 0) << endl;
	//cout << wall.getWall(5, 4) << endl;
	//cout << wall.getWall(5, 6) << endl;
	//cout << wall.getWall(1, 1) << endl;
	changemode(0);
	return EXIT_SUCCESS;
}
