int Solution::pow(int Base, int Exp, int MOD) 
{
    long long y,ret=1;
    y=Base;
    while(Exp)
    {
        if(Exp&1)
            ret=(ret*y)%MOD;
        y = (y*y)%MOD;
        Exp/=2;
    }
    return (int)((ret+MOD)%MOD);
}
