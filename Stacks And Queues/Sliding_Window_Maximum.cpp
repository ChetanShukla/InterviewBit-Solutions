vector<int> Solution::slidingMaximum(const vector<int> &nums, int k) 
{
    int i,n = nums.size();
    
    deque<int> Dq(k);
    vector<int> ans;
    
    for(i=0; i<k; i++)
    {
        while(!Dq.empty() && nums[i] >= nums[Dq.back()])
        {
            Dq.pop_back();
        }
        Dq.push_back(i);
    }
    
    for(; i<n; i++)
    {
        ans.push_back(nums[Dq.front()]);
        
        while(!Dq.empty() && Dq.front() <= i-k)
        {
            Dq.pop_front();
        }
        
        while(!Dq.empty() && nums[i] >= nums[Dq.back()])
        {
            Dq.pop_back();
        }
        Dq.push_back(i);
    }
    //cout<<"Reached here\n";
    ans.push_back(nums[Dq.front()]);

    return ans;    
}
