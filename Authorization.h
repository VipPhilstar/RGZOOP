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

    const User *login(const Credentials &credentials, DB &db);

    void logout();

    User registeration(const Credentials &credentials, DB &db);

    bool loggedIn = false;
    User *user = nullptr;
private:
};
