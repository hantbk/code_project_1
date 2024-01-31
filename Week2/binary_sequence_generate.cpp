#include <iostream>
using namespace std;

int n;
int a[1000];

void print_result()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i < 2; i++)
    {
        a[k] = i;
        if (k == n-1)
            print_result();
        else
            Try(k + 1);
    }
}

int main()
{
    cin >> n;
    Try(0);
    return 0;
}