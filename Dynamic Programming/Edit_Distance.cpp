int Solution::minDistance(string A, string B) 
{
    int i,j,m,n;
    m = A.size();
    n = B.size();
    
    int dp[m+1][n+1];
    
    for(i=0; i<=m; i++)
                    dp[i][0] = i;
    for(i=0; i<=n; i++)
                    dp[0][i] = i;
                    
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(A[i-1] == B[j-1])
                            dp[i][j] = dp[i-1][j-1];
            else
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])); 
        }
    }
    return dp[m][n];
}
