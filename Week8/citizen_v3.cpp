//C++ 
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

struct Person {
    std::string code;
    std::string date_of_birth;
    std::string father_code;
    std::string mother_code;
    char is_alive;
    std::string region_code;
};

// Function to calculate the generation distance between two people
int calculate_generation_distance(const Person& person, const std::map<std::string, Person>& database) {
    if (person.father_code == "0000000" || person.mother_code == "0000000") {
        return 1;
    }
    const Person& father = database.at(person.father_code);
    const Person& mother = database.at(person.mother_code);
    return std::max(calculate_generation_distance(father, database), calculate_generation_distance(mother, database)) + 1;
}

// Function to check if two people are unrelated (do not have father/mother-child relationship)
bool are_unrelated(const Person& person1, const Person& person2, const std::map<std::string, Person>& database) {
    if (person1.father_code == person2.code || person1.mother_code == person2.code || person2.father_code == person1.code || person2.mother_code == person1.code) {
        return false;
    }
    if (person1.father_code != "0000000" && !are_unrelated(database.at(person1.father_code), person2, database)) {
        return false;
    }
    if (person1.mother_code != "0000000" && !are_unrelated(database.at(person1.mother_code), person2, database)) {
        return false;
    }
    if (person2.father_code != "0000000" && !are_unrelated(person1, database.at(person2.father_code), database)) {
        return false;
    }
    if (person2.mother_code != "0000000" && !are_unrelated(person1, database.at(person2.mother_code), database)) {
        return false;
    }
    return true;
}

// Function to find the maximal subset of unrelated people
int find_max_unrelated_people(const std::map<std::string, Person>& database) {
    int max_subset_size = 0;
    for (const auto& entry1 : database) {
        const Person& person1 = entry1.second;
        int subset_size = 1;
        for (const auto& entry2 : database) {
            const Person& person2 = entry2.second;
            if (person1.code != person2.code && are_unrelated(person1, person2, database)) {
                subset_size++;
            }
        }
        max_subset_size = std::max(max_subset_size, subset_size);
    }
    return max_subset_size;
}

// Function to process the queries
std::vector<int> process_queries(const std::map<std::string, Person>& database, const std::vector<std::string>& queries) {
    std::vector<int> results;
    for (const std::string& query : queries) {
        std::istringstream iss(query);
        std::string command;
        iss >> command;
        if (command == "NUMBER_PEOPLE") {
            results.push_back(database.size());
        } else if (command == "NUMBER_PEOPLE_BORN_AT") {
            std::string date;
            iss >> date;
            int count = std::count_if(database.begin(), database.end(), [&date](const auto& entry) {
                return entry.second.date_of_birth == date;
            });
            results.push_back(count);
        } else if (command == "MOST_ALIVE_ANCESTOR") {
            std::string code;
            iss >> code;
            const Person& person = database.at(code);
            int generation_distance = calculate_generation_distance(person, database) - 1;
            results.push_back(generation_distance);
        } else if (command == "NUMBER_PEOPLE_BORN_BETWEEN") {
            std::string from_date, to_date;
            iss >> from_date >> to_date;
            int count = std::count_if(database.begin(), database.end(), [&from_date, &to_date](const auto& entry) {
                return entry.second.date_of_birth >= from_date && entry.second.date_of_birth <= to_date;
            });
            results.push_back(count);
        } else if (command == "MAX_UNRELATED_PEOPLE") {
            int max_unrelated_people = find_max_unrelated_people(database);
            results.push_back(max_unrelated_people);
        }
    }
    return results;
}

int main() {
    std::map<std::string, Person> database;
    std::vector<std::string> queries;

    // Read the input
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "*") {
            break;
        }
        std::istringstream iss(line);
        Person person;
        iss >> person.code >> person.date_of_birth >> person.father_code >> person.mother_code >> person.is_alive >> person.region_code;
        database[person.code] = person;
    }
    while (std::getline(std::cin, line)) {
        if (line == "***") {
            break;
        }
        queries.push_back(line);
    }

    // Process the queries
    std::vector<int> results = process_queries(database, queries);

    // Output the results
    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}