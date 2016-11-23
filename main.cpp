#include <iostream>
#include <memory>
#include "ASTSelect.hh"
#include "ConcreteVisitor.hh"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<ASTCollectionIdentifier> cols{ASTCollectionIdentifier("mr"), ASTCollectionIdentifier("rgb")};
    ASTSelect select(std::make_shared<ASTFrom>(cols),
                     std::make_shared<ASTWhere>(std::make_shared<ASTAverage>("Some other")),
                     std::make_shared<ASTAverage>("Some name"));
    auto visitorResult = std::static_pointer_cast<LogicalPlan>(ConcreteVisitor().visit(&select));
    for (auto &col: visitorResult->getLogicalJoin()->getCollections()) {
        std::cout << col << std::endl;
    }
    std::cout << std::static_pointer_cast<LogicalAverage>(visitorResult->getLogicalFilter()->getOperation())->getValue()
              << std::endl
              << std::static_pointer_cast<LogicalAverage>(visitorResult->getLogicalOp())->getValue()
              << std::endl;

    return 0;
}