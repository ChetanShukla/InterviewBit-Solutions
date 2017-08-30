int Solution::adjacent(vector<vector<int> > &A) 
{
    int i,j,k,x,y,z;
    x = A.size();
    y = A[0].size();
    
    int dp[y][2];
    
    dp[0][0] = 0;
    dp[0][1] = max(A[0][0],A[1][0]);
    
    for(j=1; j<y; j++)
    {
        // Iss column se uthana hai toh
        dp[j][1] = dp[j-1][0] + max(A[0][j], A[1][j]);
        // Nahin lena agar toh
        dp[j][0] = max(dp[j-1][0], dp[j-1][1]);
    }
    return max(dp[y-1][0], dp[y-1][1]);
}
