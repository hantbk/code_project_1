#include <iostream>
using namespace std;

int count = 0;
int solution = 0;
int a[1000][1000];

void input()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
        }
    }
}
bool checkCondition(int i, int j, int number)
{
    for (int k = 0; k < 9; k++)
    {
        if (number == a[k][j])
        {
            return false;
        }
    }
    for (int k = 0; k < 9; k++)
    {
        if (number == a[i][k])
        {
            return false;
        }
    }
    int r = i - i % 3;
    int c = j - j % 3;
    for (int k = r; k < r + 3; k++)
    {
        for (int t = c; t < c + 3; t++)
        {
            if (a[k][t] == number)
            {
                return false;
            }
        }
    }
    return true;
}

int Try(int m, int n)
{
    if (m == 9)
    {
        solution = solution + 1;
        return 0;
    }

    if (n == 9)
    {
        Try(m + 1, 0);
    }
    
    if (a[m][n] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (checkCondition(m, n, i))
            {
                a[m][n] = i;
                Try(m, n + 1);
                a[m][n] = 0;
            }
        }
    }
    else
    {
        Try(m, n + 1);
    }
}

int main()
{
    input();
    Try(0, 0);
    cout << solution;
}