#include <iostream>
#include<cstring>
#include<string>
#define INT_MIN -99999
using namespace std;

int  comn_subseq_of_max_sumHelper(char* s1,char* s2,int  n,int  m,int  k, int *** dp){
    if(k==0)
    {
        return 0;
    }

    if(n==0 || m==0)
    {
        return INT_MIN;
    }

    if(dp[n][m][k]>0)
    {
        return dp[n][m][k];
    }

    int counts;
    if(s1[0]!=s2[0])
    {
        counts = max(comn_subseq_of_max_sumHelper(s1+1, s2, n-1, m , k, dp),comn_subseq_of_max_sumHelper(s1, s2+1, n, m-1 , k, dp) );
    }
    else{
        counts = max(( int(s1[0])+comn_subseq_of_max_sumHelper(s1+1, s2+1, n-1, m-1 , k-1, dp)), max(comn_subseq_of_max_sumHelper(s1+1, s2, n-1, m , k, dp), comn_subseq_of_max_sumHelper(s1, s2+1, n, m-1 , k, dp)));
    }

    dp[n][m][k] = counts;
    return counts;

}

int comn_subseq_of_max_sum(string S1,string S2,int k)
{
    int n = S1.length();
    int m = S2.length();

    //Allocation of 3D array in heap 
    int*** dp = new int**[n+1];

    for (int i = 0; i <n+1 ; i++)
    {
        dp[i] = new int*[m+1];
        for (int j = 0; j <=m; j++) {

            dp[i][j] = new int[k+1];
        }
    }

    //assigning -1 to each elem
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
            for (int t = 0; t <= k; t++) {
                dp[i][j][t] = -1;
            }
        }
    }
    char s1[n];
    char s2[m];
    strcpy(s1, S1.c_str());
    strcpy(s2, S2.c_str());
    int maxm_sum_subsequence = comn_subseq_of_max_sumHelper(s1, s2, n, m, k, dp);

    //Deallocation of heap memory
    for(int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++) {
            delete [] dp[i][j];

        }
        delete [] dp[i];
    }
    delete [] dp;
    
    return maxm_sum_subsequence >0 ? maxm_sum_subsequence: 0;
}

int main()
{
    int k, t;
    cin>>t;
    string s1,s2;
    while(t--)
    {
        cin>>s1>>s2;
        cin>>k;
        int res = comn_subseq_of_max_sum(s1, s2, k);
        cout<<res<<endl;
    }

    return 0;
}
