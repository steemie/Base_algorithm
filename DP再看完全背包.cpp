//本模块是在0-1背包的基础上编写的，01背包不大清楚，建议先弄明白后再进一步看此部分代码
#include <algorithm>
#include <iostream>

using namespace std;


//0-1背包回顾，其中状态转移方程为：table_result[i][j] = max(table_result[i-1][j],table_result[i - 1][j - w[i]] + v[i]);
//完全背包
//题目：有N种物品和一个背包，背包容量为C，***每种物品都有无限件***。放入第i种物品的费用是Mi,重量是Wi。求解：不超过背包容量的最大费用。
//1、基础解法，三层循环
int complete_backpack_base(int n,int w)      //n:物品数量 v:背包容量
{
    int W[20] = { 2,2,6,5,4 };//第i个物品的重量
    int V[20] = { 6,3,5,4,6 };//第i个物品的价值存放
    int dp[22][22] = { 0 };//i个物品，价值为j，每个物品数量为k时候的背包价值

    //printf("基础版\n");
    for (int i = 0;i < n;i++) //物品名录
    {
        for (int j = 0;j <= w;j++)      //物品的重量
        {
            for (int k = 0; k*W[i] <= j;k++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * W[i]] + k * V[i]);
                //printf("i:%d,j:%d,k:%d,dp[i + 1][j]:%d,dp[i][j - k * W[i]]:%d,W[i]:%d, V[i]:%d\n", i, j,k, dp[i + 1][j], dp[i][j - k * W[i]], W[i], V[i]);
            }
        }
    }

    return dp[n][w];
}

//2、优化版本，实际使用中三层循环会执行次数太多
int complete_backpack_increase(int n, int w)      //n:物品数量 v:背包容量
{
    int W[20] = { 2,2,6,5,4 };//第i个物品的重量
    int V[20] = { 6,3,5,4,6 };//第i个物品的价值存放
    int dp[22] = { 0 };//i个物品，价值为j，每个物品数量为k时候的背包价值

    //printf("优化版：\n");
    for (int i = 0;i < n;i++) 
    {
        for (int j = W[i];j <= w;j++)      //顺序：每一个物品都向最大值去加
        {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
            //printf("i:%d,j:%d,dp[j]:%d,dp[j - W[i]]:%d,W[i]:%d, V[i]:%d\n",i,j, dp[j], dp[j - W[i]], W[i], V[i]);
        }
    }

    return dp[w];
}




int main()
{

    int n = 5, w = 10;

    int res1 = complete_backpack_base(n, w);
    int res2 = complete_backpack_increase(n, w);
    //printf("最大价值分别为：res1:%d.res2:%d\n", res1,res2);


    system("pause");
    return 0;
}
