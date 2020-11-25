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
        cout << "\tcomment> " << *comment << endl;
    }
}

string addRecord(User *user) {
    string title;
    cout << "Input record title: \n";
    cin >> title;
    Record tempRecord(title);
    user->addRecord(tempRecord);
    return tempRecord.getId();
}

void changeCommentRecord(User *user) {
    string id;
    cout << "Input record id: \n";
    cin >> id;
    bool currentState = db.findRecordById(id)->isCommentsAllowed();
    user->changeCanCommentRecord(id, !currentState);
}

string addComment(const string &title, const string &id) {
    Comment tempComment(title);
    auto record = db.findRecordById(id);
    record->addComment(tempComment);
    return tempComment.getId();
}

void clearConsole(int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\n";
    }
}

Credentials askCredentials() {
    string password;
    string nickname;
    cout << "Input nickname: \n";
    cin >> nickname;
    cout << "Input password: \n";
    cin >> password;
    return {nickname, password};
}

void printRecord(shared_ptr<Record> &record) {
    cout << "record>" << *record << "\n";
    printComments(record->getComments(0, 5));
}

void addComment(shared_ptr<Record> &record) {
    string title;
    cout << "Input title: \n";
    cin >> title;
    Comment tempComment(title);
    record->addComment(tempComment);
}

void recordState(Authorization &auth, shared_ptr<Record> &record) {
    int userInteractingState = 1;
    bool isNextClear = true;
    while (userInteractingState != -1) {
        if (isNextClear) {
            clearConsole(15);
        } else {
            isNextClear = true;
        }
        printRecord(record);
        cout
                << "Record Menu:\n(1) add comment\n(2) change comment permission\n(-1) exit\n";
        cin >> userInteractingState;
        try {
            switch (userInteractingState) {
                case 1:
                    addComment(record);
                    break;
                case 2:
                    changeCommentRecord(auth.getUser());
                    break;
                default:
                    if (userInteractingState != -1)
                        cout << "Wrong command\n";
            }
        } catch (const exception &ex) {
            clearConsole(15);
            cout << "error> " << ex.what() << endl;
            isNextClear = false;
            cout << "\n";
        }
    }
}

void userInteractingState(Authorization &auth) {
    int userInteractingState = 1;
    bool isNextClear = true;
    while (userInteractingState != -1) {
        if (isNextClear) {
            clearConsole(15);
        } else {
            isNextClear = true;
        }
        cout
                << "User Menu:\n(1) get records\n(2) add record\n(3) change comment permission\n(4) select record\n(-1) exit\n";
        cin >> userInteractingState;
        try {
            User *currentUser = auth.getUser();
            switch (userInteractingState) {
                case 1: {
                    auto records = currentUser->getRecords(0, 5);
                    clearConsole(15);
                    printRecords(records);
                    cout << "\n";
                    isNextClear = false;
                    break;
                }
                case 2:
                    addRecord(currentUser);
                    break;
                case 3:
                    changeCommentRecord(currentUser);
                    break;
                case 4: {
                    string id;
                    cout << "Input record id: \n";
                    cin >> id;
                    auto record = db.findRecordById(id);
                    recordState(auth, record);
                    break;
                }
                default:
                    if (userInteractingState != -1)
                        cout << "Wrong command\n";
            }
        } catch (const exception &ex) {
            clearConsole(15);
            cout << "error> " << ex.what() << endl;
            isNextClear = false;
            cout << "\n";
        }
    }
}

void authState(Authorization &auth) {
    int authState = 1;
    bool isNextClear = true;
    while (authState != -1) {
        if (isNextClear) {
            clearConsole(15);
        } else {
            isNextClear = true;
        }
        cout << "Main menu:\n(1) registration\n(2) login\n(3) logout\n(4) get current user logged in\n(-1) exit\n";
        cin >> authState;
        try {
            switch (authState) {
                case 1:
//                    auth.registration({"Phil", "password"});
                    auth.registration(askCredentials());
                    userInteractingState(auth);
                    break;
                case 2:
//                    auth.login({"Phil", "password"});
                    auth.login(askCredentials());
                    userInteractingState(auth);
                    break;
                case 3:
                    auth.logout();
                    break;
                case 4:
                    cout << auth.getUser();
                    break;
                default:
                    if (authState != -1)
                        cout << "Wrong command\n";
            }
        } catch (const exception &ex) {
            clearConsole(15);
            cout << "error> " << ex.what() << endl;
            isNextClear = false;
            cout << "\n";
        }
    }
    cout << "Exiting...";
}

int main() {
    setlocale(LC_ALL, "rus");
    Authorization auth;
    authState(auth);
    return 0;
}
