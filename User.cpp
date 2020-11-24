//
// Created by ViPhilStar.
//

#include "User.h"

extern DB db;

const std::string &User::getNickname() const {
    return nickname;
}

const std::string &User::getId() const {
    return id;
}

std::vector<std::shared_ptr<Record>> User::getRecords(int skip, int limit) const {
    if (records.size() < skip) {
        throw std::logic_error("Limit is wrong");
    }
    auto start = records.begin() + skip;
    auto end = records.size() < skip + limit ? records.end() : start + limit;
    return std::vector<std::shared_ptr<Record>>(start, end);
}

void User::addRecord(const Record &record) {
    auto tempRecord = std::make_shared<Record>(record);
    db.insertRecord(tempRecord);
    records.push_back(tempRecord);
}

void User::changeCanCommentRecord(const std::string &id, bool newValue) {
    auto it = std::find_if(records.begin(), records.end(),
                           [&id](std::shared_ptr<Record> &record) { return record->getId() == id; });
    if (it == records.end()) {
        throw std::logic_error("Not found");
    }
    (*it)->setCommentsAllowed(newValue);
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "nickname: " << user.nickname << "; id: " << user.id;
    return os;
}

bool User::checkCredentials(const Credentials &credentials) const {
    return this->password == credentials.password && this->nickname == credentials.nickname;
}

User::User(const Credentials &c, std::string interests, std::string mail, std::string phone, std::string birthday,
           std::string info) : nickname(c.nickname), password(c.password), interests(std::move(interests)),
                               mail(std::move(mail)),
                               phone(std::move(phone)), birthday(std::move(birthday)), info(std::move(info)) {
    this->id = std::to_string(random());
}


