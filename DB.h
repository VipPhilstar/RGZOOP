//
// Created by ViPhilStar.
//

#pragma once

#include <vector>
#include <string>
#include <memory>
#include <functional>
#include <algorithm>

#include "User.h"
#include "Credentials.h"

class DB {
public:
    void insertUser(const User &user);

    User *findUserByNickname(const std::string &nickname);

    User *findUserByCredentials(const Credentials &credentials);

    User *findUserById(const std::string &id);

    void updateUser(const std::string &id, const std::function<void(User &)> &transformation);

    void deleteUser(const std::string &id);

private:
    std::vector<User> users;
    std::vector<User> records;
    std::vector<User> comments;
};
