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
        const User *user = auth.getUser();
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

int main() {
    setlocale(LC_ALL, "rus");
    DB db;
    Authorization auth;

    try {
        auth.registration({"Phil", "password"}, db);
        auth.logout();
        auth.registration({"Bob", "password"}, db);
        auth.logout();
        auth.registration({"Den", "password"}, db);
        auth.logout();
//        printCurrentUser(auth);
        auto users = db.getUsers(0, 3);
        printUsers(users);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
