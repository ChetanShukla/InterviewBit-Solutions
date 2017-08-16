vector<int> Solution::getRow(int rowIndex) 
{
    vector<int> res;
    res.push_back(1);
    int n = (rowIndex)/2;
    for (int i=1;i<=n;i++)
    {
        double r = double(res[i-1]) * (double(rowIndex)+1-double(i))/double(i);
        res.push_back(r);
    }
        
    if (rowIndex%2==1)
    {
        int sz = res.size();
        for (int i=sz-1;i>=0;i--)
        {
            res.push_back(res[i]);
        }
    }
    else
    {
        int sz = res.size();
        for (int i=sz-2;i>=0;i--)
        {
            res.push_back(res[i]);
        }
    }
    return res;
}
