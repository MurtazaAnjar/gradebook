#include "assignment.h"

Assignment::Assignment(std::string assignmentName, double pointsPossible) : assignmentName(assignmentName), pointsPossible(pointsPossible) {}

std::string Assignment::getAssignmentName() const{
    return this->assignmentName;
}

double Assignment::getPointsPossible() const{
    return this->pointsPossible;
}