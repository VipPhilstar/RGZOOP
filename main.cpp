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
        cout << "user> " << *user << endl;
    }
}

void printRecords(const vector<shared_ptr<Record>> &records) {
    for (auto &record: records) {
        cout << "record> " << *record << endl;
    }
}

string addRecord(const string &title, const Authorization &auth) {
    Record tempRecord(title);
    auth.getUser()->addRecord(tempRecord);
    return tempRecord.getId();
}

DB db;

int main() {
    setlocale(LC_ALL, "rus");
    Authorization auth;
    try {
        auth.registration({"Phil", "password"});
        auth.logout();
        auth.registration({"Bob", "password"});
        addRecord("R1", auth);
        addRecord("R2", auth);
        string rId = addRecord("R3", auth);
        auth.getUser()->changeCanCommentRecord(rId, false);
        auto records = auth.getUser()->getRecords(0, 10);
        printRecords(records);
//        printCurrentUser(auth);
        auto users = db.getUsers(0, 10);
        printUsers(users);
    } catch (const exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
