vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    int x = 0;
    int y = 0;
    
    int Xor = 0;
    int i,n = A.size();
    
    for(i=0; i<n; i++)
    {
        Xor = Xor ^ A[i];
    }
    
    for(i=1; i<=n; i++)
    {
        Xor = Xor^i;
    }
    
    int set_bit = Xor & ~(Xor-1);
    
    for(i=0; i<n; i++)
    {
        if(A[i] & set_bit)
                        x = x^A[i];
        else
                y = y^A[i];
    }
    for(i=1; i<=n; i++)
    {
        if(i & set_bit)
                        x = x^i;
        else
                y = y^i;
    }
    
    vector<int> ans;
    
   for(i=0; i<n; i++)
   {
       if(x == A[i])
       {
           ans.push_back(x);
           ans.push_back(y);
           break;
       }
       else if(y == A[i])
       {
           ans.push_back(y);
           ans.push_back(x);
           break;
       }
   }
    
    return ans;
}
