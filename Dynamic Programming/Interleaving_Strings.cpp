int dp[105][105][105];

bool solve(string s1, int pos1, string s2, int pos2, string s3, int pos3)
{
    if(pos3 == s3.size())
    {
        return true;
    }
    if(pos1 > s1.size() || pos2 > s2.size())
    {
        //cout<<"Yahan se hua\n";
        return false;
    }
    if(s3[pos3] != s2[pos2] && s3[pos3] != s1[pos1])
    {
        return false;
    }
    
    if(dp[pos1][pos2][pos3] != -1)
                                    return dp[pos1][pos2][pos3];
    bool ret = false;
    
    if(s3[pos3] == s2[pos2] && s3[pos3] != s1[pos1])
    {
        ret |= solve(s1,pos1,s2,pos2+1,s3,pos3+1);
    }
    else if(s3[pos3] != s2[pos2] && s3[pos3] == s1[pos1])
    {
        ret |= solve(s1,pos1+1,s2,pos2,s3,pos3+1);
    }
    else if(s3[pos3] == s2[pos2] && s3[pos3] == s1[pos1])
    {
        ret |= solve(s1,pos1+1,s2,pos2,s3,pos3+1) | solve(s1,pos1,s2,pos2+1,s3,pos3+1);
    }
    dp[pos1][pos2][pos3] = ret;
    return ret;
}
int Solution::isInterleave(string s1, string s2, string s3) 
{
    int n1,n2,n3;
    n1 = s1.size();
    n2 = s2.size();
    n3 = s3.size();
    
    memset(dp, -1, sizeof(dp));
    
    return solve(s1,0,s2,0,s3,0);
}
