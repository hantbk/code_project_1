#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack;

    string sequence;
    cin >> sequence;
    while (sequence != "#")
    {
        if (sequence == "PUSH")
        {
            int n;
            cin >> n;
            stack.push(n);
        }
        if (sequence == "POP")
        {
            if (stack.empty())
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << stack.top() << endl;
                stack.pop();
            }
        }
        cin >> sequence;
    }

    // while (!stack.empty())
    // {
    //     cout<<stack.top()<<endl;
    //     stack.pop();
    // }

    return 0;
}