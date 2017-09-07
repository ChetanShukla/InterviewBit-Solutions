int Solution::minimumTotal(vector<vector<int> > &A) 
{
    int i,j,m,n;
    
    m = A.size();
    n = A[m-1].size();
    
    for(i=m-2; i>=0; i--)
    {
        n = A[i].size();    
        
        for(j=0; j<n; j++)
        {
            A[i][j] += min(A[i+1][j], A[i+1][j+1]);
        }
    }
    return A[0][0];
}
