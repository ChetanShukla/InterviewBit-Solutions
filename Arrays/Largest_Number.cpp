bool chk(string first, string second)
{
    string t1 = first + second;
    string t2 = second + first;
    return t1 < t2;
}
string Solution::largestNumber(const vector<int> &A) 
{
    int i,n;
    n = A.size();
    
    vector<string> Ans;
    
    for(i=0; i<n; i++)
    {
        int tmp,num;
        string s="";
        num = A[i];
        if(!num)
                s="0";
        
        while(num)
        {
            tmp = num%10;
            s = s + (char)(tmp+'0');
            num/=10;
        }
        reverse(s.begin(),s.end());
        Ans.push_back(s);
    }
    sort(Ans.begin(),Ans.end(),chk);
    string str="";
    for(i=n-1; i>=0; i--)
                        str = str + Ans[i];
    if(Ans[n-1]=="0")
                        str = "0";
    return str;
}
