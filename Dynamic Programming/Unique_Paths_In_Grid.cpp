int Solution::uniquePathsWithObstacles(vector<vector<int> > &grid) 
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
    
    if(grid[row-1][col-1] == 1)
                                return 0;
                                
    res[row-1][col-1] = 1;
    
    for(i=row-2; i>=0; i--)
    {
        if(grid[i][col-1] == 1)
                                res[i][col-1] = 0;
        else
                res[i][col-1] = res[i+1][col-1];
    }
    for(i=col-2; i>=0; i--)
    {
        if(grid[row-1][i] == 1)
                                res[row-1][i] = 0;
        else
                res[row-1][i] = res[row-1][i+1];
    }
    
    for(i=row-2; i>=0; i--)
    {
        for(j=col-2; j>=0; j--)
        {
            if(grid[i][j] == 1)
                                res[i][j] = 0;
            else
            {
                res[i][j] = res[i+1][j] + res[i][j+1];
            }
        }
    }
    ret = res[0][0];
    
    return ret;
}
