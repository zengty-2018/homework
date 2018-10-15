# 使用construct2来设计一个游戏
使用construct2可以帮助一个连编程都不会的人做出一个游戏！下面我们来用construct2来做一个简单的射击游戏：键盘鼠标控制玩家射杀怪物。<br>
## 1.创建项目
首先我们进入construct2，点击左上角的file，如图所示<br>
![image](http://thyrsi.com/t6/387/1539563887x1822611359.png)<br>
之后我们选定第一个New empty project，点击open<br>
![image](http://thyrsi.com/t6/387/1539563935x1822611359.png)<br>
这样，一个新项目就创建好了。
## 2.添加背景
项目创建完成后，点击空白处，出现以下界面，点击Tile Background<br>
![image](http://thyrsi.com/t6/387/1539563968x1822611359.png)<br>
之后再次双击空白处，在弹出的界面中选中我们的背景，再关闭窗口，就可以看到背景被添加到白板上了。<br>
这时，我们拖动背景的边框使其铺满这个白色的界面，如图<br>
![image](http://thyrsi.com/t6/387/1539564003x1822611359.png)<br>
游戏的背景就做好了。<br>
## 3.游戏角色
我们想要游戏的角色在背景上面活动，所以我们先要再添加一个图层，方法如图所示<br>
![image](http://thyrsi.com/t6/387/1539564061x-1376440138.png)<br>
创建完成后，按照箭头数字的顺序点击（其中第三步是锁定背景层、第四步是更改各层的名称）<br>
接下来我们通过双击背景弹出的窗口选中sprite来创建游戏角色，<br>
![image](http://thyrsi.com/t6/387/1539564090x-1376440138.png)<br>
再点击一次背景，在弹出的窗口选中player、monster、bullet、explode创建。（一开始我们并不需要explode和bullet，我们可以将其放在背景外）<br>
为了方便，我们可以将右键单击右下栏中的sprite，选择rename将其名称改为相对应的各个名称。如图：<br>
![image](http://thyrsi.com/t6/387/1539564124x-1376440138.png)<br>

接下来我们为角色添加一些行为。<br>
选中player，在左侧栏中找到behavior，点进去，添加8Direction、scrollto、boundtolayer。<br>
![image](http://thyrsi.com/t6/387/1539564156x-1376440138.png)<br>
为其他角色添加相对应的行为：<br>
bullet：Bullet movement和Destroy outside layout；<br>
monster:Bullet movement;<br>
explode:Fade;<br>
现在试着运行游戏，你会发现怪物的速度太快了，所以你要在左栏中将monster的speed栏改成80，bullet的speed栏改成600，同时将explode的fade改成0.5。<br>
我们不能只有一个怪物，所以接下来我们按住control拖动monster，复制出多个怪物。<br>
![image](http://thyrsi.com/t6/387/1539564233x-1404775605.png)
## 4.事件
基本将游戏角色搞定，接下来我们要定义一些事件来使游戏正常运行。切换到上面的event sheet。<br>
![image](http://thyrsi.com/t6/387/1539564276x-1404775605.png)<br>
首先我们要让玩家一直看着鼠标，完成之后会是这样的(提示：这步之前要在第一Layout1页面加入Mouse）：<br>
![image](http://thyrsi.com/t6/387/1539564312x-1404775605.png)<br>
接下来是使玩家点击鼠标开枪时射出子弹，设置好之后如下图：<br>
![image](http://thyrsi.com/t6/387/1539564345x-1404775605.png)<br>
这个时候运行游戏发现子弹使从角色的中心射出，而我们希望它从枪口射出。所以我们返回Layout1的object编辑页面，找到set origin and image point将点移到枪口即可<br>
![image](http://thyrsi.com/t6/387/1539564375x-1404775605.png)<br>
然后我们想让子弹杀死怪物，于是我们可以继续利用事件系统完成它，如下图：<br>
![image](http://thyrsi.com/t6/387/1539564428x-1404775605.png)
新的问题又出现了，我们发现怪物爆炸的时候会出现一个黑色的边框<br>
![image](http://thyrsi.com/t6/387/1539564443x-1404775605.png)<br>
我们只需要回到Layout1单击explode然后在左侧找到Blend mode将其属性改为additive，然后再运行游戏，看看发生了什么？<br>
![image](http://thyrsi.com/t6/387/1539564468x-1404775605.png)<br>

接下来我们要增加游戏的可玩性，也就是增加怪物的“智商”。<br>
![image](http://thyrsi.com/t6/387/1539564512x-1404775605.png)<br>
这样使怪物一直在布局中行走，而且如果玩家不动，怪物就会出现在玩家的面前！<br>
是不是觉得难度还不够呢？现在我们来增加怪物的血量，即让怪物被攻击5次才死亡。这里就要用到实例变量。<br>
![image](http://thyrsi.com/t6/387/1539564646x-1404755462.png)<br>
设置完实例变量后我们运行游戏发现怪物还是被攻击一次就死亡了。原因使我们没有改事件表。接下来我们回到Event sheet1，找到monster右键点击，选replace action，并把其更改为如图所示的值。<br>
![image](http://thyrsi.com/t6/387/1539564569x-1404775605.png)<br>
![image](http://thyrsi.com/t6/387/1539564675x-1404755462.png)<br>
但是这样怪物的health会无限减少到-1、-5……并不会死亡，所以我们要设置一个当health=0时死亡的事件来保证怪物血量小于零时死亡。<br>
![image](http://thyrsi.com/t6/387/1539564928x-1404755516.png)<br>
玩游戏肯定要计分，所以我们还要设置一个记分板。这时我们就要用到全局变量。<br>
![image](http://thyrsi.com/t6/387/1539564961x-1404755516.png)<br>
![image](http://thyrsi.com/t6/387/1539564979x-1404755516.png)<br>
![image](http://thyrsi.com/t6/387/1539564993x-1404755516.png)<br>
积分当然也要显示给玩家看，所以我们回到Layout1,双击空白处新建一个text，然后回到event sheet，在Every tick事件中添加操作Text。<br>
我们已经基本完成了！接下来我们做一些最后的润色。我们让系统每3秒创造一些新的怪物，添加下列新事件：<br>
![image](http://thyrsi.com/t6/387/1539565015x-1404755516.png)<br>
还要让怪物可以杀死玩家，添加以下事件：<br>
![image](http://thyrsi.com/t6/387/1539565030x-1404755516.png)<br>

这样，一个简单的游戏基本就完成了。当然我们也可以通过加入背景音乐等使其更加有意思。这就看接下来的教程了。<br>
![image](http://thyrsi.com/t6/387/1539565059x-1404755516.png)