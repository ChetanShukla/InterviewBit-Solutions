int Solution::solve(const vector<int> &cap, const vector<int> &dish, const vector<int> &cost) 
{
    int i,j,k,n1,n2,n3;
    
    vector<long long> dp;
    
    n1 = cap.size();
    
    int Max = cap[0];
    for(i=1; i<n1; i++)
    {
        Max = max(Max, cap[i]);
    }
    
    dp.resize(Max+1, INT_MAX);
    
    dp[0] = 0;
    
    n2 = dish.size();   n3 = cost.size();
    for(i=0; i<n2; i++)
    {
        for(j=0; j<=Max; j++)
        {
            if(j - dish[i] >= 0)
            {
                dp[j] = min(dp[j], dp[j-dish[i]] + cost[i]);
            }
        }
    }
    /*cout<<Max<<endl;
    
    for(i=0; i<=Max; i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    */
    int ans = 0;
    
    for(i=0; i<n1; i++)
    {
        ans += dp[cap[i]];
    }
    return ans;
}
