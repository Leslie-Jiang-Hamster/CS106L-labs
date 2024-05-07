/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

auto get_applicants(std::string filename) {
    std::set<std::string> students;
    std::string name;
    std::ifstream ifs{filename};

    if (!ifs.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
    }
    while (std::getline(ifs, name)) {
        students.insert(name);
        std::cout << name << std::endl;
    }
    ifs.close();

    return students;
}

using string_set_t = std::set<std::string>;
auto find_match(const string_set_t &students) {
    std::queue<string_set_t::const_iterator> matches_queue;

    auto pos = std::find_if(students.begin(), students.end(), [](const std::string &name) {
        return name.at(0) == 'L';
    });
    while (pos != students.end() && pos->at(0) == 'L') {
        matches_queue.push(pos);
        pos++;
    }

    std::srand(std::time(nullptr));
    while (!matches_queue.empty()) {
        auto name = *(matches_queue.front());
        matches_queue.pop();
        if (std::rand() % 4 == 0) {
            return name;
        }
    }

    return static_cast<std::string>("NO STUDENT FOUND");
}

int main() {
    // Your code goes here. Don't forget to print your true love!
    auto applicants = get_applicants("students.txt");
    std::cout << "True love: " << find_match(applicants) << std::endl;
    return 0;
}
