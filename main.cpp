//
// Created by ViPhilStar.
//

#include <iostream>
#include <string>
#include "DB.h"
#include "User.h"
#include "Authorization.h"

using namespace std;
DB db;

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

void printComments(const vector<shared_ptr<Comment>> &comments) {
    for (auto &comment: comments) {
        cout << "comment> " << *comment << endl;
    }
}

string addRecord(const string &title, const Authorization &auth) {
    Record tempRecord(title);
    auth.getUser()->addRecord(tempRecord);
    return tempRecord.getId();
}

string addComment(const string &title, const string &id) {
    Comment tempComment(title);
    auto record = db.findRecordById(id);
    record->addComment(tempComment);
    return tempComment.getId();
}


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
        addComment("C1", rId);
        auth.getUser()->changeCanCommentRecord(rId, false);
        try {
            addComment("C2", rId);
            addComment("C3", rId);
        } catch (const logic_error &ex) {
            cout << ex.what() << endl;
        }
        auto record = db.findRecordById(rId);
        printComments(db.getComments(rId, 0, 10));

//        auto records = auth.getUser()->getRecords(0, 10);
//        printRecords(records);
    } catch (const exception &ex) {
        cout << "error> " << ex.what() << endl;
    }
    return 0;
}
