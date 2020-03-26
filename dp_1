//2）、求解一个整数序列最长递增子序

static int[] dp = new int[arr.length];
private static int dp(int[] arr)
{
  dp[0] = 1;
  for(int i = 1;i < arr.length;i++)
  {
    int cnt = 1;
    for(int j = i - 1;j>=0;j--)
    {
      if(arr[i] > arr[j])
      {
        cnt = max(cnt,dp[i-1] + 1);
     }
  }
  dp[i] = cnt;
}

int ans =-1;
for(int i = 0;i < dp.length();i++)
{
    ans = max(ans,dp[i]);
}

return ans;
}
