int dp[1007][1007];

int solve(int beg, int end, vector<int> &A)
{
    if(beg > end)
                    return 0;
    
    if(dp[beg][end] != -1)
                            return dp[beg][end];
    int ret;
    
    ret = max(A[beg] + min(solve(beg+1, end-1, A), solve(beg+2, end, A)),
              A[end] + min(solve(beg+1, end-1, A), solve(beg, end-2, A)) );
    
    dp[beg][end] = ret;
    
    return ret;
}

int Solution::maxcoin(vector<int> &A) 
{
    int i,j,n = A.size();
    
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            dp[i][j] = -1;
        }
    }
    return solve(0,n-1,A);
}
