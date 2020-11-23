//
// Created by ViPhilStar.
//

#pragma once

#include "User.h"
#include "Credentials.h"
#include "DB.h"
#include <exception>

class Authorization {
public:
    const User *getUser() const;

    void login(const Credentials &credentials, DB &db);

    void logout();

    void registration(const Credentials &credentials, DB &db);

    bool loggedIn = false;
    std::shared_ptr<User> user = nullptr;
private:
};
