#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string word;
    unordered_set<string> seenWords;
    cin>>word;
    while (word != "*")
    {
        seenWords.insert(word);
        cin>>word;
    }
    string query;
    cin>>query;
    while (query != "***")
    {
        if (query == "find")
        {
            string wordToFind;
            cin>>wordToFind;
            if (seenWords.count(wordToFind) > 0)
            {
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }
        if (query == "insert")
        {
            string wordToInsert;
            cin>>wordToInsert;
            if (seenWords.count(wordToInsert) > 0)
            {
                cout<<"0\n";
            }else{
                seenWords.insert(wordToInsert);
                cout<<"1\n";
            }
        }
        cin>>query;        
    }
    return 0;
}