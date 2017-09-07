vector< vector<int> > dp;
int recur(int sum, int n)
{
    if(n == 0)
    {
        return (sum == 0);
    }
    //cout<<pos<<" "<<sum<<" "<<dig<<endl;
    if(dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    
    int mod = 1000000007;
    int ret = 0;
    
    for(int i=0; i<10; i++)
    {
        if(sum-i>=0)
                ret = (ret + recur(sum-i,n-1))%mod;
    }
    dp[n][sum] = (ret+mod)%mod;
    
    return ret%mod;
}

int Solution::solve(int n, int sum) 
{
    int i,ans = 0;
    dp.resize(n+1);
    
    for(i=0; i<=n; i++)
    {
        dp[i].resize(sum+1,-1);
    }
    int mod = 1000000007;
    for(i=1; i<10; i++)
    {
        if(sum-i>=0)
                ans = (ans + recur(sum-i,n-1))%mod;
    }
    
    /*for(i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }   */ 
    return (ans+mod)%mod;
}
