// 贪吃蛇二代.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define WALL "■"
#define FOOD "●"
#define SNAKE "◆"
#define LONG__MAX 30
#define WIDTH_MAX 60
#define BAR_MAX 24

using namespace std;
struct spot
{
    int x;
    int y;
};//定义的坐标类
spot barrier[BAR_MAX];
int timen = 5;
void Late() {//延时函数
	for (int i = 0; i <= pow(22, timen); ++i)
		;
}
bool operator == (spot a, spot b)
{
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;
}
void setSpot(int x, int y) {//查的资料，控制光标移动的函数
	HANDLE winHandle;
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);
}

class snake_node//节点类
{private:
	spot s;
	snake_node* p_front;
	snake_node* p_next;
	friend class snake_list;//便于访问节点数据
public:
	snake_node(spot a);
	friend ostream& operator >>(ostream& os, snake_node);
	spot get_node()
	{
		return s;
	}
	snake_node* get_next()
	{
		return p_next;
	}
};
snake_node::snake_node(spot a)
{
	s = a;
	p_front = NULL;
	p_next = NULL;
}
ostream& operator >>(ostream& os, snake_node)
{
	os << SNAKE;
	return os;
}
class snake_list//链表类
{
private:
	snake_node* head;
	snake_node* tail;
	char direction;
	bool life;//记录蛇是否生存

public:
	snake_list();
	void insert(spot pos);
	void movep();
	void move();
	void collision_wall();
	void collision_self();
	bool eaten(spot food);
	void print_snake();
	snake_node* get_head();
	bool get_life();
};

snake_node* snake_list::get_head()
{
	return head;
}
bool snake_list::get_life()
{
	return life;
}
snake_list::snake_list()
{
	direction = 'a';
	head = NULL;
	tail = NULL;
	life = 1;

}
void snake_list::insert(spot pos)
{
	snake_node * p1;
	p1 = new snake_node(pos);
	if (head == NULL)
	{
		head = p1;
		tail = p1;
	}
	else
	{
		tail->p_next = p1;
		p1->p_front = tail;
		tail = p1;
	}
}void snake_list::movep()
{
	tail->p_next = head;
	head->p_front = tail;
	head = tail;
	tail->p_front->p_next = NULL;
	tail = tail->p_front;
}

void snake_list::move()
{
	if (_kbhit())//判断是否敲击
	{
		char ch = _getch();
		if (ch == 'a')
		{
			if (direction != 'd')
				direction = 'a';

		}
		if (ch == 'd')
		{
			if (direction != 'a')
				direction = 'd';

		}
		if (ch == 'w')
		{
			if (direction != 's')
				direction = 'w';

		}
		if (ch == 's')
		{
			if (direction != 'w')
				direction = 's';

		}
	}
	switch (direction)
	{
	case 'a': {
		movep();
		head->s.x =head->p_next->s.x- 2;
		head->s.y = head->p_next->s.y;
		
	}
			break;
	case'd': {
		movep();
		head->s.x = head->p_next->s.x+2;
		head->s.y = head->p_next->s.y;
	}
		   break;
	case'w': {
		movep();
		head->s.x = head->p_next->s.x;
		head->s.y = head->p_next->s.y-1;
	}
		   break;
	case's': {
		movep();
		head->s.x = head->p_next->s.x;
		head->s.y = head->p_next->s.y+1;

	}
		   break;
	}

}
void snake_list::collision_wall()
{
	if (head->s.x <= 0 || head->s.x >= WIDTH_MAX - 3 || head->s.y <= 0 || head->s.y >= LONG__MAX - 1)
		life = 0;
	for (int i = 0;i < BAR_MAX;i++)
		if (head->s == barrier[i])
			life = 0;

}
void snake_list::collision_self()
{
	snake_node * p=head->p_next;
	while (p != NULL)
	{
		if (head->s == p->s)
		{
			life = 0;
			break;
		}
		p = p->p_next;

	}

}
bool snake_list::eaten(spot food)
{
	if (head->s == food)
	{
		
		insert(tail->s);
		return true;
	}
	return false;
}
void snake_list::print_snake() 
{
	snake_node* p = head;
	while (p != NULL)
	{
		setSpot(p->s.x,p->s.y);
		cout << SNAKE;
		p = p->p_next;

	}


}
class food
{
private:
	spot f;
public:
	food();
	spot get_spot();
	void reset();
	void print_food();
	bool repe_snake(snake_node* p);
	bool repe_barrier(spot* bar);//判断是否重新设置的位置与蛇重合
};
food::food()
{
	f.x = 10;
	f.y = 10;
}
bool food::repe_barrier(spot* bar)
{
	for (int i = 0;i < BAR_MAX;i++)
		if (f == bar[i])
			return true;
	return false;
}
spot food::get_spot()
{
	return f;
}
void food::reset()
{
	do {
		f.x = rand() % (WIDTH_MAX - 5) + 1;//蛇头是2，2，的变化，故食物的横坐标也必须要是偶数
		f.y = rand() % (LONG__MAX - 2) + 1;
	} while (f.x % 2);
}
void food::print_food()
{

	setSpot(f.x, f.y);
	cout << FOOD;
}
bool food::repe_snake(snake_node* head)
{
	snake_node* p  = head;
	while (p != NULL)
	{
		if (p->get_node() == f)
			return true;
		p = p->get_next();

	}
	return false;
}
void set_map();
void set_barrier();
void print_barrier();
int main()
{
	snake_list Sna;
	food Fo;
	for (int i = 0;i < 3;i++)//初始化蛇，长度为3
	{
		spot pos;
		pos.x = WIDTH_MAX/2 + 2*i;
		pos.y = LONG__MAX/2;
		Sna.insert(pos);
	}
	set_barrier();//初始化障碍
	while (Sna.get_life())
	{
		set_map();
		print_barrier();
		Sna.print_snake();
		Fo.print_food();
		Sna.collision_self();
		Sna.collision_wall();
		if (Sna.eaten(Fo.get_spot()))
		{
			do
			{
				Fo.reset();

			} while (Fo.repe_snake(Sna.get_head())||Fo.repe_barrier(barrier));
		}
		Late();
		system("cls");
		Sna.move();
	}

	
}

void set_map()
{
	for (int i = 0;i < WIDTH_MAX-1;i = i + 2)
	{
		setSpot(i, 0);
		cout << WALL;
	}
	for (int i = 1;i < LONG__MAX;i++)
	{
		setSpot(0, i);
		cout << WALL;
		setSpot(WIDTH_MAX - 2, i);
		cout << WALL;
	}
	for (int i = 2;i < WIDTH_MAX - 1;i++)
	{
		setSpot(i, LONG__MAX - 1);
		cout << WALL;
	}
	


}
void print_barrier()
{
	for (int i = 0;i < BAR_MAX;i++)
	{
		setSpot(barrier[i].x,barrier[i].y);
		cout << WALL;
	}

}
void set_barrier()
{
	for (int i = 0;i < 5;i++)//障碍物的横坐标也必须是偶数
	{
		barrier[i].x = 10 + 2 * i;
		barrier[i].y = LONG__MAX / 4;
	}
	for (int i = 5;i < 10;i++)//障碍物的横坐标也必须是偶数
	{
		barrier[i].x = WIDTH_MAX/4+1;
		barrier[i].y = 20+(i-5);
	}
	for (int i = 10;i < 15;i++)//障碍物的横坐标也必须是偶数
	{
		barrier[i].x = 40+2*(i-10);
		barrier[i].y = 5+(i-10);
	}
	for (int i = 15;i < 20;i++)//障碍物的横坐标也必须是偶数
	{
		barrier[i].x = 40 + 2 * (i - 15);
		barrier[i].y =20;
	}
	for (int i = 20;i < 24;i++)//障碍物的横坐标也必须是偶数
	{
		barrier[i].x = 48;
		barrier[i].y = 20+(i-19);
	}

}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
