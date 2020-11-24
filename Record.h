//
// Created by ViPhilStar.
//

#pragma once

#include <string>
#include <utility>
#include <ostream>

class Record {
    bool commentsAllowed = true;
    std::string id;
    std::string title;
public:
    bool isCommentsAllowed() const;

    explicit Record(std::string title);

    friend std::ostream &operator<<(std::ostream &os, const Record &record);

public:
    const std::string &getId() const;
};
