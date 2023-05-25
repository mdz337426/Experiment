#include <iostream>
#include <cstring>
using namespace std;
int arr1[10][10];

int kadane(int arr[], int n)
{
    int max_sum=0, current_sum=0;

    for(int i=0; i<n; i++)
    {
        current_sum +=arr[i];

        if(current_sum> max_sum)
        {
            max_sum = current_sum;
        }

        if(current_sum <0)
        {
            current_sum =0;
        }
    }

    return max_sum;
}

int maxm_sum_rect(int arr[][10], int n, int m)
{
    int temp[n];
    int maxm_sum = -99999;

    for(int i=0; i<m; i++)
    {
        memset(temp, 0 , sizeof(temp));
        for(int j=i; j<m ; j++)
        {
            for(int l=0; l<n; l++)
            {
                temp[l] +=arr[l][j]; 
            }

            int sum=kadane(temp, n);

            if(sum > maxm_sum)
            {
                maxm_sum = sum;
            }


        }
    }

    return maxm_sum;
}

int main()
{
    int n;
    int m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr1[i][j];
        }
    }

    int maxm_sum = maxm_sum_rect(arr1, n, m);
    cout<<maxm_sum <<endl;
    return 0;
}