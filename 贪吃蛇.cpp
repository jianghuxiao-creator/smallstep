#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <conio.h> //接收键盘
#include <ctime>
#include <mmsystem.h>             //多媒体接口
#pragma comment(lib,"winmm.lib")
using namespace std;

//欢迎界面
void welcome(string str);

//游戏规则
void gameRule();

//游戏边界
void snakeBoundary();

//光标定位
void setCursor(int x, int y);

//蛇
class Snake
{
public:
	int x;
	int y;
	Snake *next;		
};
Snake *pHead = new Snake();

//得分
double score; 

//食物
class Food
{
public:
	int x;
	int y;
	int foodFlag;      //flag = 0没有被吃，flag = 1被吃
	int score;        //分数
};
Food *food = new Food();

//蛇的初始化
void SnakeInit();

//蛇的移动
void SnakeMove();

//食物跳动
void FoodSkip();

//解决食物出现在蛇身上
//void foodCoverSnake();

//食物被吃
void EatFood();

// 游戏失误
void gameError();

//游戏结束界面
void gameOver();

// 获取方向
char getDirection();

int main()
{
	loop:
	//背景音乐	
	mciSendString("open 甩葱歌.mp3 alias bk", 0, 0, 0);
	mciSendString("Play bk repeat", 0, 0, 0);

	welcome("欢迎来到贪吃蛇游戏，祝你游戏愉快！");
	system("cls");
	//游戏规则
	gameRule();

	system("cls");
	snakeBoundary();
	SnakeInit();
	FoodSkip();	
	SnakeMove();	
	system("pause");
	if (_kbhit())
	{
		goto loop;
	}
	return 0;
}

//欢迎界面
void welcome(string str)
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t';
	cout << str << endl;
	setCursor(50, 15);
	system("pause");
	return;
}

//游戏规则
void gameRule()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t';
	cout << "↑向上走  ←向左走   ↓向下走   →向右走" << endl;	
	cout << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t';
	cout << "吃到一个食物得十分." << endl;
	setCursor(50, 15);
	system("pause");
	return;
}



//游戏边界
void snakeBoundary()
{
	for (int i = 0; i < 60; i += 2)
	{
		setCursor(i, 0);
		cout << "■";
		setCursor(i,25);
		cout << "■";

	}
	for (int i = 0; i <= 25; i++)
	{
		setCursor(0, i);
		cout << "■";
		setCursor(60, i);
		cout << "■";
	}

	setCursor(80, 10);
	cout << "↑ 向上走.     ↓向下走.";
	setCursor(80, 11);
	cout << "← 向左走.     →向右走.";
	setCursor(80, 12);
	cout << "吃到一个食物得10分.";
	setCursor(80, 15);
	cout << "当前得分： ";
	return;

}

//光标定位
void setCursor(int x,int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos;
	cursorPos.X = x;
	cursorPos.Y = y;
	SetConsoleCursorPosition(hStdout, cursorPos);
//	CloseHandle(hStdout);
	return;
}

//蛇的初始化
void SnakeInit()
{
	

	////背景yanse
	//setbkcolor(RGB(220, 20, 150));
	//cleardevice();
	pHead->x = 10;
	pHead->y = 10;
	pHead->next = NULL;
	score = 0.0;

	for (int i = 0; i < 4; i++)
	{
		Snake *snakeNode = new Snake();
		snakeNode->x = pHead->x + 2;
		snakeNode->y = pHead->y ;
		snakeNode->next = pHead;
		pHead = snakeNode;
	}	
	Snake *p = new Snake();
	p = pHead;
	while (p->next != NULL)
	{
		setCursor(p->x, p->y);
		cout <<"■";
		p = p->next;
	}
	setCursor(pHead->x, pHead->y);	
	return ;
}

//蛇的移动
void SnakeMove()
{	
	char flag = '0';
	char flagOld = '0';
	//默认向右走
	while (!_kbhit())
	{
		//游戏失误
		gameError();

		//吃到食物
		EatFood();
		if (food->foodFlag == 1)
		{
			delete food;
			FoodSkip();
			
		}

		Snake *newSnakeNode = new Snake();
		newSnakeNode->x = pHead->x + 2;
		newSnakeNode->y = pHead->y;
		newSnakeNode->next = pHead;
		pHead = newSnakeNode;

		Snake *p = pHead;
		while (p->next->next != NULL)
		{
			setCursor(p->x, p->y);
			cout << "■";
			p = p->next;
		}	
		setCursor(p->x, p->y);
		cout << " ";
		delete p->next;
		p->next = NULL;
		Sleep(250);
	} //end 默认向右走

	while (1)
	{	
		flagOld = flag;

		if (_kbhit())
		{
			flag = getDirection();//获取方向
		}
			
		
			switch (flag) 
			{
			case '6'://向右走

				while (!_kbhit() && flagOld != '4')
				{		
					//游戏失误
					gameError();

					//吃到食物
					EatFood();
					if (food->foodFlag == 1)
					{
						FoodSkip();
					}

					Snake *newSnakeNode = new Snake();
					newSnakeNode->x = pHead->x + 2;
					newSnakeNode->y = pHead->y;
					newSnakeNode->next = pHead;
					pHead = newSnakeNode;					
					
					Snake *p = pHead;
					while (p->next->next != NULL)
					{
						setCursor(p->x, p->y);
						cout << "■";
						p = p->next;
					}
					
					setCursor(p->x, p->y);
					cout << " ";
					

					delete p->next;
					p->next = NULL;
					Sleep(250);
					
				}
				break;
			case '8'://向上走
				while (!_kbhit() && flagOld != '2')
				{	
					//游戏失误
					gameError();

					//吃到食物
					EatFood();
					if (food->foodFlag == 1)
					{
						FoodSkip();
					}

					Snake *newSnakeNode = new Snake();
					newSnakeNode->x = pHead->x;
					newSnakeNode->y = pHead->y - 1;
					newSnakeNode->next = pHead;
					pHead = newSnakeNode;										

					Snake *p = pHead;
					while (p->next->next != NULL)
					{
						setCursor(p->x, p->y);
						cout << "■";
						p = p->next;
					}
					
						setCursor(p->x, p->y);
						cout << " ";
					

					delete p->next;
					p->next = NULL;

					Sleep(250);
				}

				break;
			case '4':
				//向左走
				while (!_kbhit() && flagOld != '6')
				{	
					//游戏失误
					gameError();

					//吃到食物
					EatFood();
					if (food->foodFlag == 1)
					{
						FoodSkip();
					}

					Snake *newSnakeNode = new Snake();
					newSnakeNode->x = pHead->x - 2;
					newSnakeNode->y = pHead->y;
					newSnakeNode->next = pHead;
					pHead = newSnakeNode;
					setCursor(newSnakeNode->x, newSnakeNode->y);
					
					Snake *p = pHead;
					while (p->next->next != NULL)
					{
						setCursor(p->x, p->y);
						cout << "■";
						p = p->next;
					}
					
						setCursor(p->x, p->y);
						cout << " ";
					

					delete p->next;
					p->next = NULL;

					Sleep(250);					
				}
				break;
			case '2':
				//向下走
				while (!_kbhit() && flagOld != '8')
				{	
					//游戏失误
					gameError();

					//吃到食物
					EatFood();
					if (food->foodFlag == 1)
					{
						FoodSkip();
					}

					Snake *newSnakeNode = new Snake();
					newSnakeNode->x = pHead->x;
					newSnakeNode->y = pHead->y + 1;
					newSnakeNode->next = pHead;
					pHead = newSnakeNode;
					
					Snake *p = pHead;
					while (p->next->next != NULL)
					{
						setCursor(p->x, p->y);
						cout << "■";
						p = p->next;
					}

					
						setCursor(p->x, p->y);
						cout << " ";
					

					delete p->next;
					p->next = NULL;

					Sleep(250);					
				}
				break;
			}
			
	}					
}

//食物跳动
void FoodSkip()
{
	//Food *food = new Food();	
	srand((unsigned)time(0));

	food->x = (1 + rand() % 29) * 2;
	food->y = 1 + rand() % 24;
	food->foodFlag = 0;
	
	Snake *p = pHead->next;
	do
	{
		if (p->x == food->x && p->y == food->y)
		{
			Sleep(1);
			FoodSkip();
			break;
		}
		p = p->next;
	} while (p->next != NULL);
	
	setCursor(food->x, food->y);
	cout << "■";
	return ;
}



void EatFood()
{	
	food->foodFlag = 0;
		if ((pHead->x == food->x) && (pHead->y == food->y)) //吃到
		{
			Snake *snakeNewNode = new Snake();          //蛇的长度加1
			snakeNewNode->x = food->x;
			snakeNewNode->y = food->y;
			snakeNewNode->next = pHead;
			pHead = snakeNewNode;

			food->foodFlag = 1;

			setCursor(food->x, food->y);       //删除被吃掉的食物
			cout << " ";	

			score = score + 10;
			setCursor(96,15);
			cout <<  score;		

		}
		return ;
}

// 游戏失误
void gameError()
{
	if (pHead->x < 1 || pHead->x > 59 || pHead->y < 1 || pHead->y > 24)
	{
		gameOver();
	}
	Snake *p = pHead->next;
	
	do
	{
		if (p->x == pHead->x && p->y == pHead->y)
		{
			gameOver();
			return;
		}
		p = p->next;
	} while (p->next != NULL);	
	return;
}

//游戏结束界面
void gameOver()
{
	system("cls");
	//system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t';
	cout << "最终得分：" << score << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t';
	cout << "游戏结束，你超过了99%的游戏玩家！" << endl << endl;

	setCursor(50, 15);
	system("pause");
	return;
}

//获取方向
char getDirection()
{
	int key, key2;	
	key = _getch();
	if (key == 224)
	{
		key2 = _getch();
		if (key2 == 72)
		{
			return '8'; //上箭头.
		}
		if (key2 == 80)
		{
			return '2'; //下箭头.
		}
		if (key2 == 75)
		{
			return '4'; //左箭头.
		}
		if (key2 == 77)
		{
			return '6'; //右箭头
		}
	}
	return 'n';
}