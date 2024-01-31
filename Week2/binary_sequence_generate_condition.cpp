#include <iostream>
using namespace std;

int n;
int a[1000];

void print_result()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i < 2; i++)
    {
        if(a[k-1] + i < 2){
            a[k] = i;
            if (k == n )
                print_result();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
    return 0;
}