//C++11  (C98会报错)


//本模块实现01背包问题，对于指定的编号物品，选择拿或者不拿，不能拿走部分
/*
重量为w的背包，和N个物品：物品有两个属性：重量和价值（wt[i],val[i]）
用这个包装下价值最大的东西
举例：
N=3,W=4
wt = {2,1,3};
val = {4,2,3};
结果是取前面两个，返回最大价值为：4+2 = 6
*/

//1.明确状态和选择  2.明确dp的含义   3.根据选择思考状态转移的逻辑

#include <iostream>
#include <vector>
using namespace std;

/* DP_01backpack  */

int kanpsack(int W,int N,vector<int>& wt,vector<int>& val)
{
    // W:all weight
    //N:size
    //wt:everyone weight
    //val:everyone value
    //return:the most big value
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= W;j++)
        {
            if(j - wt[i - 1] < 0)
            {
                //The current weight is big than backpack size(weight)
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                //chose 0-1   do or donothing
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1],
                                dp[i-1][j]);
            }
            
        }
    }
    
    return dp[N][W];
    
}
  
int main()
{
	cout  << "test DP_01_backpack" <<endl;
    int result = 0;
    
    vector<int> wt = {2,1,3};
    vector<int> val = {4,2,3};
    result = kanpsack(3,4,wt,val);
    
    cout<<"Now the most big val is:"<<result<<endl;

	return 0;
}

