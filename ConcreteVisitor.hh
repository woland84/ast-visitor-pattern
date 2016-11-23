//
// Created by Alex on 23/11/2016.
//

#ifndef VISITORPATTERN_CONCRETEVISITOR_HH
#define VISITORPATTERN_CONCRETEVISITOR_HH

#include "ASTVisitor.hh"
#include "ASTFrom.hh"
#include "ASTWhere.hh"
#include "ASTOperation.hh"
#include "ASTSelect.hh"
#include "ASTAverage.hh"
#include "LogicalOperation.hh"
#include "LogicalFilter.hh"
#include "LogicalJoin.hh"
#include "LogicalPlan.hh"
#include "LogicalAverage.hh"


class ConcreteVisitor : public ASTVisitor {
public:
    std::shared_ptr<VisitorResult> visit(ASTFrom *from) override {
        auto lj = std::make_shared<LogicalJoin>();
        std::vector<std::string> colls;
        for (auto &coll: from->getCollections()) {
            colls.push_back(coll.getName());
        }
        lj->setCollections(colls);
        return lj;
    }

    std::shared_ptr<VisitorResult> visit(ASTWhere *where) override {
        auto lop = std::static_pointer_cast<LogicalOperation>(where->getFilterOperation()->accept(this));
        return std::make_shared<LogicalFilter>(lop);
    }

    std::shared_ptr<VisitorResult> visit(ASTOperation *operation) override {
        return std::make_shared<LogicalOperation>();
    }

    std::shared_ptr<VisitorResult> visit(ASTSelect *select) override {
        auto logicalFilter = std::static_pointer_cast<LogicalFilter>(select->getWhere()->accept(this));
        auto logicalJoin = std::static_pointer_cast<LogicalJoin>(select->getFrom()->accept(this));
        auto logicalOp = std::static_pointer_cast<LogicalOperation>(select->getOperation()->accept(this));
        auto logicalPlan = std::make_shared<LogicalPlan>(logicalOp, logicalJoin, logicalFilter);
        return logicalPlan;
    }

    std::shared_ptr<VisitorResult> visit(ASTAverage *average) override {
        return std::make_shared<LogicalAverage>(average->getName());
    }
};

#endif //VISITORPATTERN_CONCRETEVISITOR_HH
