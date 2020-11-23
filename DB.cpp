//
// Created by ViPhilStar.
//

#include "DB.h"

void DB::insertUser(std::shared_ptr<User> &user) {
    users.push_back(user);
}


std::shared_ptr<User> DB::findUserByNickname(const std::string &nickname) {
    auto it = std::find_if(users.begin(), users.end(),
                           [&nickname](std::shared_ptr<User> &user) { return user->getNickname() == nickname; });
    if (it != users.end()) {
        return (*it);
    } else {
        return nullptr;
    }
}

std::shared_ptr<User> DB::findUserById(const std::string &id) {
    auto it = std::find_if(users.begin(), users.end(),
                           [&id](std::shared_ptr<User> &user) { return user->getId() == id; });
    if (it != users.end()) {
        return (*it);
    } else {
        return nullptr;
    }
}

std::shared_ptr<User> DB::findUserByCredentials(const Credentials &credentials) {
    auto it = std::find_if(users.begin(), users.end(),
                           [&credentials](std::shared_ptr<User> &user) { return user->checkCredentials(credentials); });
    if (it != users.end()) {
        return (*it);
    } else {
        return nullptr;
    }
}

void DB::updateUser(const std::string &id, const std::function<void(User &)> &transformation) {
    std::shared_ptr<User> userToUpdate = findUserById(id);
    transformation(*userToUpdate);
}

void DB::deleteUser(const std::string &id) {
    auto it = users.erase(std::remove_if(users.begin(), users.end(),
                                         [&id](std::shared_ptr<User> &user) { return user->getId() == id; }),
                          users.end());
}

std::vector<std::shared_ptr<User>> DB::getUsers(int skip, int limit) const {
    if (users.size() < skip + limit) {
        throw std::logic_error("Limit is wrong");
    }
    auto start = users.begin() + skip;
    auto end = start + limit;
    return std::vector<std::shared_ptr<User>>(start, end);
}

