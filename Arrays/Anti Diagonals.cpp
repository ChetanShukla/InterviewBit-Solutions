vector<vector<int> > Solution::diagonal(vector<vector<int> > &grid) 
{
    int i,j,k,n = grid.size();
    
    vector< vector<int> > ans;
    
    if(n==0)
                return ans;
                
    for(k=0; k<((2*n)-1); k++)
    {
        vector<int> temp;
        
        if(k<n)
        {
            for(i=0,j=k; i<n && j>=0; i++,j--)
            {
                temp.push_back(grid[i][j]);
            }
        }
        else
        {
            for(i=k-n+1,j=n-1; i<n && j>=0; i++,j--)
            {
                temp.push_back(grid[i][j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
