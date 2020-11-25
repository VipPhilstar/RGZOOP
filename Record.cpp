//
// Created by ViPhilStar.
//

#include "Record.h"

extern DB db;

const std::string &Record::getId() const {
    return id;
}

bool Record::isCommentsAllowed() const {
    return commentsAllowed;
}

Record::Record(std::string title) : title(std::move(title)) {
    this->id = std::to_string(random() % 9000 + 1000);
}

std::ostream &operator<<(std::ostream &os, const Record &record) {
    os << "title: " << record.title << "; id: " << record.id << "; canComment: " << record.commentsAllowed;
    return os;
}

void Record::setTitle(const std::string &title) {
    this->title = title;
}

void Record::setCommentsAllowed(bool commentsAllowed) {
    this->commentsAllowed = commentsAllowed;
}

std::vector<std::shared_ptr<Comment>> Record::getComments(int skip, int limit) const {
    if (comments.size() < skip) {
        throw std::logic_error("Limit is wrong");
    }
    auto start = comments.begin() + skip;
    auto end = comments.size() < skip + limit ? comments.end() : start + limit;
    return std::vector<std::shared_ptr<Comment>>(start, end);
}

void Record::addComment(const Comment &comment) {
    if (!commentsAllowed) {
        throw std::logic_error("Comment not allowed!");
    }
    auto tempComment = std::make_shared<Comment>(comment);
    db.insertComment(tempComment);
    comments.push_back(tempComment);
}

