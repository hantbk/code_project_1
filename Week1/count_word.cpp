#include<iostream>
#include<string>
using namespace std;

int main()
{
    string text;
    string line;
    int count = 0;
    while(getline(cin, line))
    {
        if(line.empty()){
            count++;
            // if(count==3){
            //     break;
            // }
            text += '\n';    
        }else{
            count = 0;
            text += line;
            text += '\n';
        }     
    }
    int wordCount = 0;
    bool inWord = false;
    for(char c : text){
        if(c!=' ' && c!='\n' && c!='\t'){
            if(!inWord){
                wordCount++;
                inWord = true;
            }
        }else
        {
            inWord = false;
        }
    }
    cout << wordCount << endl;
    return 0;
}