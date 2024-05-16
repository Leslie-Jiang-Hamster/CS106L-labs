#include "user.h"
#include <set>
#include <iostream>
#include <string>

User::User(std::string name) {
    this->name = name;
    this->friends = std::set<User>{};
}

User::User(const User& other) {
    this->name = other.name;
    this->friends = other.friends;
}

User::User(User&& other) {
    this->name = other.name;
    this->friends = std::move(other.friends);
}
User User::operator=(User&& other) {
    this->name = other.name;
    this->friends = std::move(other.friends);
    return *this;
}

std::string User::getName() const {
    return name;
}

std::set<User>& User::getFriends() {
    return friends;
}

// A const version is needed to allow read-only access to the friends set!
const std::set<User>& User::getFriends() const {
    return friends;
}

void User::setName(std::string name) {
    this->name = name;
}

bool User::operator<(const User& other) const {
    return this->getName() < other.getName();
}