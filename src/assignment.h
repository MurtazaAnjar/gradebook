#ifndef HELLO_WORLD_ASSIGNMENT_H
#define HELLO_WORLD_ASSIGNMENT_H

#include <string>

class Assignment {
private:
    std::string assignmentName;
    double pointsPossible;

public:
    Assignment(std::string assignmentName, double pointsPossible);
    std::string getAssignmentName() const;
    double getPointsPossible() const;
};

#endif //HELLO_WORLD_ASSIGNMENT_H