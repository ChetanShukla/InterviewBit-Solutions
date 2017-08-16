int nCr(int n, int r)
{
    int i;
    double ret = 1.0;
    
    r = min(r,n-r);
    for(i=1; i<=r; i++)
    {
        ret = ret*(n-r+i);
        ret = ret/i;
    }
    return ret;
}

vector<vector<int> > Solution::generate(int k) 
{
    vector<int> temp;
    
    vector< vector<int> > res;
    if(!k)
                return res;
    
    temp.push_back(1);
    
    res.push_back(temp);
    
    if(k == 1)
            return res;
    
    for(int i = 1; i<k; i++)
    {
        temp.clear();
        for(int j=0; j<=i; j++)
        {
            temp.push_back(nCr(i,j));
        }
        res.push_back(temp);
    }
    return res;
}
