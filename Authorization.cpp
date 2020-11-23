//
// Created by ViPhilStar.
//

#include "Authorization.h"

const User *Authorization::getUser() const {
    if (!loggedIn) {
        throw std::logic_error("Not logged in.");
    }
    return user;
}

User Authorization::registeration(const Credentials &credentials, DB &db) {
    if (loggedIn) {
        throw std::logic_error("Already logged in.");
    }
    User *existingUser = db.findUserByNickname(credentials.nickname);
    if (existingUser != nullptr) {
        throw std::logic_error("User already exists!");
    }
    User tempUser(credentials);
    this->user = &tempUser;
    this->loggedIn = true;
    db.insertUser(tempUser);
    return tempUser;
}

const User * Authorization::login(const Credentials &credentials, DB &db) {
    if (loggedIn) {
        throw std::logic_error("Already logged in.");
    }
    User *tempUser = db.findUserByCredentials(credentials);
    if (tempUser == nullptr) {
        throw std::logic_error("Invalid login or password!");
    }
    this->user = tempUser;
    this->loggedIn = true;
    return tempUser;
}

void Authorization::logout() {
    this->user = nullptr;
    this->loggedIn = false;
}

