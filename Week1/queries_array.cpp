#include <iostream>

using namespace std;
int n, sum = 0, find_max = -1000, find_min = 1000;

int main()
{
    cin >> n;
    int list[n + 1], temp;
    int i, j;
    i = 1;
    while (i <= n)
    {
        cin >> temp;
        list[i] = temp;
        sum += temp;
        if (temp > find_max)
            find_max = temp;
        if (temp < find_min)
            find_min = temp;
        i = i + 1;
    }
    string query;
    cin >> query >> query;
    while (query != "***")
    {
        if (query == "find-max")
            cout << find_max << endl;
        else if (query == "find-min")
            cout << find_min << endl;
        else if (query == "sum")
            cout << sum << endl;
        else
        {
            cin >> i >> j;
            temp = list[i];
            while (i <= j)
            {
                if (temp < list[i])
                    temp = list[i];
                i = i + 1;
            }
            cout << temp << endl;
        }
        cin >> query;
    }
    return 0;
}