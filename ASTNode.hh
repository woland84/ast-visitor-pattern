//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_ASTNODE_HH
#define VISITORPATTERN_ASTNODE_HH

#include <memory>
#include "VisitorResult.hh"
#include "ASTVisitor.hh"

class ASTNode {
public:
    virtual std::shared_ptr<VisitorResult> accept(ASTVisitor *visitor) = 0;
};

#endif //VISITORPATTERN_ASTNODE_HH
