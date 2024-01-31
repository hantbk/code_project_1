#include <bits/stdc++.h> 

using namespace std;

int main(){
    char date[11]; //YYYY-MM-DD
    char day[3], month[3], year[5];
    cin >> date;
    if (strlen(date) ==10 && date[4] == '-' && date[7] == '-')
    {
        for (int i = 0; i < 4; i++)
        {
            year[i] = date[i];
        }
        year[4] = '\0';
        for (int i = 5; i<7 ; i++)
        {
            int j = i-5;
            month[j] = date[i];
            j++;
        }
        month[2] = '\0';
        for (int i = 8 ; i<10 ; i++)
        {
            int j = i-8;
            day[j] = date[i];
            j++;
        }
    }
    else
    {
        cout << "INCORRECT" << endl;
        return 0;
    }
    int yyyy, mm, dd;
    yyyy=atoi(year);
    mm=atoi(month);
    dd=atoi(day);
    if (yyyy < 0 || yyyy > 9999 || mm < 1 || mm > 12 || dd < 1 || dd > 31)
    {
        cout << "INCORRECT" << endl;
    }
    else
    {
        cout << yyyy<<" "<<mm<<" "<<dd<< endl;
    }
    return 0;
}