int Solution::maxSubArray(const vector<int> &A) 
{
    int Loc_Max,Max;
    int i,n = A.size();
    
    Loc_Max = Max = A[0];
    
    for(i=1; i<n; i++)
    {
        Loc_Max = max(Loc_Max+A[i], A[i]);
        Max = max(Max,Loc_Max);
    }
    return Max;
}
