int Solution::solve(vector<vector<int> > &mat)
{
    int i,j,k,row,col;
    
    row = mat.size();
    col = mat[0].size();
    
    int temp[row+5][col+5];
    
    for(i=0; i<col; i++)
    {
        temp[0][i] = mat[0][i];
        
        for(j=1; j<row; j++)
        {
            if(mat[j][i])
            {
                temp[j][i] = temp[j-1][i] + 1;
            }
            else
            {
                temp[j][i] = 0;
            }
        }
    }
    for(i=0; i<row; i++)
    {
        int count[row+5];
        memset(count, 0 ,sizeof(count));
 
        for (j=0; j<col; j++)
                        count[temp[i][j]]++;
 
        //  Traverse the count array from right side
        int col_no = 0;
        for(j=row; j>=0; j--)
        {
            if (count[j] > 0)
            {
                for(k=0; k<count[j]; k++)
                {
                    temp[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
    int curr_area, max_area = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            curr_area = (j+1)*temp[i][j];

            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}
