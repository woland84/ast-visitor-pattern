//
// Created by Alex on 23/11/2016.
//

#ifndef VISITORPATTERN_LOGICALAVERAGE_HH
#define VISITORPATTERN_LOGICALAVERAGE_HH

#include <string>
#include "VisitorResult.hh"

class LogicalAverage : public LogicalOperation {
public:
    LogicalAverage(const std::string &value) : value(value) {}

    const std::string &getValue() const {
        return value;
    }

private:
    std::string value;
};

#endif //VISITORPATTERN_LOGICALAVERAGE_HH
