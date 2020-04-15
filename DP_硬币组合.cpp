.cpp/*
*本模块重点深究动态规划的解法，并且对每种解法提出自己的思路
*和代码实现，重点在于方法，不在于最终的结果
*
*/


#include"standard.h"


// 1.硬币问题：2 5 7，最终需要若干硬币凑成27，求解需要的最少硬币数

//题目分析 1)求最小解：用dp
//			2）最后一步的最优解是什么：f(27) = min((f(27 - 2)+1 ),f(27 - 5)+1,f(27 - 7)+1)



//用递归看看 ,这个函数返回最小值问题
int f(int x)
{
	if (x == 0)
	{
		return  0;

	}

	int res = STAD_MAX_INT_MAX_VALUE; 
	//我们分情况进行递归求解
	if (x>=2)
	{
		res = min(f(x - 2) + 1,res);
	}

	if (x>=5)
	{
		res = min(f(x - 5) + 1,res);
	}
	if (x>=7)
	{
		res = min(f(x - 7) + 1,res);
	}

	return res;

}


//解决表达式必须含有常量值
/****************************
方法1：使用动态内存分配，new和delete操作符
int num;
cin >> num;
int* a = new int[num];
…
delete[] a;
方法2：使用vector容器
int num;
cin >> num;
vector a(num);
方法3：
宏定义大小，或者使用const int转换

*************************/
//dp解法：四部曲
// 1.确定状态 2、转移方程 3、边界条件和初始值 4、计算顺序
int coninChange(int A[],int M,int lengthA)
{
	//考虑dp数据的大小
	int *dp = new int[M +1];

	int n = lengthA;


	dp[0] = 0;
	
	for(int i =1;i <= M;i++)
	{
		dp[i] = STAD_MAX_INT_MAX_VALUE;
		for(int j = 0;j < n;j++)
		{
			//换个思路，把dp初始化为负数，为负数的时候就直接，最小值就直接等于
			//新的，否则就取最小值
			if(i >= A[j] && dp[i - A[j]] != STAD_MAX_INT_MAX_VALUE)
			{
				dp[i] = min(dp[i - A[j]] + 1,dp[i]);
			}

		}
	}

	if(dp[M] == STAD_MAX_INT_MAX_VALUE)
	{
		return -1;
	}
	int res = dp[M];

	delete dp;

	return res;






}

int main()
{

	int res = 0;
	int A[3] = {2,5,7};
	int M = 27;
	res = coninChange(A,M,3);
	cout<<res<<endl;

	system("pause");
	return 0;
}
