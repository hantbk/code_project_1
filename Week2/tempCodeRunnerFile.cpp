#include<iostream>
using namespace std;
const long long mod=1e9+7;
long long binom[1001][1001];

int main()
{
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i==j || j==0) binom[i][j] = 1;
            else binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
            binom[i][j]%=mod;
        }
    }
    int n,k;
    cin>>k>>n;
    cout<<binom[n][k];
    return 0;
}