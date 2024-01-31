#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> stack;
    string sequence;
    cin>>sequence;
    for (char c : sequence)
    {
        if(c =='{' | c == '[' | c == '('){
            stack.push(c);
        }else if ((c=='}' && stack.top()=='{') | (c==']' && stack.top()=='[') | (c==')' && stack.top()=='('))
        {
            stack.pop();
        }else
        {
            cout<<0;
            return 0;
        }
        
    }
    if (stack.empty())
    {
        cout<<1;
    }else cout<<0;
    return 0;
}