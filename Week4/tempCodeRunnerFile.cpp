#include <iostream>
#include <vector>
using namespace std;

vector<int> myHashCode;

void hashcode(string s, int m){
    int k = s.size();
    int h_s = 0;
    for (int i = 1; i <= k+1 ; i++)
    {
        h_s += int(s[i-1]) * pow(256,k-1);
        k--;
    }
    h_s = h_s % m;
    // cout<<h_s<<endl;
    myHashCode.push_back(h_s);
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    string word;
    for (int i = 0; i < n; i++)
    {
        cin>>word; 
        hashcode(word,m);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<myHashCode[i]<<endl;
    }
    return 0;
}