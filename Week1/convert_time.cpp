#include<iostream>
using namespace std;

int main(){
    char time[8]; //hh:mm:ss
    cin >> time;
    if (strlen(time) == 8 && time[2] == ':' && time[5] == ':')
    {
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int minute = (time[3] - '0') * 10 + (time[4] - '0');
        int second = (time[6] - '0') * 10 + (time[7] - '0');
        if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59)
        {
            cout << hour*3600 + minute*60 + second << endl;
        }
        else
        {
            cout << "INCORRECT" << endl;
        }
    }
    else
    {
        cout << "INCORRECT" << endl;
        return 0;
    }
    return 0;
}