#include<iostream>
using namespace std;

int n,a[1000],used[1000];

void print_solution()
{
    for (int i = 1; i <= n ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int k){
    for (int i = 1; i <= n; i++)
    {
        if (used[i]==0)
        {
            a[k] = i;
            used[i] = 1;
            if(k==n) print_solution();
            else Try(k+1);
            used[i] = 0;
        }
    }
}

int main(){
    cin>>n;
    Try(1);
    return 0;
}