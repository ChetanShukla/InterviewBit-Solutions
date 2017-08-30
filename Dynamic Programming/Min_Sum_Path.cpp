int Solution::minPathSum(vector<vector<int> > &grid) 
{
    int row = grid.size();
    int col = grid[0].size();
    
    vector< vector<int> > res;
    res.resize(row);
    
    int i,j,ret = 0;
    
    for(i=0; i<row; i++)
    {
        res[i].resize(col,0);
    }
                                
    res[row-1][col-1] = grid[row-1][col-1];
    
    for(i=row-2; i>=0; i--)
    {
        res[i][col-1] = res[i+1][col-1] + grid[i][col-1];
    }
    for(i=col-2; i>=0; i--)
    {
        res[row-1][i] = res[row-1][i+1] + grid[row-1][i];
    }
    
    for(i=row-2; i>=0; i--)
    {
        for(j=col-2; j>=0; j--)
        {
            res[i][j] = min(res[i+1][j], res[i][j+1]) + grid[i][j];
        }
    }
    ret = res[0][0];
    
    return ret;
}
