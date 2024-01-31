#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct transaction
{
    string fromAccount;
    string toAccount;
    int money;
    string timePoint;
    string atm;
};

vector<transaction> transactions;
set<string> accounts;

void exploreCycle(string account, int k, unordered_set<string> &visited_accounts, bool &has_cycle)
{
    if (k == 0)
    {
        if (visited_accounts.count(account) > 0)
        {
            has_cycle = true;
        }
        return;
    }
    for (auto transaction : transactions)
    {
        if (transaction.fromAccount == account && visited_accounts.count(transaction.toAccount) == 0)
        {
            if (transaction.fromAccount == transaction.toAccount )
            {
                has_cycle = false;
                break;
            }
            visited_accounts.insert(transaction.toAccount);
            exploreCycle(transaction.toAccount, k - 1, visited_accounts, has_cycle);
            visited_accounts.erase(transaction.toAccount);
        }
    }
}

void process()
{
    string query;
    while (cin >> query)
    {
        if (query == "#")
        {
            break;
        }
        if (query == "?number_transactions")
        {
            cout << transactions.size() << endl;
        }
        if (query == "?total_money_transaction")
        {
            int total_money_transaction = 0;
            for (auto t : transactions)
            {
                total_money_transaction += t.money;
            }
            cout << total_money_transaction << endl;
        }
        if (query == "?list_sorted_accounts")
        {
            vector<string> sorted_accounts(accounts.begin(), accounts.end());
            sort(sorted_accounts.begin(), sorted_accounts.end());
            for (auto s : sorted_accounts)
            {
                cout << s << " ";
            }
            cout << endl;
        }
        if (query == "?total_money_transaction_from")
        {
            string account;
            cin >> account;
            int total_money_transaction_from = 0;
            for (auto t : transactions)
            {
                if (t.fromAccount == account)
                {
                    total_money_transaction_from += t.money;
                }
            }
            cout << total_money_transaction_from << endl;
        }
        if (query == "?inspect_cycle")
        {
            string account;
            int k;
            cin >> account >> k;
            unordered_set<string> visited_accounts;
            visited_accounts.insert(account);
            string current_account = account;
            bool has_cycle = false;
            exploreCycle(current_account, k, visited_accounts, has_cycle);
            if (has_cycle)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}

void input()
{
    string fromAccount, toAccount, timePoint, atm;
    int money;
    while (cin >> fromAccount)
    {
        if (fromAccount == "#")
        {
            break;
        }
        cin >> toAccount >> money >> timePoint >> atm;
        transaction t;
        t.fromAccount = fromAccount;
        t.toAccount = toAccount;
        t.money = money;
        t.timePoint = timePoint;
        t.atm = atm;
        transactions.push_back(t);
        accounts.insert(fromAccount);
        accounts.insert(toAccount);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    process();
    return 0;
}