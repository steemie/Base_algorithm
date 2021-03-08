/*************************
修改记录:
20210308 增加基础模块  V1
20210308 增加多条路径和最短路径的输出  V2
*************************/

#include <iostream>
#include <string>

using namespace std;

/********宏定义区域开始****************************/
#define maxsize (10001)  //栈的最大容量
#define M       (8)      //行
#define N       (8)      //列
/********宏定义区域结束***************************/

struct MazeInfo
{
    int i; //当前方块的行号
    int j; //当前方块的列号
    int di; //下一个可走方位的方位号

}maze_info[maxsize],path[maxsize];  //定义栈 ,//V2版本添加所有的

int top = -1; //初始化栈顶指针
int count1 = 1; //计数器
int minlen = maxsize;

//增加两行两列的外墙
int Mg[M + 2][N + 2] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

//入口（x1,y1） 出口（x2,y2）
//求入口到出口的最短路径
//1、找出一条走到终点
//2、增加寻找最短的那条路径
void MgPath(int x1,int y1,int x2,int y2)
{                                               
    int i = 0, j = 0,di = 0;
    int find = 0;
    top++;//初始化方块进栈
    maze_info[top].i = x1;
    maze_info[top].j = y1;
    maze_info[top].di = -1;
    Mg[x1][y1] = -1;  //走过的路线做标记

    while (top > -1)   //栈不为空时，继续执行
    {
       
        i = maze_info[top].i;
        j = maze_info[top].j;
        di = maze_info[top].di;

        //先判断是否为终点
        if (i == x2 && j == y2)
        {
            //直接输出路径
            printf("迷宫路径如下：\n");
            printf("第%d条路径如下：\n", count1++);      //V2
            for (int k = 0; k <= top;k++)   //是否要输出top？
            {
                printf("\t(%d,%d)", maze_info[k].i, maze_info[k].j);
                if (k % 5 == 0)
                {
                    printf("\n");
                }    

            }
            printf("\n");

            //V2
            if (top + 1 < minlen)
            {
                for (int k1 = 0;k1 <= top;k1++)
                {
                    path[k1] = maze_info[k1];
                }

                minlen = top + 1;
            }

            Mg[maze_info[top].i][maze_info[top].j] = 0;
            top--; //开始下一次的
            i = maze_info[top].i;
            j = maze_info[top].j;
            di = maze_info[top].di;



            //return; //V2
        }

        //判断右侧和下侧的点
        find = 0;                       
        while (find == 0 && di < 4) //寻找下一个可以走的方块
        {
            di++;
            switch (di)
            {
                case 0:
                {
                    i = maze_info[top].i - 1;
                    j = maze_info[top].j;
                    break;
                }

                case 1:
                {
                    i = maze_info[top].i;
                    j = maze_info[top].j + 1;
                    break;
                }

                case 2:
                {
                    i = maze_info[top].i + 1;
                    j = maze_info[top].j;
                    break;
                }

                case 3:
                {
                    i = maze_info[top].i;
                    j = maze_info[top].j - 1;
                    break;
                }
            }

            // 改变后，再去判断是否为墙壁
            //两层含义；1、不能为墙壁 2、之前没有走过，走过的路记为-1
            if (Mg[i][j] == 0)
            {
                find = 1;       //找到通路就马上跳出
            }
        }

        if (find == 1)
        {
            //找到了下一个可走的方块
            maze_info[top].di = di;
            top++;
            maze_info[top].i = i;
            maze_info[top].j = j;
            maze_info[top].di = -1;
            Mg[i][j] = -1; //避免重复走到该块

        }
        else
        {
            //找不到，前路不同，返回上一层
            Mg[maze_info[top].i][maze_info[top].j] = 0;             //让该位置变为其他路径可走
            top--; //
        }





    }

    if (minlen == maxsize && maze_info[top].i == 0 && maze_info[top].j == 0)
    {
        printf("没有可走路径\n");
    }
    else
    {
        printf("最短路径：\n");
        for (int k2 = 0;k2 < minlen;k2++)
        {
            printf("\t(%d,%d)", path[k2].i, path[k2].j);
            if (k2 % 5 == 0)
            {
                printf("\n");
            }
        }
    }

    
}


//BFS
//maze   labyrinth
//1表示墙壁，0表示可以走的路 ，只能横着或者竖着走，求左上角到右下角的最短路径
//例如下面
int maze[5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};




int main()
{

    int x1, y1, x2, y2;
    //scanf:x1,y1,x2,y2
    x1 = 1;
    y1 = 1;
    x2 = 8;
    y2 = 8;
    MgPath(x1, y1, x2, y2);
    system("pause");
    return 0;

}
