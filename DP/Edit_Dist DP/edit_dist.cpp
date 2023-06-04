#include<iostream>
#include<cstring>
using namespace std; 

int edit_dist(char * s1, char *s2)
{
    if(s1[0]=='\0')
    {
        return strlen(s2);
    }

    if(s2[0]=='\0')
    {
        return strlen(s1);
    }
    int countt;
    if(s1[0]==s2[0])
    {
        countt = edit_dist(s1+1, s2+1);
    }
    else{
        countt =1+ min(edit_dist(s1+1, s2+1), min(edit_dist(s1+1,s2),edit_dist(s1,s2+1)));
    }
    return countt;
}

int edit_dist2helper(char * s1, char * s2, int n, int m , int ** dp)
{
    if(n==0 )
    {
        return m;  
    }

    if(m==0)
    {
        return n;
    }

    if(dp[n][m]>0)
    {
        return dp[n][m];

    }

    int zcount;
    if(s1[0]==s2[0])
    {
        zcount = edit_dist2helper(s1+1, s2+1, n-1, m-1, dp);
    }
    else{
        zcount = 1+min(edit_dist2helper(s1+1, s2+1, n-1, m-1, dp), min(edit_dist2helper(s1, s2+1, n, m-1, dp),edit_dist2helper(s1+1, s2, n-1, m, dp)));
    }

    dp[n][m]=zcount;


    return zcount;

}


int edit_dist2(char * s1, char * s2)
{
    int n =strlen(s1);
    int m = strlen(s2);
    int ** dp = new int *[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i]= new int [m+1];
        for(int j =0; j<=m; j++){
            dp[i][j]=-1;
        }
    }

    int calc = edit_dist2helper(s1, s2, n, m , dp);

    for(int i=0; i<n; i++)
    {
        delete []dp[i];
    }
    delete []dp;
    return calc;
}

int edit_distI(char * s1, char * s2)
{
    int n = strlen(s1);
    int m = strlen(s2);
    int ** dp = new int *[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i]= new int [m+1];    
    }

    for (int i=0; i<=n;i++ )
    {
        dp[i][0] = i;

    }

     for (int i=0; i<=m;i++ )
    {
        dp[0][i] = i;

    }

    for(int i=1 ; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[n-i]==s2[m-j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]));
            }

        }
    }
    int ans = dp[n][m];
    for(int i=0; i<=n; i++)
    {
        delete []dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    int m,n;
    cin>>m>>n;
    char s1[m];
    char s2[n];
    cin>>s1;
    cin>>s2;
    cout<<edit_dist2(s1, s2)<<endl;
    cout<<edit_distI(s1, s2)<<endl;
    //cout<<edit_dist(s1, s2)<<endl;
    return 0;
}
