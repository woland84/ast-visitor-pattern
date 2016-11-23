//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_ASTOPERATION_HH
#define VISITORPATTERN_ASTOPERATION_HH

#include "ASTNode.hh"

class ASTOperation : public ASTNode {
public:
    std::shared_ptr<VisitorResult> accept(ASTVisitor *visitor) override {
        return visitor->visit(this);
    }
};

#endif //VISITORPATTERN_ASTOPERATION_HH
