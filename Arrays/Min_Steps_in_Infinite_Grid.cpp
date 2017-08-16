// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) 
{
    int res = 0;
    
    if(X.size() == 0 || Y.size() == 0)
                                        return res;
                                        
    int n = X.size();
    int i,j;
    
    int px = X[0], py = Y[0];
    
    for(i=1; i<n; i++)
    {
        int tmp1,tmp2;
        
        tmp1 = X[i] - px;
        tmp2 = Y[i] - py;
    
        res += max(abs(tmp1), abs(tmp2));
    
        px = X[i];
        py = Y[i];
    }
    return res;
}
