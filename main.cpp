//
// Created by ViPhilStar.
//

#include <iostream>
#include <string>
#include "DB.h"
#include "User.h"
#include "Authorization.h"

using namespace std;

void printCurrentUser(Authorization &auth) {
    try {
        User *user = auth.getUser();
        cout << "user> " << *user << endl;
    } catch (const exception &ex) {
        cout << "status> " << ex.what() << endl;
    }
}

void printUsers(const vector<shared_ptr<User>> &users) {
    for (auto &user: users) {
        cout << *user << endl;
    }
}

DB db;

int main() {
    setlocale(LC_ALL, "rus");
    Authorization auth;
    try {
        auth.registration({"Phil", "password"});
//        printCurrentUser(auth);
        auto users = db.getUsers(0, 3);
        printUsers(users);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
