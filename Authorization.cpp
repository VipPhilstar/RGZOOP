//
// Created by ViPhilStar.
//

#include "Authorization.h"

extern DB db;

User * Authorization::getUser() const {
    if (!loggedIn) {
        throw std::logic_error("Not logged in.");
    }
    return user.get();
}

void Authorization::registration(const Credentials &credentials) {
    if (loggedIn) {
        throw std::logic_error("Already logged in.");
    }
    try {
        std::shared_ptr<User> existingUser = db.findUserByNickname(credentials.nickname);
        throw std::logic_error("User already exists!");
    } catch (const std::logic_error &ex) {}
    auto tempUser = std::make_shared<User>(credentials);
    this->user = tempUser;
    this->loggedIn = true;
    db.insertUser(tempUser);
}

void Authorization::login(const Credentials &credentials) {
    if (loggedIn) {
        throw std::logic_error("Already logged in.");
    }
    try {
        std::shared_ptr<User> tempUser = db.findUserByCredentials(credentials);
        this->user = tempUser;
        this->loggedIn = true;
    } catch (const std::logic_error &ex) {
        throw std::logic_error("Invalid login or password!");
    }
}

void Authorization::logout() {
    this->user = nullptr;
    this->loggedIn = false;
}

