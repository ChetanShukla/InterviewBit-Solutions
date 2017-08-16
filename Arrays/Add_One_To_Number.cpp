vector<int> Solution::plusOne(vector<int> &A) 
{
    int n = A.size();
    
    int i,tmp = 1;
    
    for(i=n-1; i>=0; i--)
    {
        A[i] = A[i] + tmp;
        tmp = A[i]/10;
        A[i] = A[i]%10;
    }
    vector<int> B;
    i = 0;
    if(tmp)
            B.push_back(tmp);
    else
    {
        while(A[i] == 0)
                        i++;
    }
    
    for(; i<n; i++)
                    B.push_back(A[i]);
    return B;
}
