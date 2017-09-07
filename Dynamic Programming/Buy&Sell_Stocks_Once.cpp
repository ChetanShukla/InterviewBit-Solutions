int Solution::maxProfit(const vector<int> &stocks) 
{
    int i,n = stocks.size();
    int ans = 0;
    
    if(n==0)    return ans;
    
    int left = stocks[0];
    
    for(i=1; i<n; i++)
    {
        left = min(left, stocks[i]);
        ans = max(ans, stocks[i] - left);
    }
    
    return ans;
}
