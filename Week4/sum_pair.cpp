#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int count = 0;
    cin>>n>>m;
    vector<int> myList(n);
    for (int i = 0; i < n; i++)
    {
        cin>>myList[i];
    }
    unordered_set<int> seenNumbers;
    for (int i = 0; i < myList.size(); i++)
    {
        if (seenNumbers.count(m - myList[i]) > 0)
        {
            count++;
        }else{
            seenNumbers.insert(myList[i]);
        }
    }
    cout<<count<<"\n";
    return 0;
}