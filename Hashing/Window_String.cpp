string Solution::minWindow(string S, string T) 
{
    if (S.size() < T.size())
    {
        return "";
    }
             
    map<char,int>mp; 
    for(int i=0;i<T.size();i++)
    {
        mp[T[i]]++;
    }
    int res_len=INT_MAX; // result length
    int res_p=0;//result start posiion
         
    int p=0; //pointer start
    int q=S.size()-1; //pointer end
         
    while(mp[S[p]]==0)
    {
        if(p>=S.size())
        {
            return "";
        } 
        p++;
    }
    while(mp[S[p]]==0)
    {
        q--;
        if(q<0)
        {
            return "";
        }
    }
    map<char,int> tab; //store chars occurrence of S[p:q]
    for (int i=p;i<=q;i++)
    {
        tab[S[i]]++;
    } 
    
    while (tab[S[q]]>mp[S[q]] || mp[S[q]]==0)
    { 
        tab[S[q]]--;
        q--;
    }
             
    for (int i=0;i<T.size();i++)
    {  
        if (tab[T[i]]<mp[T[i]])
        {
            return "";
        }
    }
    if (q-p+1<res_len)
    {
        res_len=q-p+1; 
        res_p=p;
    }    
         
    while (p<q)
    {
        if (q-p+1<res_len)
        {
            res_len=q-p+1; 
            res_p=p;
        } 
        if (mp[S[p]]==0)
        {
            p++;
            continue;
        }   
        if (tab[S[p]]>mp[S[p]])
        {
            tab[S[p]]--;
            p++;
            continue;
        }
        q++; 
        while (q<S.size() && S[q]!=S[p])
        { 
            if (mp[S[q]]>0)
            {
                tab[S[q]]++;
            } 
            q++;
        }
        if (q>=S.size())
        {
            q=S.size()-1;
        }
        else
        {
            tab[S[q]]++;
        }
        if (S[q]==S[p])
        { 
            tab[S[p]]--; 
            if (tab[S[p]]<mp[S[p]])
            {
                break;
            } 
            p++;
            continue;
        }        
            break;
    }
         
    return S.substr(res_p,res_len);
}
