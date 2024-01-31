// C++
#include <bits/stdc++.h>
using namespace std;

struct Order
{
    string customerID;
    string productID;
    int price;
    string shopID;
    string timePoint;
};

vector<Order> orders;
unordered_map<string, int> shopRevenue;
unordered_map<string, int> customerShopConsume;
int total_number_orders = 0;
int total_revenue = 0;
int revenueSecond[86400];
int revenueSecondFromZero[86400] = {0};

void processQuery(const string &query)
{
    stringstream ss(query);
    string command;
    ss >> command;
    if (command == "#")
    {
        return;
    }
    if (command == "?total_number_orders")
    {
        cout << total_number_orders << "\n";
    }
    else if (command == "?total_revenue")
    {
        cout << total_revenue << "\n";
    }
    else if (command == "?revenue_of_shop")
    {
        string shopID;
        ss >> shopID;
        cout << shopRevenue[shopID] << "\n";
    }
    else if (command == "?total_consume_of_customer_shop")
    {
        string customerID, shopID;
        ss >> customerID >> shopID;
        cout << customerShopConsume[customerID + "_" + shopID] << "\n";
    }
    else if (command == "?total_revenue_in_period")
    {
        string fromTime, toTime;
        ss >> fromTime >> toTime;
        int fromTimeSecond = stoi(fromTime.substr(0, 2)) * 3600 + stoi(fromTime.substr(3, 2)) * 60 + stoi(fromTime.substr(6, 2));
        int toTimeSecond = stoi(toTime.substr(0, 2)) * 3600 + stoi(toTime.substr(3, 2)) * 60 + stoi(toTime.substr(6, 2));
        int totalRevenue = 0;

        // cout << fromTimeSecond << " " << revenueSecond[fromTimeSecond] << "\n";
        // cout << toTimeSecond << " " << revenueSecond[toTimeSecond] << "\n";
        totalRevenue = revenueSecondFromZero[toTimeSecond] - revenueSecondFromZero[fromTimeSecond-1];
        cout << totalRevenue << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string line;
    while (getline(cin, line))
    {
        if (line == "#")
        {
            break;
        }
        stringstream ss(line);
        Order order;
        ss >> order.customerID >> order.productID >> order.price >> order.shopID >> order.timePoint;
        int hour = stoi(order.timePoint.substr(0, 2));
        int minute = stoi(order.timePoint.substr(3, 2));
        int second = stoi(order.timePoint.substr(6, 2));
        int timePointSecond = hour * 3600 + minute * 60 + second;
        revenueSecond[timePointSecond] += order.price;
        total_number_orders++;
        total_revenue += order.price;
        orders.push_back(order);
        shopRevenue[order.shopID] += order.price;
        customerShopConsume[order.customerID + "_" + order.shopID] += order.price;
    }

    int currentRevenue = 0;
    for (int i = 0; i <= 86400; i++)
    {
        currentRevenue += revenueSecond[i];
        revenueSecondFromZero[i] = currentRevenue;
    }

    string query;
    while (getline(cin, query))
    {
        if (query == "#")
        {
            break;
        }
        processQuery(query);
    }
    return 0;
}
