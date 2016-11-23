//
// Created by Alex on 23/11/2016.
//

#ifndef VISITORPATTERN_ASTAVERAGE_HH
#define VISITORPATTERN_ASTAVERAGE_HH

#include <string>
#include "ASTOperation.hh"

class ASTAverage : public ASTOperation {
public:
    ASTAverage(const std::string &name) : name(name) {}

    const std::string &getName() const {
        return name;
    }

    std::shared_ptr<VisitorResult> accept(ASTVisitor *visitor) override {
        return visitor->visit(this);
    }

private:
    std::string name;
};

#endif //VISITORPATTERN_ASTAVERAGE_HH
