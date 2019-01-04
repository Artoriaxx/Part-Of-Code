#include<bits/stdc++.h>
#include<Windows.h>//windows API 控制光标 dos操作
#include<conio.h>//控制台输入输出库，含有_kbhit(), getch()等
using namespace std;

int scores, speed;//分数，速度
bool getit = false;//是否吃到食物
bool gameornot = false;//是否继续游戏
int max_scores;//最高分

struct Food {//食物结构
	int x, y;
} food;

struct Snake {//蛇的结构，链表模拟队列，使队列更加灵活
	int x, y;
	Snake *next;
};

Snake *head, *tail;//head是蛇尾，tail是蛇头，因为队尾进行插入操作，队头进行删除操作

enum direction {//枚举变量，枚举方向
	up, down, l, r
};

struct Snake_para {//当前蛇头状态
	direction dir;
	int length;
} now;

void change_cursor(int x, int y);//控制光标移动

void init_windows();//初始化游戏界面，打印围墙，控制窗口大小为固定值

void startmenu();//游戏的欢迎界面，游戏规则介绍，询问是否开始

void extend(int x, int y);//增加一节蛇身

void init_food();//初始化食物位置

void init_snake();//初始化蛇

void deletehead();//删除蛇尾

void game_end();//本局游戏结束处理函数，给出本局分数

void move();//蛇身移动，判断蛇位置是否合法

void input();//获取键盘方向输入

void print();//打印食物和蛇

void thanks();//用户选择停止游戏，给出多局游戏的最高分，感谢用户体验本游戏

int main() {
	system("color 03");//改变控制台颜色为蓝色，背景为黑色
	srand(time(NULL));//初始化随机数种子，用于生成食物
	init_windows();
	startmenu();
	init_snake();
	while (gameornot) {//如果选择继续进行游戏，则不停循环，gameornot为标志变量
		input();
		move();
		if (gameornot) {
			print();
			int speed = min(9, scores / 10);//当前速度，每10分速度提高一档
			Sleep(100 - 10 * speed);//通过sleep函数改变贪吃蛇移动速度
			max_scores = max(max_scores, scores);//记录最高分
		}
	}
	thanks();
	return 0;
}


void change_cursor(int x, int y) {//控制光标移动
	COORD pos;//COORD是一种结构，表示一个字符在控制台屏幕上的光标
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//将光标位置移动到(x,y),getstdhandle用于获取标准输出位置
}

void init_windows() {
	system("mode con cols=80 lines=31");//dos命令，改变窗口大小为31(行)*80(列),行为31因为最后一行用于显示分数
	for (int i = 1; i <= 40; i++) {
		printf("■");//注意这个字符占2位，循环条件要随之改变
	}
	for (int i = 1; i <= 28; i++) {
		change_cursor(1, i + 1);
		printf("■");
		change_cursor(79, i + 1);
		printf("■");
	}
	change_cursor(1, 30);
	for (int i = 1; i <= 40; i++) {
		printf("■");
	}
}

void startmenu() {
	change_cursor(33, 11);
	printf("Retro Snaker");
	change_cursor(40, 12);
	printf("By Artoriax");
	change_cursor(21, 14);
	printf("Please don't change the size of the window");
	change_cursor(26, 15);
	printf("Use WASD To Control Direction");
	change_cursor(18, 16);
	printf("Please play games under the English input method.");
	change_cursor(32, 18);
	printf("START? (y/n): ");
	char ch;
	scanf("%c", &ch);//读入是否开始
	if (ch == 'y' || ch == 'Y') gameornot = true;//标志变量设为true，循环可以进行
	system("cls");//清屏，进入游戏
	init_windows();
	change_cursor(30, 31);
	printf("Total Scores : %d", scores * 10);
}

void extend(int x, int y) {
	Snake *tmp = (Snake*)malloc(sizeof(Snake));//链表操作，先初始化一个结构，连到链表尾
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	tail->next = tmp;
	tail = tmp;//连接到表尾
}

void init_food() {
	bool flag = false;//食物是否出现在蛇身上
	getit = false;//初始化食物时要标记食物为未吃到
	food.x = (rand() % 76) + 3;//注意墙的字符占两位，食物rand时要注意，以免出现在墙内产生bug
	food.y = (rand() % 26) + 3;
	Snake *q = head;
	while (q != tail) {//遍历蛇身
		if (q->x == food.x && q->y == food.y) {
			flag = true;
			break;
		}
		q = q->next;
	}
	if (flag) init_food();//如果出现在蛇身上，递归调用，重新生成食物
}

void init_snake() {
	head = tail = (Snake*)malloc(sizeof(Snake));//初始化蛇头蛇尾
	head->next = NULL;
	now.dir = r;
	now.length = 4;
	for (int i = 0; i < now.length; i++)
		extend(35 + i, 15);
	init_food();
}

void deletehead() {
	Snake *p = head;//链表头对应蛇尾
	p = p->next;
	head = p;
}

void game_end() {
	gameornot = false;//先标记是否进行游戏为false
	system("cls");//清空屏幕，打印提示信息
	init_windows();
	change_cursor(32, 15);
	printf("Your scores : %d", scores * 10);
	scores = 0;
	change_cursor(30, 16);
	printf("CONTINUE GAME？(y/n)：");
	char ch[2];
	scanf("%s", ch);
	if (ch[0] == 'y' || ch[0] == 'Y') {//如果继续进行游戏，重新初始化
		gameornot = true;
		system("cls");
		init_windows();
		init_snake();
		change_cursor(30, 31);
		printf("Total Scores : %d", scores * 10);
	}
}

void move() {
	Snake *p, *q;
	p = tail, q = head;
	while (q != tail) {//先删除上一次移动的蛇
		change_cursor(q->x, q->y);
		printf(" ");
		q = q->next;
	}
	change_cursor(tail->x, tail->y);//删除蛇尾
	printf(" ");
	p = tail;
	switch (now.dir) {//判断要移动的方向
	case up:
		extend(p->x, p->y - 1); break;
	case down:
		extend(p->x, p->y + 1); break;
	case l:
		extend(p->x - 1, p->y); break;
	case r:
		extend(p->x + 1, p->y); break;
	}
	if (tail->x == food.x && tail->y == food.y) {//如果吃到了食物
		now.length++;//现在蛇身长度+1
		scores++;//分数+1
		getit = true;//标记吃到了食物
		change_cursor(30, 31);
		printf("Total Scores : %d", scores * 10);//更新显示分数，显示分数为得分*10
	}

	if (!getit) {//如果没有吃到，删除蛇尾
		deletehead();
	}
	p = tail;
	q = head;
	while (q != tail) {
		if (q->x == p->x && q->y == p->y) {
			game_end();//如果自己碰到了自己，游戏结束
			break;
		}
		q = q->next;
	}
	if (tail->x > 78 || tail->y > 29 || tail->x <= 2 || tail->y <= 1) {//蛇头碰到墙，游戏结束
		game_end();
	}
}

void input() {
	char c;
	if (_kbhit()) {//判断键盘是否响应
		c = getch();//无阻碍输入函数
		switch (c) {
		case 'w':
			if (now.dir == down) break;
			else now.dir = up; break;
		case 's':
			if (now.dir == up) break;
			else now.dir = down; break;
		case 'a':
			if (now.dir == r) break;
			else now.dir = l; break;
		case 'd':
			if (now.dir == l) break;
			else now.dir = r; break;
		}
	}
}

void print() {
	change_cursor(food.x, food.y);//打印食物
	printf("@");
	Snake *q;
	q = head;
	change_cursor(tail->x, tail->y);//打印蛇
	printf("*");
	while (q != tail) {
		change_cursor(q->x, q->y);
		printf("*");
		q = q->next;
	}
	if (getit == 1)
		init_food();
}

void thanks() {
	system("cls");//清空屏幕，打印致谢信息
	init_windows();
	change_cursor(28, 14);
	printf("Your Highest Scores : %d", max_scores * 10);//多局游戏最高分
	change_cursor(30, 16);
	printf("Thanks For Playing");//致谢
	change_cursor(32, 17);
}