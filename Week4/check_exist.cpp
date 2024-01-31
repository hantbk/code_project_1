#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<int> myList(1000000);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>myList[i];
    }
    unordered_set<int> seenNumbers;
    for (int i = 0; i < n; i++)
    {
        if(seenNumbers.count(myList[i]) > 0){
            cout<<1<<"\n";
        }else{
            seenNumbers.insert(myList[i]);
            cout<<0<<"\n";
        }
    }
    return 0;
}