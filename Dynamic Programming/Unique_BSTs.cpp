int solve(int n, vector<int> &solutions)
{
    if(n==0 || n==1)
                    return 1;
    
    int ret = 0;                
    for(int i=1; i<=n; i++)
    {
        if(solutions[i-1] == -1)
                                solutions[i-1] = solve(i-1,solutions);
        if(solutions[n-i] == -1)
                                solutions[n-i] = solve(n-i, solutions);
                                
        ret += solutions[i-1] * solutions[n-i];
    }
    return ret;
}
int Solution::numTrees(int n) 
{
    vector<int> solutions(n+1);
    
    for(int i = 0; i<=n; i++)
    {
        solutions[i] = -1;
    }
    return solve(n,solutions);
}
