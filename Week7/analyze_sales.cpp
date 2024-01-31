#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

struct Order {
    string customerID;
    string productID;
    int price;
    string shopID;
    string timePoint;
};

vector<Order> orders;
unordered_map<string, int> shopRevenue;
int total_number_orders = 0;
int total_revenue = 0;

void processQuery(const string& query) {
    stringstream ss(query);
    string command;
    ss >> command;
    if (command == "#")
    {
        return;
    }
    if (command == "?total_number_orders") {
        cout << total_number_orders << endl;
    }
    else if (command == "?total_revenue") {
        cout << total_revenue << endl;
    }
    else if (command == "?revenue_of_shop") {
        string shopID;
        ss >> shopID;
        cout << shopRevenue[shopID] << endl;
    }
    else if (command == "?total_consume_of_customer_shop") {
        string customerID, shopID;
        ss >> customerID >> shopID;

        int totalConsume = 0;
        for (const auto& order : orders) {
            if (order.customerID == customerID && order.shopID == shopID) {
                totalConsume += order.price;
            }
        }
        cout << totalConsume << endl;
    }
    else if (command == "?total_revenue_in_period") {
        string fromTime, toTime;
        ss >> fromTime >> toTime;

        int totalRevenue = 0;
        for (const auto& order : orders) {
            if (order.timePoint >= fromTime && order.timePoint <= toTime) {
                totalRevenue += order.price;
            }
        }
        cout << totalRevenue << endl;
    }
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
        Order order;
        ss >> order.customerID >> order.productID >> order.price >> order.shopID >> order.timePoint;
        total_number_orders++;
        total_revenue += order.price;
        orders.push_back(order);
        shopRevenue[order.shopID] += order.price;
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