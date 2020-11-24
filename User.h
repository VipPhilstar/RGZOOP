//
// Created by ViPhilStar.
//

#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include "Credentials.h"
#include "Record.h"

class User;

#include "DB.h"

class User {
    std::string id;
    std::string nickname;
    std::string password;
    std::string interests = "";
    std::string mail = "";
    std::string phone = "";
    std::string birthday = "";
    std::string info = "";
    std::vector<std::shared_ptr<Record>> records;
public:
    explicit User(const Credentials &c, std::string interests = "", std::string mail = "", std::string phone = "",
                  std::string birthday = "",
                  std::string info = "");

    const std::string &getNickname() const;

    const std::string &getId() const;

    std::vector<std::shared_ptr<Record>> getRecords(int skip, int limit) const;

    void addRecord(const Record &record);

    bool checkCredentials(const Credentials &credentials) const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);

};
