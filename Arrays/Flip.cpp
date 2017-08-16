vector<int> Solution::flip(string str) 
{
    vector<int> vec;
    
    int i,n;
    n = str.size();
    
    for(i=0; i<n; i++)
    {
        if(str[i] == '1')
                            vec.push_back(-1);
        else
                vec.push_back(1);
    }
    vector<int> ans;

    int sz = vec.size();
    for(i=0; i<sz; i++)
                        if(vec[i] == 1)
                                        break;
    if(i==sz)
                return ans;            
    
    int l,r;
    l = r = 1;
    int Max = vec[0];
    int Loc = vec[0];
    
    for(i=1; i<sz; i++)
    {
        Loc = max(Loc+vec[i], vec[i]);
        
        if(Loc > Max)
        {
            Max = Loc;
            r = i+1;
        }
    }
    Loc = 0;
    for(i=r-1; i>=0; i--)
    {
        Loc += vec[i];
        if(Loc == Max)
        {
            l = i+1;
            //break;
        }
    }
    ans.push_back(l);
    ans.push_back(r);
    
    return ans;
}
