//
// Created by ViPhilStar.
//

#include "DB.h"

void DB::insertUser(const User &user) {
    users.push_back(user);
}

User *DB::findUserByNickname(const std::string &nickname) {
    auto it = std::find_if(users.begin(), users.end(),
                           [&nickname](User &user) { return user.getNickname() == nickname; });
    if (it != users.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

User *DB::findUserById(const std::string &id) {
    auto it = std::find_if(users.begin(), users.end(), [&id](User &user) { return user.getId() == id; });
    if (it != users.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

User *DB::findUserByCredentials(const Credentials &credentials) {
    auto it = std::find_if(users.begin(), users.end(),
                           [&credentials](User &user) { return user.checkCredentials(credentials); });
    if (it != users.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

void DB::updateUser(const std::string &id, const std::function<void(User &)> &transformation) {
    User *userToUpdate = findUserById(id);
    transformation(*userToUpdate);
}

void DB::deleteUser(const std::string &id) {
    auto it = users.erase(std::remove_if(users.begin(), users.end(), [&id](User &user) { return user.getId() == id; }),
                          users.end());
}

