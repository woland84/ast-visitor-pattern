//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_LOGICALJOIN_HH
#define VISITORPATTERN_LOGICALJOIN_HH

#include <vector>
#include <string>
#include "VisitorResult.hh"

class LogicalJoin : public VisitorResult {
public:
    LogicalJoin() {}

    const std::vector<std::string> &getCollections() const {
        return collections;
    }

    void setCollections(const std::vector<std::string> &collections) {
        LogicalJoin::collections = collections;
    }

private:
    std::vector<std::string> collections;
};

#endif //VISITORPATTERN_LOGICALJOIN_HH
