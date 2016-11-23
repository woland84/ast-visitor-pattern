//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_ASTSELECT_HH
#define VISITORPATTERN_ASTSELECT_HH

#include <memory>
#include "ASTNode.hh"
#include "ASTFrom.hh"
#include "ASTWhere.hh"

class ASTSelect : public ASTNode {
public:
    ASTSelect(const std::shared_ptr<ASTFrom> &from, const std::shared_ptr<ASTWhere> &where,
              const std::shared_ptr<ASTOperation> &operation) : from(from), where(where), operation(operation) {};

    const std::shared_ptr<ASTFrom> &getFrom() const {
        return from;
    }

    const std::shared_ptr<ASTWhere> &getWhere() const {
        return where;
    }

    const std::shared_ptr<ASTOperation> &getOperation() const {
        return operation;
    }

    std::shared_ptr<VisitorResult> accept(ASTVisitor *visitor) override {
        return visitor->visit(this);
    }

private:
    std::shared_ptr<ASTFrom> from;
    std::shared_ptr<ASTWhere> where;
    std::shared_ptr<ASTOperation> operation;
};

#endif //VISITORPATTERN_ASTSELECT_HH
