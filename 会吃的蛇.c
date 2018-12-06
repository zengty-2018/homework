#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> 

#define   WALL_LENTH   12
#define   WALL         '*'
#define   SNAKE_BODY   'X'
#define   SNAKE_HEAD   'H'
#define   AREA         ' '
#define   FOOD         '$'
#define   random(x,y)    (rand()%(y-x+1)+x)

char map[12][12];
int flag = 1;
int flag1 = 0;
int flag2 = 1;
int snake_len = 5;
int position[100][2];
int head[2];
int direction;
int foods[2];

//����Ҫʹ�õĺ��� 
void before_game();
void play_game();
void game_over();
void starting_interface();
void map_making();
void snake_making();
void output();
void getDirection();
void snakeMove();
void isGameOver();
void food();
void ifeat();

//������ 
int main(){
	before_game();
	play_game();
	game_over();
	
	return 0;
}

//��Ϸ��ʼǰ��׼�� 
void before_game(){
	starting_interface();
	map_making();
	snake_making();
}

//��Ϸ�еĲ��� 
void play_game(){
	output();
	
	while(1){
		food();
		getDirection();
		snakeMove();
		ifeat();
		isGameOver();
		
		if(flag == 0)
			break; 
		
		output();
	}
}

//��Ϸ����֮��Ĳ��� 
void game_over(){
	printf("\n\n\n\n");
	printf("                                           ��Ϸ����\n------------------------------------------------------------------------------------------------------------\n");
}

//��ʼ���� 
void starting_interface(){
	char c;
	printf("                                            ̰����            \n\n\n\n\n\n");
	printf("                                        ʹ��WASD���Ʒ���       \n"); 
	printf("\n");
	printf("                                         ���س�����ʼ\n------------------------------------------------------------------------------------------------------------\n");
	if((c = getchar()) != EOF)
		system("CLS"); 
}

//��ͼ��ʼ�� 
void map_making(){
	int i; 
	for(i = 0; i < WALL_LENTH; i++){
		map[0][i] = WALL;
		map[WALL_LENTH-1][i] = WALL;
		map[i][0] = WALL;
		map[i][WALL_LENTH-1] = WALL;
	}
}

//�߳�ʼ�� 
void snake_making(){
	int i,x=0;
	for(i = 1; i < snake_len; i++){
		map[1][i] = SNAKE_BODY;
		position[x][0] = 1;
		position[x][1] = i;
		x++;
	}
	map[1][i] = SNAKE_HEAD;
	head[0] = 1;
	head[1] = i;
}

//�����ͼ 
void output(){
	int i,j;
		for(i = 0; i < WALL_LENTH; i++){
			for(j = 0; j < WALL_LENTH; j++){
				printf("%c",map[i][j]);
			}
		printf("\n");
	}
}

//�õ�ǰ���ķ��� 
void getDirection(){
	direction = getch();
}

//�ߵ��ƶ� 
void snakeMove(){
	int i;
	
	switch (direction) {
		case 97 : {map[position[0][0]][position[0][1]] = AREA;   //��β�����һ��λ�øĳɿո� 
					for(i = 0; i < snake_len-2; i++){
						position[i][0] = position[i+1][0];
						position[i][1] = position[i+1][1];      //ÿ��β����ǰ�ƶ�һ�� 
					}
					position[i][0] = head[0];
					position[i][1] = head[1];
					head[1]--;                                  //ͷ���ƶ� 
				};
				break;
		case 119  : {map[position[0][0]][position[0][1]] = AREA;
					for(i = 0; i < snake_len-2; i++){
						position[i][0] = position[i+1][0];
						position[i][1] = position[i+1][1];
					}
					position[i][0] = head[0];
					position[i][1] = head[1];
					head[0]--;
				};
				break;
		case 100 : {map[position[0][0]][position[0][1]] = AREA;
					for(i = 0; i < snake_len-2; i++){
						position[i][0] = position[i+1][0];
						position[i][1] = position[i+1][1];
					}
					position[i][0] = head[0];
					position[i][1] = head[1];
					head[1]++;
				};
				break;
		case 115 : {map[position[0][0]][position[0][1]] = AREA;
					for(i = 0; i < snake_len-2; i++){
						position[i][0] = position[i+1][0];
						position[i][1] = position[i+1][1];
					}
					position[i][0] = head[0];
					position[i][1] = head[1];
					head[0]++;
				};
				break;
	}
	
	for(i = 0; i < snake_len-1; i++){
		map[position[i][0]][position[i][1]] = SNAKE_BODY;        //���µ��������Ӧλ�õ��ַ��ĳ�SNAKE_BODY 
	}
	map[head[0]][head[1]] = SNAKE_HEAD;                          //���µ���ͷ��Ӧλ�õ��ַ��ĳ�SNAKE_HEAD 
}

//�ж��Ƿ������Ϸ 
void isGameOver(){
	int i;
	
	if(head[0] == 0 || head[0] == 11)    //�������½���� 
		flag = 0;
	if(head[1] == 0 || head[1] == 11)    //�������ҽ���� 
		flag = 0;
	
	for(i = 0; i < snake_len-1; i++){
		if(position[i][0] == head[0] && position[i][1] == head[1])    //ͷ����������� 
			flag = 0;
	}
}

//�������ʳ������ 
void food(){
	int i;
	if(flag1 == 0){
		srand((int)time(0));
		while(1){
			flag2 = 1;
			foods[0] = random(1,10);
			foods[1] = random(1,10);
			for(i = 0; i < snake_len-1; i++){
				if(position[i][0] == foods[0] && position[i][1] == foods[1]){  //�������ߵ������� 
					flag2 = 0;
					break;
				}
			}
			if(head[0] == foods[0] && head[1] == foods[1])   //�������ߵ�ͷ�� 
				flag2 = 0;
			if(flag2 == 1)
				break;
		}
		map[foods[0]][foods[1]] = FOOD;
		flag1 = 1;
	}
}

//�ж��Ƿ�Ե�ʳ�� 
void ifeat(){
	int i;
	if(foods[0] == head[0] && foods[1] == head[1]){
		flag1 = 0;
		snake_len++;
		position[snake_len-2][0] = head[0];
		position[snake_len-2][1] = head[1];
		
		switch (direction){
			case  97  : head[1]--; break;
			case 119  : head[0]--; break;
			case 100  : head[1]++; break;
			case 115  : head[0]++; break;
		}
		for(i = 0; i < snake_len-1; i++){
			map[position[i][0]][position[i][1]] = SNAKE_BODY;        //���µ��������Ӧλ�õ��ַ��ĳ�SNAKE_BODY 
		}
		map[head[0]][head[1]] = SNAKE_HEAD;                          //���µ���ͷ��Ӧλ�õ��ַ��ĳ�SNAKE_HEAD 
	} 
}
