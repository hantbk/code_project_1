#include <bits/stdc++.h>

using namespace std;

// <code> <date_of_birth> <father_code> <mother_code> <is_alive> <region_code>

string code, date, father, mother, alive, region;
int number_people, people_until[1116000];
map<int, int> number_people_born_at;
map<string, pair<string, string>> parent_of;
map<string, int> ancestor_count;

int max_unrelated_people;
// unrelated check
map<string, bool> unrelated;
// count child of {father, mother}
map<pair<string, string>, vector<string>> child_of;

int date_convert(string date)
{
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return year * 372 + month * 31 + day;
}

int ancestor_dis(string code)
{
    int res = 0;
    string father = parent_of[code].first;
    string mother = parent_of[code].second;
    if (father != "0000000" && mother != "0000000")
    {
        res += 1;
        res += max(ancestor_dis(father), ancestor_dis(mother));
    }
    ancestor_count[code] = res;
    return res;
}

void input()
{
    cin >> code;
    while (code != "*")
    {
        // NUMBER_PEOPLE
        number_people += 1;

        cin >> date >> father >> mother >> alive >> region;

        // NUMBER_PEOPLE_BORN_AT
        number_people_born_at[date_convert(date)] += 1;

        parent_of[code] = {father, mother};

        // MAX_UNRELATED_PEOPLE
        if (father == "0000000" && mother == "0000000")
        {
            max_unrelated_people += 1;
            unrelated[code] = true;
        }
        else
        {
            unrelated[code] = false;
            child_of[{father, mother}].push_back(code);

            if (child_of[{father, mother}].size() > 2 || unrelated[father] == false || unrelated[mother] == false)
            {
                if (unrelated[father] == true || unrelated[mother] == true)
                {
                    unrelated[father] = false;
                    unrelated[mother] = false;
                    max_unrelated_people -= 2;
                    for (auto it : child_of[{father, mother}])
                    {
                        unrelated[it] = true;
                        max_unrelated_people += 1;
                    }
                }
                else
                {
                    unrelated[code] = true;
                    max_unrelated_people += 1;
                }
            }
        }
        cin >> code;
    }

    // NUMBER_PEOPLE_BORN_BETWEEN
    int sum = 0;
    for (int i = 0; i < 1116000; i++)
    {
        sum += number_people_born_at[i];
        people_until[i] = sum;
    }
}

void querying()
{
    string query;
    cin >> query;
    while (query != "***")
    {
        if (query == "NUMBER_PEOPLE")
            cout << number_people << endl;
        else if (query == "NUMBER_PEOPLE_BORN_AT")
        {
            string date;
            cin >> date;
            cout << number_people_born_at[date_convert(date)] << endl;
        }
        else if (query == "MOST_ALIVE_ANCESTOR")
        {
            string code;
            cin >> code;
            if (ancestor_count[code] == 0)
                cout << ancestor_dis(code) << endl;
            else
                cout << ancestor_count[code] << endl;
        }
        else if (query == "NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string start, end;
            cin >> start >> end;
            cout << people_until[date_convert(end)] - people_until[date_convert(start) - 1] << endl;
        }
        else if (query == "MAX_UNRELATED_PEOPLE")
        {
            cout << max_unrelated_people << endl;
        }
        cin >> query;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    querying();
    return 0;
}
