#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int pour(int fromCap, int toCap, int goal)
{
    int from = fromCap;
    int to = 0;
    int step = 1;

    while (from != goal && to != goal)
    {
        int temp = min(from, toCap - to);
        to += temp;
        from -= temp;
        step++;
        if (from == goal || to == goal)
        {
            break;
        }
        if (from == 0)
        {
            from = fromCap;
            step++;
        }
        if (to == toCap)
        {
            to = 0;
            step++;
        }
    }
    return step;
}

int minSteps(int a, int b, int c)
{
    // if (a > b)
    //     swap(a, b);
    if (c > b)
        return -1;
    if (c % gcd(a, b) != 0)
        return -1;
    return min(pour(a, b, c), pour(b, a, c));
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << minSteps(a, b, c);
    return 0;
}