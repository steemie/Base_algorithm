//动态规划典型题目
//该类型题目思路：读懂题意，理清关系，寻找一个一维或者二维数组将i 和 i-1的关系表示出来，需要明确初始值

//1.给定两个字符串，寻找它们的最大子序列的数值。
//思路：欲求n的最大子序列，一定是基于本次比较，和前面的值

// java  方法源自网络博客
public int getgetLCS(String s1,String s2)
{
  if (s1 == NULL && NULL == s2)
  {
    return 0;
  }
  
  int sLength = s1.length();
  int tLength = s2.length();
  
  //从1开始存，new默认初始化为0了
  int [][] dp = new int[sLength + 1][tLength + 1];
  
  for(int i = 1;i <= sLength;i++)
  {
    for(int j = 1;j <= tLength;j++)
    {
        if(s1.charAt(i - 1) == s2.charat(j - 1))
        {
          //相等，则此次可以加1
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else
        {
          dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
        }
    }
  }
  
  //可以打印出每个值
  return dp[sLength][tLength];
  
}
                 
