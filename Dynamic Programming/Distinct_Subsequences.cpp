int dp[1007][1007];
int solve(string str, int pos1, string sub, int pos2)
{
    int n1,n2;
    n1 = str.size();
    n2 = sub.size();
    
    if(n2 - pos2 > n1 - pos1)
    {
        return 0;
    }
    
    if(n2 == pos2)
    {
        return 1;
    }
    
    if(dp[pos1][pos2] != -1)
                            return dp[pos1][pos2];
                            
    if(str[pos1] != sub[pos2])
    {
        dp[pos1][pos2] = solve(str,pos1+1,sub,pos2);
    }
    
    else
    {
        dp[pos1][pos2] =  solve(str,pos1+1,sub,pos2+1) + solve(str,pos1+1,sub,pos2);
    }
    return dp[pos1][pos2];
}

int Solution::numDistinct(string str, string sub) 
{
    memset(dp, -1, sizeof(dp));
    return solve(str,0,sub,0);
}
