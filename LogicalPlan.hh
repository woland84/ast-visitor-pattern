//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_LOGICALPLAN_HH
#define VISITORPATTERN_LOGICALPLAN_HH

#include <memory>
#include "LogicalOperation.hh"
#include "LogicalJoin.hh"
#include "LogicalFilter.hh"

class LogicalPlan : public VisitorResult {

public:
    LogicalPlan() {}

    LogicalPlan(const std::shared_ptr<LogicalOperation> &logicalOp, const std::shared_ptr<LogicalJoin> &logicalJoin,
                std::shared_ptr<LogicalFilter> logicalFilter)
            : logicalOp(logicalOp), logicalJoin(logicalJoin), logicalFilter(logicalFilter) {}

    const std::shared_ptr<LogicalOperation> &getLogicalOp() const {
        return logicalOp;
    }

    const std::shared_ptr<LogicalJoin> &getLogicalJoin() const {
        return logicalJoin;
    }

    const std::shared_ptr<LogicalFilter> &getLogicalFilter() const {
        return logicalFilter;
    }

private:
    std::shared_ptr<LogicalOperation> logicalOp;
    std::shared_ptr<LogicalJoin> logicalJoin;
    std::shared_ptr<LogicalFilter> logicalFilter;
};

#endif //VISITORPATTERN_LOGICALPLAN_HH
