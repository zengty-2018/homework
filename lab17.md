# 贪吃蛇设计及算法介绍
贪吃蛇是许多人小时候很喜欢玩的一个简单的游戏，现在我来介绍一下用C语言字符简单实现贪吃蛇的功能的字符游戏的设计思路和算法。  

游戏是根据“自顶向下逐步求精”的思路设计的。  

### 第一层
首先我们将问题分解，贪吃蛇的游戏无非就是三步————游戏前（before_game），游戏中（play_game），游戏结束（game_over）。我们只需要将这三个函数具体实现就可以了。  

### 第二层
这里我们将三个步骤的行为细化：  
before_game：  
```
starting_interface();   //开始界面的打印
map_making();   //地图的初始化
snake_making();  //蛇的初始化
```

play_game：  
```
output();  //打印初始化的地图
	
while(1){
	food();  //生成食物
	getDirection();  //从键盘输入得到方向
	snakeMove();    //根据方向确定蛇的移动
	ifeat();  //判断是否吃到食物
	isGameOver();   //判断游戏是否结束
	
	if(游戏结束)    //假如游戏结束
		break;     //就退出循环
		
	output();   //打印蛇移动后的地图
}
```

game_over：  
```
printf_end   //打印结束界面
```


###  第三层
在第三层要把各个函数实现，因此算法用伪代码表示。  

starting_interface()：  
直接打印开始界面即可 

map_making():  
```
FROM 0 TO WALL_LEN:
    地图上的点变为墙；
```

void snake_making():  
初始化蛇身和蛇头的位置就可以了。 

void output()：  
```
FOR EVERY ROW OF MAP  THEN  
    FORM 0 TO MAX LEN
        PRINTF ROW_OF_MAP
END FOR
```

void getDirection():  
```
DIRECTION = 输入  
```

void snakeMove():  
```
CASE DIRECTION DO
‘A':左前进一步，break；
‘D':右前进一步，break；
‘W’:上前进一步，break;    
‘S’:下前进一步，break;
END CASE
```

void isGameOver():  
```
IF 头碰到身子 OR 头碰到墙 THEN
    GAME OVER;
END IF
```

void food():  
随机生成食物坐标即可  

void ifeat()：  
```
IF 头的坐标 = 食物坐标 THEN
    SNAKE_LEN++;
    尾部增长；
END IF
```

---------
最后效果如下：  
![image](http://thyrsi.com/t6/631/1544634096x2890202498.jpg)  
![image](http://thyrsi.com/t6/631/1544634120x2890202761.jpg)  
![image](http://thyrsi.com/t6/631/1544634140x2890202761.jpg)  