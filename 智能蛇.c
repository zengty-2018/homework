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

//各种要使用的函数 
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

//主函数 
int main(){
	before_game();
	play_game();
	game_over();
	
	return 0;
}

//游戏开始前的准备 
void before_game(){
	starting_interface();
	map_making();
	snake_making();
}

//游戏中的操作 
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

//游戏结束之后的操作 
void game_over(){
	printf("\n\n\n\n");
	printf("                                           游戏结束\n------------------------------------------------------------------------------------------------------------\n");
}

//开始界面 
void starting_interface(){
	char c;
	printf("                                            贪吃蛇            \n\n\n\n\n\n");
	printf("                                        使用WASD控制方向       \n"); 
	printf("\n");
	printf("                                         按回车键开始\n------------------------------------------------------------------------------------------------------------\n");
	if((c = getchar()) != EOF)
		system("CLS"); 
}

//地图初始化 
void map_making(){
	int i; 
	for(i = 0; i < WALL_LENTH; i++){
		map[0][i] = WALL;
		map[WALL_LENTH-1][i] = WALL;
		map[i][0] = WALL;
		map[i][WALL_LENTH-1] = WALL;
	}
}

//蛇初始化 
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

//输出地图 
void output(){
	int i,j;
		for(i = 0; i < WALL_LENTH; i++){
			for(j = 0; j < WALL_LENTH; j++){
				printf("%c",map[i][j]);
			}
		printf("\n");
	}
}

//得到前进的方向 
void getDirection(){
	//direction = getch();
	char movable[5] = {'w','s','a','d','\0'};
	int distance[4];
	int a, b;
	
	a = foods[0] - head[0];
	b = foods[1] - head[1];
	
	if(a > 0){
		if(b > 0){
			distance[0] = 999;
			distance[1] = a+b-1;
			distance[2] = 999;
			distance[3] = a+b-1;
		}
		else if(b == 0){
			distance[0] = 999;
			distance[1] = a+b-1;
			distance[2] = 999;
			distance[3] = 999;
		}
		else if(b < 0){
			distance[0] = 999;
			distance[1] = a-b-1;
			distance[2] = a-b-1;
			distance[3] = 999;
		}
	}
	else if(a == 0){
		if(b > 0){
			distance[0] = 999;
			distance[1] = 999;
			distance[2] = 999;
			distance[3] = a+b-1;
		}
		else if(b < 0){
			distance[0] = 999;
			distance[1] = 999;
			distance[2] = a-b-1;
			distance[3] = 999;
		}
	}
	else if(a < 0){
		if(b > 0){
			distance[0] = b-a-1;
			distance[1] = 999;
			distance[2] = 999;
			distance[3] = b-a-1;
		}
		else if(b == 0){
			distance[0] = 1-a;
			distance[1] = 999;
			distance[2] = 999;
			distance[3] = 999;
		}
		else if(b < 0){
			distance[0] = -a-b-1;
			distance[1] = 999;
			distance[2] = -a-b-1;
			distance[3] = 999;
		}
	}
	int min = 0;
	int i; 
	for(i = 1; i < 4; i++)
		if(distance[i] < distance[min])
			min = i;
	if(getch() != EOF)
		direction = movable[min];
			
}

//蛇的移动 
void snakeMove(){
	int i;
	
	switch (direction) {
		case 97 : {map[position[0][0]][position[0][1]] = AREA;   //把尾巴最后一个位置改成空格 
					for(i = 0; i < snake_len-2; i++){
						position[i][0] = position[i+1][0];
						position[i][1] = position[i+1][1];      //每个尾巴向前移动一个 
					}
					position[i][0] = head[0];
					position[i][1] = head[1];
					head[1]--;                                  //头的移动 
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
		map[position[i][0]][position[i][1]] = SNAKE_BODY;        //把新的蛇身体对应位置的字符改成SNAKE_BODY 
	}
	map[head[0]][head[1]] = SNAKE_HEAD;                          //把新的蛇头对应位置的字符改成SNAKE_HEAD 
}

//判断是否结束游戏 
void isGameOver(){
	int i;
	
	if(head[0] == 0 || head[0] == 11)    //碰到上下界结束 
		flag = 0;
	if(head[1] == 0 || head[1] == 11)    //碰到左右界结束 
		flag = 0;
	
	for(i = 0; i < snake_len-1; i++){
		if(position[i][0] == head[0] && position[i][1] == head[1])    //头碰到身体结束 
			flag = 0;
	}
}

//随机生成食物坐标 
void food(){
	int i;
	if(flag1 == 0){
		srand((int)time(0));
		while(1){
			flag2 = 1;
			foods[0] = random(1,10);
			foods[1] = random(1,10);
			for(i = 0; i < snake_len-1; i++){
				if(position[i][0] == foods[0] && position[i][1] == foods[1]){  //不能在蛇的身体里 
					flag2 = 0;
					break;
				}
			}
			if(head[0] == foods[0] && head[1] == foods[1])   //不能在蛇的头上 
				flag2 = 0;
			if(flag2 == 1)
				break;
		}
		map[foods[0]][foods[1]] = FOOD;
		flag1 = 1;
	}
}

//判断是否吃到食物 
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
			map[position[i][0]][position[i][1]] = SNAKE_BODY;        //把新的蛇身体对应位置的字符改成SNAKE_BODY 
		}
		map[head[0]][head[1]] = SNAKE_HEAD;                          //把新的蛇头对应位置的字符改成SNAKE_HEAD 
	} 
}
