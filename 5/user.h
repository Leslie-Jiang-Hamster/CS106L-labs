#include <set>
#include <string>

class User {
public:
    User() = default;
    User(std::string name);
    User(const User& other);
    User(User&& other);
    User operator=(User&& other);

    // getter functions
    std::string getName() const;
    std::set<User>& getFriends();
    const std::set<User>& getFriends() const;

    // setter functions
    void setName(std::string name);

    bool operator<(const User& other) const;
    
private:
    std::string name;
    std::set<User> friends;
};
