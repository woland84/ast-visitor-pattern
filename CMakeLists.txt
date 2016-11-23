cmake_minimum_required(VERSION 3.6)
project(VisitorPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ASTNode.hh ASTSelect.hh ASTFrom.hh ASTWhere.hh ASTOperation.hh ASTCollectionIdentifier.hh LogicalPlan.hh LogicalOperation.hh VisitorResult.hh LogicalJoin.hh ASTVisitor.hh ASTAverage.hh ConcreteVisitor.hh LogicalFilter.hh LogicalAverage.hh)
add_executable(VisitorPattern ${SOURCE_FILES})