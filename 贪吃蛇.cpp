#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;

int scores, speed;
bool getit = false;
bool gameornot = false;
int max_scores;

enum direction {
	up, down, l, r
};

struct Food {
	int x, y;
} food;

struct Snake {
	int x, y;
	Snake *next;
};

Snake *head, *tail;

struct Snake_para {
	direction dir;
	int length;
} now;

void change_cursor(int x, int y) {//控制光标移动
	COORD pos;//COORD是一种结构，表示一个字符在控制台屏幕上的光标
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//将光标位置移动到(x,y),getstdhandle用于获取标准输出位置
}

void init_windows() {
	system("mode con cols=80 lines=31");//设置窗口大小
	for (int i = 1; i <= 40; i++) {
		printf("■");
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
	scanf("%c", &ch);
	if (ch == 'y' || ch == 'Y') gameornot = true;
	system("cls");
	init_windows();
	change_cursor(30, 31);
	printf("Total Scores : %d", scores * 10);
}

void extend(int x, int y) {
	Snake *tmp = (Snake*)malloc(sizeof(Snake));
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	tail->next = tmp;
	tail = tmp;
}

void init_food() {
	bool flag = false;
	getit = false;
	food.x = (rand() % 76) + 3;
	food.y = (rand() % 26) + 3;
	Snake *q = head;
	while (q != tail) {
		if (q->x == food.x && q->y == food.y) {
			flag = true;
			break;
		}
		q = q->next;
	}
	if (flag) init_food();
}

void init_snake() {
	head = tail = (Snake*)malloc(sizeof(Snake));
	head->next = NULL;
	now.dir = r;
	now.length = 4;
	for (int i = 0; i < now.length; i++)
		extend(35 + i, 15);
	init_food();
}

void deletehead() {
	Snake *p = head;
	p = p->next;
	head = p;
}


void game_end() {
	gameornot = false;
	system("cls");
	init_windows();
	change_cursor(32, 15);
	printf("Your scores : %d", scores * 10);
	scores = 0;
	change_cursor(30, 16);
	printf("CONTINUE GAME？(y/n)：");
	char ch[2];
	scanf("%s", ch);
	if (ch[0] == 'y' || ch[0] == 'Y') {
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
	while (q != tail) {
		change_cursor(q->x, q->y);
		printf(" ");
		q = q->next;
	}
	change_cursor(tail->x, tail->y);
	printf(" ");
	p = tail;
	switch (now.dir) {
	case up:
		extend(p->x, p->y - 1); break;
	case down:
		extend(p->x, p->y + 1); break;
	case l:
		extend(p->x - 1, p->y); break;
	case r:
		extend(p->x + 1, p->y); break;
	}
	if (tail->x == food.x && tail->y == food.y) {
		now.length++;
		scores++;
		getit = true;
		change_cursor(30, 31);
		printf("Total Scores : %d", scores * 10);
	}
	if (!getit) {
		deletehead();
	}
	p = tail;
	q = head;
	while (q != tail) {
		if (q->x == p->x && q->y == p->y) {
			game_end();
			break;
		}
		q = q->next;
	}
	if (tail->x > 78 || tail->y > 29 || tail->x <= 2 || tail->y <= 1) {
		game_end();
	}
}

void input() {
	char c;
	if (_kbhit()) {
		c = getch();
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

void print() {//打印食物和蛇
	change_cursor(food.x, food.y);
	printf("@");
	Snake *q;
	q = head;
	change_cursor(tail->x, tail->y);
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
	system("cls");
	init_windows();
	change_cursor(28, 14);
	printf("Your Highest Scores : %d", max_scores * 10);
	change_cursor(30, 16);
	printf("Thanks For Playing");
}

int main() {
	system("color 03");
	srand(time(NULL));
	init_windows();
	startmenu();
	init_snake();
	while (gameornot) {
		input();
		move();
		if (gameornot) {
			print();
			int speed = min(9, scores / 10);
			Sleep(100 - 10 * speed);
			max_scores = max(max_scores, scores);
		}
	}
	thanks();
	return 0;
}
