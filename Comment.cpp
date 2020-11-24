//
// Created by ViPhilStar.
//

#include "Comment.h"

const std::string &Comment::getId() const {
    return id;
}

void Comment::setTitle(const std::string &title) {
    this->title = title;
}

std::ostream &operator<<(std::ostream &os, const Comment &comment) {
    os << "title: " << comment.title << "; id: " << comment.id;
    return os;
}

Comment::Comment(std::string title) : title(std::move(title)) {
    this->id = std::to_string(random());
}
