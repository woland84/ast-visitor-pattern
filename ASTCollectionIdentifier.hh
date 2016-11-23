//
// Created by Alex on 22/11/2016.
//

#ifndef VISITORPATTERN_ASTCOLLECTIONIDENTIFIER_HH
#define VISITORPATTERN_ASTCOLLECTIONIDENTIFIER_HH

#include <string>

class ASTCollectionIdentifier {
public:
    ASTCollectionIdentifier(const std::string &name) : name(name) {}

    const std::string &getName() const {
        return name;
    }

private:
    std::string name;
};

#endif //VISITORPATTERN_ASTCOLLECTIONIDENTIFIER_HH
