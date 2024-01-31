#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Citizen {
    std::string code;
    std::string date_of_birth;
    std::string father_code;
    std::string mother_code;
    char is_alive;
    std::string region_code;
};

std::vector<Citizen> people;
std::unordered_map<std::string, std::vector<int>> code_to_indices;
std::unordered_map<std::string, std::vector<int>> date_to_indices;
std::unordered_map<std::string, std::string> parent_to_child;
std::unordered_set<std::string> unrelated_people;

int number_people() {
    return people.size();
}

int number_people_born_at(const std::string& date) {
    if (date_to_indices.find(date) != date_to_indices.end()) {
        return date_to_indices[date].size();
    }
    return 0;
}

int find_generation_distance(const std::string& code) {
    std::queue<std::string> q;
    std::unordered_map<std::string, int> distance;
    q.push(code);
    distance[code] = 0;
    int max_distance = 0;

    while (!q.empty()) {
        std::string curr_code = q.front();
        q.pop();
        int curr_distance = distance[curr_code];
        max_distance = std::max(max_distance, curr_distance);

        if (parent_to_child.find(curr_code) != parent_to_child.end()) {
            std::string parent_code = parent_to_child[curr_code];
            if (distance.find(parent_code) == distance.end()) {
                distance[parent_code] = curr_distance + 1;
                q.push(parent_code);
            }
        }
    }

    return max_distance;
}

int most_alive_ancestor(const std::string& code) {
    return find_generation_distance(code);
}

int number_people_born_between(const std::string& from_date, const std::string& to_date) {
    int count = 0;
    for (const auto& person : people) {
        if (person.date_of_birth >= from_date && person.date_of_birth <= to_date) {
            count++;
        }
    }
    return count;
}

void dfs(const std::string& code, std::unordered_set<std::string>& visited) {
    visited.insert(code);
    if (parent_to_child.find(code) != parent_to_child.end()) {
        std::string child_code = parent_to_child[code];
        if (visited.find(child_code) == visited.end()) {
            dfs(child_code, visited);
        }
    }
    for (const auto& person : people) {
        if (person.father_code == code || person.mother_code == code) {
            if (visited.find(person.code) == visited.end()) {
                dfs(person.code, visited);
            }
        }
    }
}

int max_unrelated_people() {
    int max_size = 0;
    for (const auto& person : people) {
        std::unordered_set<std::string> unrelated_set;
        for (const auto& p : people) {
            unrelated_set.insert(p.code);
        }
        std::unordered_set<std::string> related_set;
        dfs(person.code, related_set);
        for (const auto& p : related_set) {
            unrelated_set.erase(p);
        }
        max_size = std::max(max_size, static_cast<int>(unrelated_set.size()));
    }
    return max_size;
}

int main() {
    std::string line;
    // Read the first block (DataBase)
    while (getline(std::cin, line) && line != "*") {
        std::string code, date_of_birth, father_code, mother_code, is_alive, region_code;
        std::istringstream iss(line);
        iss >> code >> date_of_birth >> father_code >> mother_code >> is_alive >> region_code;
        people.push_back({ code, date_of_birth, father_code, mother_code, is_alive[0], region_code });
        code_to_indices[code].push_back(people.size() - 1);
        date_to_indices[date_of_birth].push_back(people.size() - 1);
        if (father_code != "0000000") {
            parent_to_child[father_code] = code;
        }
        if (mother_code != "0000000") {
            parent_to_child[mother_code] = code;
        }
    }

    // Read the second block (queries)
    while (getline(std::cin, line) && line != "***") {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "NUMBER_PEOPLE") {
            std::cout << number_people() << std::endl;
        } else if (command == "NUMBER_PEOPLE_BORN_AT") {
            std::string date;
            iss >> date;
            std::cout << number_people_born_at(date) << std::endl;
        } else if (command == "MOST_ALIVE_ANCESTOR") {
            std::string code;
            iss >> code;
            std::cout << most_alive_ancestor(code) << std::endl;
} else if (command == "NUMBER_PEOPLE_BORN_BETWEEN") {
            std::string from_date, to_date;
            iss >> from_date >> to_date;
            std::cout << number_people_born_between(from_date, to_date) << std::endl;
        } else if (command == "MAX_UNRELATED_PEOPLE") {
            std::cout << max_unrelated_people() << std::endl;
        }
    }

    return 0;
}