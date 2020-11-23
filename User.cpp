//
// Created by ViPhilStar.
//

#include "User.h"

const std::string &User::getNickname() const {
    return this->nickname;
}

const std::string &User::getId() const {
    return this->id;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "\n\tnickname: " << user.nickname << ";\tid: " << user.id;
    return os;
}

bool User::checkCredentials(const Credentials &credentials) const {
    return this->password == credentials.password && this->nickname == credentials.nickname;
}

void User::initId() {
    this->id = std::to_string(random());
}

User::User(const Credentials &c, std::string interests, std::string mail, std::string phone, std::string birthday,
           std::string info) : nickname(c.nickname), password(c.password), interests(std::move(interests)),
                               mail(std::move(mail)),
                               phone(std::move(phone)), birthday(std::move(birthday)), info(std::move(info)) {
    this->initId();
}
