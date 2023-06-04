#include <iostream>
using namespace std;

int knapsnackHelper(int * weight, int * value , int W, int n, int ** dp)
{
    if(W == 0)
    {
        return 0;
    }
    if(W < 0)
    {
        return -9999;
    }
    if(n==0)
    {
        return 0;
    }

    if(dp[n][W]>0)
    {
        return dp[n][W];
    }

    int Include =value[n-1]+ knapsnackHelper(weight,value, W-weight[n-1], n-1, dp );
    int not_include = knapsnackHelper(weight, value, W, n-1, dp);
    dp[n][W] = max(Include, not_include);

    return dp[n][W];

}

int knapsnack(int * weight, int * value, int W, int n)
{
    int ** dp = new int * [n+1];
    for(int i=0 ; i<=n ;i++)
    {
        dp[i] = new int[W+1];
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            dp[i][j]=-1;
        }
    }

    int val = knapsnackHelper(weight, value, W, n, dp);

    for(int i=0; i<=n ; i++)
    {
        delete [] dp[i];
    }
    delete []dp;

    return val;
}

int knapsnackI(int * weight, int * value, int W, int n)
{
    int ** dp = new int * [n+1];
    for(int i=0 ; i<=n ;i++)
    {
        dp[i] = new int[W+1];
    }

    for(int i=0; i<=n; i++)
    {
        dp[0][i] = 0;

    }

    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;

    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            dp[i][j] =dp[i-1][j];
            if(weight[i-1]<=j)
            {
                dp[i][j] = max(dp[i][j], value[i-1]+dp[i-1][j-weight[i-1]]);
            }
        }
    }

    int ans  = dp[n][W];
    for(int i=0; i<=n; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    int n, max_weight;
    cin>>n;
    int * value =new int[n];
    int * weight =  new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>value[i];
    }
    cin>>max_weight;
    int maxm_val = knapsnack(weight, value, max_weight , n);
    cout<<maxm_val<<endl;
    cout<<knapsnackI(weight, value, max_weight, n)<<endl;

    return 0;

}
