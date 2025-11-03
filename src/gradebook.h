#ifndef HELLO_WORLD_GRADEBOOK_H
#define HELLO_WORLD_GRADEBOOK_H
#include "student.h"
#include "assignment.h"
#include <vector>


class Gradebook {
    private:
    std::vector<Student> students;
    std::vector<Assignment> assignments;
    std::vector<std::vector<double>> grades;

public:
    void add_student(const std::string &firstName, const std::string &lastName, const std::string &id);
    void add_assignment(const std::string &name, double pointsPossible);
    void enter_grade(const std::string &id, const std::string &assignment_name, double grade);
    std::string report() const;
};

#endif