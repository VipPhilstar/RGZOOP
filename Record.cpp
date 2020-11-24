//
// Created by ViPhilStar.
//

#include "Record.h"

const std::string &Record::getId() const {
    return id;
}

bool Record::isCommentsAllowed() const {
    return commentsAllowed;
}

Record::Record(std::string title) : title(std::move(title)) {
    this->id = std::to_string(random());
}

std::ostream &operator<<(std::ostream &os, const Record &record) {
    os << "title: " << record.id << "; id: " << record.id;
    return os;
}

