#include <iostream>
using namespace std;

int n, m, a[100];
int sum = 0;

void print_solution()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= m; i++) 
    {
        a[k] = i;
        sum = sum + a[k];
        if (k == n - 1 && sum == m)
        {
            print_solution();
        }
        else if (k < n - 1) 
        {
            Try(k + 1);
        }
        sum = sum - a[k];
    }
}

int main()
{
    cin >> n >> m;
    Try(0);
    return 0;
}