#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k,index=0;
    int count=0;
    cin>>n>>k;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum+=vec[i];
    }
    if(sum%2==0) count++;
    for (int i = k; i < n; i++)
    {
        sum = sum - vec[i-k] + vec[i];
        if(sum%2==0) count++;
    }
    
    cout<<count<<endl;
    return 0;
}