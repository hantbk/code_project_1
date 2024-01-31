#include <iostream>
#include <vector>
#define ll unsigned long long
using namespace std;

vector<ll> myHashCode;

void hashcode(string s, int m) {
    int k = s.size();
    ll h_s = 0;
    ll power = 1;  // Initialize power as 1
    for (int i = k - 1; i >= 0; i--) {  // Reverse the loop to avoid computing pow
        h_s += ((int(s[i]) * power) % m) % m;
        power = (power * 256) % m;  // Multiply power by 256 in each iteration
    }
    h_s %= m;  // Compute modulo to prevent overflow
    // cout << h_s << endl;
    myHashCode.push_back(h_s);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        hashcode(word, m);
    }
    for (int i = 0; i < n; i++) {
        cout << myHashCode[i] << "\n";
    }
    return 0;
}