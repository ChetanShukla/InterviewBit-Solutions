int Solution::minCut(string A) 
{
    int i,j,k, n = A.size();
    
    int cuts[n], Pal[n][n];
    
    memset(Pal, 0 ,sizeof(Pal));
    
    for(i=0; i<n; i++)
                    Pal[i][i] = 1;
                    
    int len;
    
    for(len = 2; len<=n; len++)
    {
        for(i=0; i<n-len+1; i++)
        {
            j = i+len-1;
            
            if(len == 2)
            {
                Pal[i][j] = (A[i] == A[j]);
            }
            
            else if(A[i] == A[j])
            {
                Pal[i][j] = 1 & Pal[i+1][j-1];
            }
        }
    }
    for (i=0; i<n; i++)
    {
        if(Pal[0][i] == true)
                        cuts[i] = 0;
        else
        {
            cuts[i] = INT_MAX;
            for(j=0; j<i; j++)
            {
                if(Pal[j+1][i] == 1)
                    cuts[i] = min(cuts[i], 1+cuts[j]);
            }
        }
    }
    return cuts[n-1];
}
