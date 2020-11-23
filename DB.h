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
    void insertUser(std::shared_ptr<User> &user);

    std::shared_ptr<User> findUserByNickname(const std::string &nickname);

    std::shared_ptr<User> findUserByCredentials(const Credentials &credentials);

    std::shared_ptr<User> findUserById(const std::string &id);

    std::vector<std::shared_ptr<User>> getUsers(int skip = 0, int limit = 10) const;

    void updateUser(const std::string &id, const std::function<void(User &)> &transformation);

    void deleteUser(const std::string &id);

private:
    std::vector<std::shared_ptr<User>> users;
    std::vector<User> records;
    std::vector<User> comments;
};
