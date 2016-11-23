//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_ASTHEADER_HH
#define VISITORPATTERN_ASTHEADER_HH

#include <memory>
#include "ASTNode.hh"
#include "ASTOperation.hh"

class ASTWhere : public ASTNode {
public:
    ASTWhere(const std::shared_ptr<ASTOperation> &filterOperation) : filterOperation(filterOperation) {};

    const std::shared_ptr<ASTOperation> &getFilterOperation() const {
        return filterOperation;
    }

    std::shared_ptr<VisitorResult> accept(ASTVisitor *visitor) override {
        return visitor->visit(this);
    }

private:
    std::shared_ptr<ASTOperation> filterOperation;
};

#endif //VISITORPATTERN_ASTHEADER_HH
