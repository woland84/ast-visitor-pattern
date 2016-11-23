= AST Visitor pattern with return types =
Just an example of how one can apply the visitor pattern in C++ to an AST in order to translate it to some other data structure.
In this example, our aim is to translate the AST tree to a Logical Plan. 
Check ASTVisitor.hh, ASTNode.hh, VisitorResult.hh and ConcreteVisitor.hh for a basic structure