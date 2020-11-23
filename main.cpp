//
// Created by ViPhilStar.
//

#include <iostream>
#include <string>
#include "DB.h"
#include "User.h"
#include "Authorization.h"

using namespace std;

void getCurrentUser(Authorization &auth) {
    try {
        const User *user = auth.getUser();
        cout << "user> " << *user << endl;
    } catch (const exception &ex) {
        cout << "status> " << ex.what() << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    DB db;
    Authorization auth;

    try {
        auth.registeration({"Phil", "pass"}, db);
        getCurrentUser(auth);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
