int solve(int num, int l, int r)
{
    long long mid = l + (r-l)/2;
    
    if((mid*mid) == num)
                        return mid;
    
    if((mid*mid) < num && ((mid+1)*(mid+1)) > num )
                                                    return mid;
    
    if((mid*mid) < num)
                            return solve(num,mid+1,r);
    
    return solve(num, l, mid);
}

int Solution::sqrt(int num) 
{
    if(num<=1)
                return num;
    
    return solve(num,1,num);
}
