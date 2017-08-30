vector<int> Solution::nextGreater(vector<int> &nums) 
{
    vector<int> Ans;
    
    int i,n = nums.size();
    
    if(!n)  return Ans;
    Ans.resize(n);
    stack<int> St;
    
    for(i=0; i<n; i++)
    {
        if(St.empty() || nums[St.top()] >= nums[i])
        {
            St.push(i);
        }
        else
        {
            while(!St.empty() && nums[St.top()] < nums[i])
            {
                int tp = St.top();
                
                Ans[tp] = nums[i];
                St.pop();
            }
            St.push(i);
        }
    }
    while(!St.empty())
    {
        int tp = St.top();
            
        Ans[tp] = -1;
        St.pop();
    }
    return Ans;
}
