int Solution::coinchange2(vector<int> &coins, int num) 
{
    int i,j, n = coins.size();
    int dp[num];
    int mod = 1000007;
    dp[0] = 1;
    for(i=1; i<=num; i++)
                        dp[i] = 0;
    for(i=0; i<n; i++)
    {
        for(j = coins[i]; j<=num; j++)
        {
            dp[j] = (dp[j] + dp[j-coins[i]])%mod;
        }
    }
    return (dp[num]+mod)%mod;
}
