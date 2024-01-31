#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> queue;
    string sequence;
    cin>>sequence;
    while (sequence != "#")
    {
        if(sequence == "PUSH"){
            int n;
            cin>>n;
            queue.push(n);
        }
        if(sequence == "POP"){
            if(queue.empty()){
                cout<<"NULL"<<endl;
            }else
            {
                cout<<queue.front()<<endl;
                queue.pop();
            }
        }
        cin>>sequence;
    }
    
    return 0;
}