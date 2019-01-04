#include<bits/stdc++.h>
#include<Windows.h>//windows API ���ƹ�� dos����
#include<conio.h>//����̨��������⣬����_kbhit(), getch()��
using namespace std;

int scores, speed;//�������ٶ�
bool getit = false;//�Ƿ�Ե�ʳ��
bool gameornot = false;//�Ƿ������Ϸ
int max_scores;//��߷�

struct Food {//ʳ��ṹ
	int x, y;
} food;

struct Snake {//�ߵĽṹ������ģ����У�ʹ���и������
	int x, y;
	Snake *next;
};

Snake *head, *tail;//head����β��tail����ͷ����Ϊ��β���в����������ͷ����ɾ������

enum direction {//ö�ٱ�����ö�ٷ���
	up, down, l, r
};

struct Snake_para {//��ǰ��ͷ״̬
	direction dir;
	int length;
} now;

void change_cursor(int x, int y);//���ƹ���ƶ�

void init_windows();//��ʼ����Ϸ���棬��ӡΧǽ�����ƴ��ڴ�СΪ�̶�ֵ

void startmenu();//��Ϸ�Ļ�ӭ���棬��Ϸ������ܣ�ѯ���Ƿ�ʼ

void extend(int x, int y);//����һ������

void init_food();//��ʼ��ʳ��λ��

void init_snake();//��ʼ����

void deletehead();//ɾ����β

void game_end();//������Ϸ�������������������ַ���

void move();//�����ƶ����ж���λ���Ƿ�Ϸ�

void input();//��ȡ���̷�������

void print();//��ӡʳ�����

void thanks();//�û�ѡ��ֹͣ��Ϸ�����������Ϸ����߷֣���л�û����鱾��Ϸ

int main() {
	system("color 03");//�ı����̨��ɫΪ��ɫ������Ϊ��ɫ
	srand(time(NULL));//��ʼ����������ӣ���������ʳ��
	init_windows();
	startmenu();
	init_snake();
	while (gameornot) {//���ѡ�����������Ϸ����ͣѭ����gameornotΪ��־����
		input();
		move();
		if (gameornot) {
			print();
			int speed = min(9, scores / 10);//��ǰ�ٶȣ�ÿ10���ٶ����һ��
			Sleep(100 - 10 * speed);//ͨ��sleep�����ı�̰�����ƶ��ٶ�
			max_scores = max(max_scores, scores);//��¼��߷�
		}
	}
	thanks();
	return 0;
}


void change_cursor(int x, int y) {//���ƹ���ƶ�
	COORD pos;//COORD��һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵĹ��
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//�����λ���ƶ���(x,y),getstdhandle���ڻ�ȡ��׼���λ��
}

void init_windows() {
	system("mode con cols=80 lines=31");//dos����ı䴰�ڴ�СΪ31(��)*80(��),��Ϊ31��Ϊ���һ��������ʾ����
	for (int i = 1; i <= 40; i++) {
		printf("��");//ע������ַ�ռ2λ��ѭ������Ҫ��֮�ı�
	}
	for (int i = 1; i <= 28; i++) {
		change_cursor(1, i + 1);
		printf("��");
		change_cursor(79, i + 1);
		printf("��");
	}
	change_cursor(1, 30);
	for (int i = 1; i <= 40; i++) {
		printf("��");
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
	scanf("%c", &ch);//�����Ƿ�ʼ
	if (ch == 'y' || ch == 'Y') gameornot = true;//��־������Ϊtrue��ѭ�����Խ���
	system("cls");//������������Ϸ
	init_windows();
	change_cursor(30, 31);
	printf("Total Scores : %d", scores * 10);
}

void extend(int x, int y) {
	Snake *tmp = (Snake*)malloc(sizeof(Snake));//����������ȳ�ʼ��һ���ṹ����������β
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	tail->next = tmp;
	tail = tmp;//���ӵ���β
}

void init_food() {
	bool flag = false;//ʳ���Ƿ������������
	getit = false;//��ʼ��ʳ��ʱҪ���ʳ��Ϊδ�Ե�
	food.x = (rand() % 76) + 3;//ע��ǽ���ַ�ռ��λ��ʳ��randʱҪע�⣬���������ǽ�ڲ���bug
	food.y = (rand() % 26) + 3;
	Snake *q = head;
	while (q != tail) {//��������
		if (q->x == food.x && q->y == food.y) {
			flag = true;
			break;
		}
		q = q->next;
	}
	if (flag) init_food();//��������������ϣ��ݹ���ã���������ʳ��
}

void init_snake() {
	head = tail = (Snake*)malloc(sizeof(Snake));//��ʼ����ͷ��β
	head->next = NULL;
	now.dir = r;
	now.length = 4;
	for (int i = 0; i < now.length; i++)
		extend(35 + i, 15);
	init_food();
}

void deletehead() {
	Snake *p = head;//����ͷ��Ӧ��β
	p = p->next;
	head = p;
}

void game_end() {
	gameornot = false;//�ȱ���Ƿ������ϷΪfalse
	system("cls");//�����Ļ����ӡ��ʾ��Ϣ
	init_windows();
	change_cursor(32, 15);
	printf("Your scores : %d", scores * 10);
	scores = 0;
	change_cursor(30, 16);
	printf("CONTINUE GAME��(y/n)��");
	char ch[2];
	scanf("%s", ch);
	if (ch[0] == 'y' || ch[0] == 'Y') {//�������������Ϸ�����³�ʼ��
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
	while (q != tail) {//��ɾ����һ���ƶ�����
		change_cursor(q->x, q->y);
		printf(" ");
		q = q->next;
	}
	change_cursor(tail->x, tail->y);//ɾ����β
	printf(" ");
	p = tail;
	switch (now.dir) {//�ж�Ҫ�ƶ��ķ���
	case up:
		extend(p->x, p->y - 1); break;
	case down:
		extend(p->x, p->y + 1); break;
	case l:
		extend(p->x - 1, p->y); break;
	case r:
		extend(p->x + 1, p->y); break;
	}
	if (tail->x == food.x && tail->y == food.y) {//����Ե���ʳ��
		now.length++;//����������+1
		scores++;//����+1
		getit = true;//��ǳԵ���ʳ��
		change_cursor(30, 31);
		printf("Total Scores : %d", scores * 10);//������ʾ��������ʾ����Ϊ�÷�*10
	}

	if (!getit) {//���û�гԵ���ɾ����β
		deletehead();
	}
	p = tail;
	q = head;
	while (q != tail) {
		if (q->x == p->x && q->y == p->y) {
			game_end();//����Լ��������Լ�����Ϸ����
			break;
		}
		q = q->next;
	}
	if (tail->x > 78 || tail->y > 29 || tail->x <= 2 || tail->y <= 1) {//��ͷ����ǽ����Ϸ����
		game_end();
	}
}

void input() {
	char c;
	if (_kbhit()) {//�жϼ����Ƿ���Ӧ
		c = getch();//���谭���뺯��
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
	change_cursor(food.x, food.y);//��ӡʳ��
	printf("@");
	Snake *q;
	q = head;
	change_cursor(tail->x, tail->y);//��ӡ��
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
	system("cls");//�����Ļ����ӡ��л��Ϣ
	init_windows();
	change_cursor(28, 14);
	printf("Your Highest Scores : %d", max_scores * 10);//�����Ϸ��߷�
	change_cursor(30, 16);
	printf("Thanks For Playing");//��л
	change_cursor(32, 17);
}