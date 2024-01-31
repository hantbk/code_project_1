#include<iostream>
#include<string>
using namespace std;

int main()
{
    string text;
    string line;
    string p1;
    string p2;
    getline(cin,p1);
    getline(cin,p2);
    while (getline(cin,line))
    {
        text+=line;
        text+='\n';
    }
    int pos = text.find(p1);
    while(pos!=-1){
        text.replace(pos,p1.size(),p2);
        pos = text.find(p1);
    }
    cout<<text<<endl;
    return 0;
}