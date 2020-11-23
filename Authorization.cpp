//
// Created by ViPhilStar.
//

#include "Authorization.h"

const User *Authorization::getUser() const {
    if (!loggedIn) {
        throw std::logic_error("Not logged in.");
    }
    return user.get();
}

void Authorization::registration(const Credentials &credentials, DB &db) {
    if (loggedIn) {
        throw std::logic_error("Already logged in.");
    }
    std::shared_ptr<User> existingUser = db.findUserByNickname(credentials.nickname);
    if (existingUser != nullptr) {
        throw std::logic_error("User already exists!");
    }
    std::shared_ptr<User> tempUser = std::make_shared<User>(credentials);
    this->user = tempUser;
    this->loggedIn = true;
    db.insertUser(tempUser);
}

void Authorization::login(const Credentials &credentials, DB &db) {
    if (loggedIn) {
        throw std::logic_error("Already logged in.");
    }
    std::shared_ptr<User> tempUser = db.findUserByCredentials(credentials);
    if (tempUser == nullptr) {
        throw std::logic_error("Invalid login or password!");
    }
    this->user = tempUser;
    this->loggedIn = true;
}

void Authorization::logout() {
    this->user = nullptr;
    this->loggedIn = false;
}

