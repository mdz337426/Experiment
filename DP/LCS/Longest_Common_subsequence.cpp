#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int lcs(char*s1, char *s2)
{
    if(s1[0]=='\0' || s2[0]=='\0')
    {
        return 0;
    }

    if(s1[0]==s2[0])
    {
        return 1+lcs(s1+1, s2+1);
    }
    else{
        return max(lcs(s1, s2+1), lcs(s1+1, s2));
    }
}
int lcs2helper(char * s1, char * s2, int n , int m, int ** dp)
{
    if(n==0 || m==0)
    {
        return 0;
    }

    if(dp[n][m]>-1)
    {
        return dp[n][m];
    }
    int ans;

    if(s1[0]==s2[0])
    {
        ans= 1+lcs2helper(s1+1, s2+1, n-1, m-1, dp);
    }
    else{
        int first = lcs2helper(s1+1, s2, n-1, m, dp);
        int second = lcs2helper(s1, s2+1, n, m-1, dp);
        ans =  max(first, second);
    }

    dp[n][m]=ans;
    return ans;

     
}

int lcs2(char * s1, char * s2){
    int n = strlen(s1);
    int m = strlen(s2);
    int ** dp = new int * [m+1];
    for(int i=0; i<=m; i++)
    {
        dp[i]= new int[n+1];
        for(int j=0; j<=n; j++)
        {
            dp[i][j]=-1;
        }
    }

    int ans = lcs2helper(s1,s2,n, m , dp);
    for(int i=0 ;i<=m ; i++)
    {
        delete [] dp[i];

    }

    
    delete [] dp;
    return ans;

}

int lcsI(char*s1, char*s2)
{
    int n = strlen(s1);
    int m = strlen(s2);
    int ** dp = new int * [m+1];
    for(int i=0; i<=m; i++)
    {
        dp[i]= new int[n+1];
    }
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=0;

    }

    for(int i=0; i<=m; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1; i<=n ; i++)
    {
        for(int j=1; j<=m ; j++)
        {
            if(s1[n-i]==s2[m-j])
            {
                dp[i][j] = 1+dp[i-1][j-1];

            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            }
        }
    }
    

    int ans = dp[m][n];
    for(int i=0 ;i<=m ; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}


int main()
{
    int n,m;
    cin>>n>>m;
    char s1[n];
    char s2[m];

    cin>>s1>>s2;
    cout<<lcs2(s1, s2)<<endl;
    cout<<lcsI(s1, s2)<<endl;
    return 0;
    
}
