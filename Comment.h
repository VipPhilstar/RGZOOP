//
// Created by ViPhilStar.
//

#pragma once

#include <string>
#include <utility>
#include <ostream>

class Comment {
    std::string id;
    std::string title;
public:

    void setTitle(const std::string &title);

    explicit Comment(std::string title);

    friend std::ostream &operator<<(std::ostream &os, const Comment &comment);

    const std::string &getId() const;

public:
};
