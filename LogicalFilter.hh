//
// Created by Alex on 23/11/2016.
//

#ifndef VISITORPATTERN_LOGICALFILTER_HH
#define VISITORPATTERN_LOGICALFILTER_HH

#include <memory>
#include "VisitorResult.hh"
#include "LogicalOperation.hh"

class LogicalFilter : public VisitorResult {
public:
    LogicalFilter(const std::shared_ptr<LogicalOperation> &operation) : operation(operation) {}

    const std::shared_ptr<LogicalOperation> &getOperation() const {
        return operation;
    }

private:
    std::shared_ptr<LogicalOperation> operation;
};

#endif //VISITORPATTERN_LOGICALFILTER_HH
