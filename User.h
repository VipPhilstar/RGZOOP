//
// Created by ViPhilStar.
//

#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>
#include "Credentials.h"

class User {
public:
    User(const Credentials &c, std::string &interests, std::string &mail, std::string &phone, std::string &birthday,
         std::string &info);

    explicit User(const Credentials &credentials);

    const std::string &getNickname() const;

    const std::string &getId() const;

    bool checkCredentials(const Credentials &credentials) const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);

    void initId();

    std::string id;
    std::string nickname;
    std::string password;
    std::string interests = "";
    std::string mail = "";
    std::string phone = "";
    std::string birthday = "";
    std::string info = "";
};
