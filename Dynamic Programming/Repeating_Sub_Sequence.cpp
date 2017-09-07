int Solution::anytwo(string str) 
{
    int i,j,n = str.size();
    
    int dp[n+1][n+1];
    
    memset(dp,0,sizeof(dp));
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(str[i-1] == str[j-1] && i!=j)
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    if(dp[n][n] >= 2)
                    return true;
    return false;
}
