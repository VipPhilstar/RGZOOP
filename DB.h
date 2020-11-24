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
#include "Record.h"

class DB {
    std::vector<std::shared_ptr<User>> users;
    std::vector<std::shared_ptr<Record>> records;
//    std::vector<User> comments;
public:
    void insertUser(std::shared_ptr<User> &user);

    void insertRecord(std::shared_ptr<Record> &record);

    std::shared_ptr<User> findUserByNickname(const std::string &nickname);

    std::shared_ptr<User> findUserByCredentials(const Credentials &credentials);

    std::shared_ptr<User> findUserById(const std::string &id);

    std::shared_ptr<Record> findRecordById(const std::string &id);

    std::vector<std::shared_ptr<User>> getUsers(int skip = 0, int limit = 10) const;

    std::vector<std::shared_ptr<Record>> getRecords(const std::string &id, int skip = 0, int limit = 10);

    void updateUser(const std::string &id, const std::function<void(User &)> &transformation);

    void updateRecord(const std::string &id, const std::function<void(Record &)> &transformation);

    void deleteUser(const std::string &id);
};
