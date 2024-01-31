#include <iostream>
using namespace std;

int fibonaci(int n){
    int f1, f2, f3, k;
    if(n<=1) return n;
    else
    {
        f1=0;
        f2=1;
        for ( k = 2; k <= n; k++)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
    
}

int main()
{
    int n;
    cin>>n;
    cout<<fibonaci(n-1);
    return 0;
}