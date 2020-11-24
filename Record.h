//
// Created by ViPhilStar.
//

#pragma once

#include <string>
#include <utility>
#include <ostream>
#include <vector>
#include <memory>
#include "Comment.h"

class User;
class Record;

#include "DB.h"

class Record {
    bool commentsAllowed = true;
    std::string id;
    std::string title;
    std::vector<std::shared_ptr<Comment>> comments;
public:
    bool isCommentsAllowed() const;

    void setTitle(const std::string &title);

    void setCommentsAllowed(bool commentsAllowed);

    std::vector<std::shared_ptr<Comment>> getComments(int skip, int limit) const;

    void addComment(const Comment &comment);

    explicit Record(std::string title);

    friend std::ostream &operator<<(std::ostream &os, const Record &record);

public:
    const std::string &getId() const;
};
