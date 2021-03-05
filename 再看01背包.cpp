
#include <time.h>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>
using namespace std;

int table_result[20][20];
//二维的写法
int Knapsack1(int v[], int w[], int c, int n) 
{//value weight capacity num  

    for(int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= c;j++)
        {
            if (j < w[i])
            {
                //装不下就等于上一次的
                table_result[i][j] = table[i - 1][j];
            }
            else
            {
                //为什么要比较呢？因为呀：加了本次的质量后，上次的质量肯定只能算余下的那部分，那部分的价值加上此刻的，不一定就比我[i-1][j]大
                table_result[i][j] = max(table_result[i-1][j],table_result[i - 1][j - w[i]] + v[i]); 
            }
        }
    }

    return table_result[n][c];

}

int table_result2[20];   //默认初始化为0了的
//换种一维的写法
int Knapsack2(int v[], int w[], int c, int n)
{//value weight capacity num  

    int a[5] = {2};
    printf("a:%d\n", a[0]);
    //int table_result2[20];
    //memset(table_result2, 0, sizeof(int) * 20);   //这样初始化只能是0或者-1，因为是按照字节的形式填充二进制的
    //for (int i1 = 0;i1 < 20;i1++)
    //{

      //  printf("table_result2:%d\n", table_result2[i1]);
    //}

    for (int i = 1;i <= n;i++)
    {
        //j >= w[i] 理解：如果容量比物体的重量小，那肯定是0，完全没必要再遍历
        //一维的话就逆序遍历，第一个判断语句中可以一直往前推的，但是那 table_result2[j - w[i]]这个值我并不知道!!! ：没关系，有默认值的，
        //i = 0时，走完内层的j循环，  table_result2一定是有值的
        for (int j = c;j >= w[i];j--)
        {
            printf("table_result2[j - w[i]]:%d,table_result2[j]:%d ---- j:%d,i:%d,w[i]:%d\n", table_result2[j - w[i]] + v[i], table_result2[j], j, i,w[i]);
            if (table_result2[j - w[i]] + v[i] > table_result2[j])
            {
                table_result2[j] = table_result2[j - w[i]] + v[i];
            }

        }
    }

    return table_result2[c];

}

//一维的打印结果
/*
table_result2[j - w[i]]:6, table_result2[j] : 0 ----j : 10, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 9, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 8, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 7, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 6, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 5, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 4, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 3, i : 1, w[i] : 2
table_result2[j - w[i]] : 6, table_result2[j] : 0 ----j : 2, i : 1, w[i] : 2
table_result2[j - w[i]] : 9, table_result2[j] : 6 ----j : 10, i : 2, w[i] : 2
table_result2[j - w[i]] : 9, table_result2[j] : 6 ----j : 9, i : 2, w[i] : 2
table_result2[j - w[i]] : 9, table_result2[j] : 6 ----j : 8, i : 2, w[i] : 2
table_result2[j - w[i]] : 9, table_result2[j] : 6 ----j : 7, i : 2, w[i] : 2
table_result2[j - w[i]] : 9, table_result2[j] : 6 ----j : 6, i : 2, w[i] : 2
table_result2[j - w[i]] : 9, table_result2[j] : 6 ----j : 5, i : 2, w[i] : 2
table_result2[j - w[i]] : 9, table_result2[j] : 6 ----j : 4, i : 2, w[i] : 2
table_result2[j - w[i]] : 3, table_result2[j] : 6 ----j : 3, i : 2, w[i] : 2
table_result2[j - w[i]] : 3, table_result2[j] : 6 ----j : 2, i : 2, w[i] : 2
table_result2[j - w[i]] : 14, table_result2[j] : 9 ----j : 10, i : 3, w[i] : 6
table_result2[j - w[i]] : 11, table_result2[j] : 9 ----j : 9, i : 3, w[i] : 6
table_result2[j - w[i]] : 11, table_result2[j] : 9 ----j : 8, i : 3, w[i] : 6
table_result2[j - w[i]] : 5, table_result2[j] : 9 ----j : 7, i : 3, w[i] : 6
table_result2[j - w[i]] : 5, table_result2[j] : 9 ----j : 6, i : 3, w[i] : 6
table_result2[j - w[i]] : 13, table_result2[j] : 14 ----j : 10, i : 4, w[i] : 5
table_result2[j - w[i]] : 13, table_result2[j] : 11 ----j : 9, i : 4, w[i] : 5
table_result2[j - w[i]] : 10, table_result2[j] : 11 ----j : 8, i : 4, w[i] : 5
table_result2[j - w[i]] : 10, table_result2[j] : 9 ----j : 7, i : 4, w[i] : 5
table_result2[j - w[i]] : 4, table_result2[j] : 9 ----j : 6, i : 4, w[i] : 5
table_result2[j - w[i]] : 4, table_result2[j] : 9 ----j : 5, i : 4, w[i] : 5
table_result2[j - w[i]] : 15, table_result2[j] : 14 ----j : 10, i : 5, w[i] : 4    ------这就是我们最终需要输出的值j==10的时候
table_result2[j - w[i]] : 15, table_result2[j] : 13 ----j : 9, i : 5, w[i] : 4
table_result2[j - w[i]] : 15, table_result2[j] : 11 ----j : 8, i : 5, w[i] : 4
table_result2[j - w[i]] : 12, table_result2[j] : 10 ----j : 7, i : 5, w[i] : 4
table_result2[j - w[i]] : 12, table_result2[j] : 9 ----j : 6, i : 5, w[i] : 4
table_result2[j - w[i]] : 6, table_result2[j] : 9 ----j : 5, i : 5, w[i] : 4
table_result2[j - w[i]] : 6, table_result2[j] : 9 ----j : 4, i : 5, w[i] : 4
第一种方法->总价值最大为：15
*/

int main() {
    int weight[6] = { 0,2,2,6,5,4 };//最低位补了0，从weight[1]开始赋值   
    int value[6] = { 0,6,3,5,4,6 };
    int c = 10;
    cout << "第一种方法->总价值最大为：" << Knapsack2(value, weight, c, 5) << endl;
    /*cout << "第二种方法->总价值最大为：" << KnapsackTwo(value, weight, c, 5) << endl;
    Traceback(weight, c, 5);
    cout << "最优值的解：";
    for (int i = 1;i < 5 + 1;i++)cout << flag[i] << " ";
    cout << endl;
    for (int i = 1;i < 6;i++) {
        for (int j = 0;j < 11;j++) {
            printf("%2d ", tableTwo[i][j]);
        }
        cout << endl;
    }     */
    return 0;

}
