//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_ASTVISITOR_HH
#define VISITORPATTERN_ASTVISITOR_HH

#include <memory>
#include "VisitorResult.hh"

class ASTNode;

class ASTFrom;

class ASTOperation;

class ASTSelect;

class ASTWhere;

class ASTAverage;

class ASTVisitor {
public:
    virtual std::shared_ptr<VisitorResult> visit(ASTFrom *) = 0;

    virtual std::shared_ptr<VisitorResult> visit(ASTOperation *) = 0;

    virtual std::shared_ptr<VisitorResult> visit(ASTWhere *) = 0;

    virtual std::shared_ptr<VisitorResult> visit(ASTSelect *) = 0;

    virtual std::shared_ptr<VisitorResult> visit(ASTAverage *) = 0;

};

#endif //VISITORPATTERN_ASTVISITOR_HH
