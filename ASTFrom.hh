//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_ASTFROM_HH
#define VISITORPATTERN_ASTFROM_HH

#include <memory>
#include <vector>
#include "ASTNode.hh"
#include "ASTCollectionIdentifier.hh"

class ASTFrom : public ASTNode {
public:
    ASTFrom(const std::vector<ASTCollectionIdentifier> &collections) : collections(collections) {}

    const std::vector<ASTCollectionIdentifier> &getCollections() const {
        return collections;
    }

    std::shared_ptr<VisitorResult> accept(ASTVisitor *visitor) override {
        return visitor->visit(this);
    }



private:
    std::vector<ASTCollectionIdentifier> collections;
};

#endif //VISITORPATTERN_ASTFROM_HH
