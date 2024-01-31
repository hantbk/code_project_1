#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Transaction {
    string fromAccount;
    string toAccount;
    int money;
    string timePoint;
    string atm;
};

vector<Transaction> transactions;
unordered_map<string, int> accountOutgoingMoney;
unordered_map<string, unordered_set<string>> accountIncomingAccounts;

void processQuery(const string& query) {
    stringstream ss(query);
    string command;
    ss >> command;

    if (command == "?number_transactions") {
        cout << transactions.size() << endl;
    }
    else if (command == "?total_money_transaction") {
        int totalMoney = 0;
        for (const auto& transaction : transactions) {
            totalMoney += transaction.money;
        }
        cout << totalMoney << endl;
    }
    else if (command == "?list_sorted_accounts") {
        unordered_set<string> accounts;
        for (const auto& transaction : transactions) {
            accounts.insert(transaction.fromAccount);
            accounts.insert(transaction.toAccount);
        }
        vector<string> sortedAccounts(accounts.begin(), accounts.end());
        sort(sortedAccounts.begin(), sortedAccounts.end());
        for (const auto& account : sortedAccounts) {
            cout << account << endl;
        }
    }
    else if (command == "?total_money_transaction_from") {
        string account;
        ss >> account;
        cout << accountOutgoingMoney[account] << endl;
    }
    else if (command == "?inspect_cycle") {
        string account;
        int k;
        ss >> account >> k;

        unordered_set<string> visited;
        visited.insert(account);
        if (inspectCycleHelper(account, account, k - 1, visited)) {
            cout << "1" << endl;
        }
        else {
            cout << "0" << endl;
        }
    }
}

bool inspectCycleHelper(const string& startAccount, const string& currAccount, int k, unordered_set<string>& visited) {
    if (k == 0) {
        if (accountIncomingAccounts[currAccount].count(startAccount) > 0) {
            return true;
        }
        return false;
    }

    for (const auto& nextAccount : accountIncomingAccounts[currAccount]) {
        if (visited.count(nextAccount) == 0) {
            visited.insert(nextAccount);
            if (inspectCycleHelper(startAccount, nextAccount, k - 1, visited)) {
                return true;
            }
            visited.erase(nextAccount);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        stringstream ss(line);
        Transaction transaction;
        ss >> transaction.fromAccount >> transaction.toAccount >> transaction.money >> transaction.timePoint >> transaction.atm;
        transactions.push_back(transaction);
        accountOutgoingMoney[transaction.fromAccount] += transaction.money;
        accountIncomingAccounts[transaction.toAccount].insert(transaction.fromAccount);
    }

    string query;
    while (getline(cin, query)) {
        if (query == "#") {
            break;
        }
        processQuery(query);
    }

    return 0;
}