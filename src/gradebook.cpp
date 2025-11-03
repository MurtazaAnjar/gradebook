#include "gradebook.h"
#include <string>
#include <vector>
#include <algorithm>


void Gradebook::add_student(const std::string &first_name, const std::string &last_name, const std::string &id) {
    students.push_back(Student(first_name, last_name, id));
    grades.push_back(std::vector<double>(assignments.size(), -1));
}

void Gradebook::add_assignment(const std::string &assignmentName, double pointsPossible) {
    assignments.push_back(Assignment(assignmentName, pointsPossible));
    for (auto &row : grades) {
        row.push_back(-1);
    }
}

void Gradebook::enter_grade(const std::string &id, const std::string &assignmentName, const double grade) {
    int studentIndex = -1, assignmentIndex = -1;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            studentIndex = i;
        }
    }
    for (int j = 0; j < assignments.size(); j++) {
        if (assignments[j].getAssignmentName() == assignmentName) {
            assignmentIndex = j;
        }
    }
    if (studentIndex != -1 && assignmentIndex != -1) {
        grades[studentIndex][assignmentIndex] = grade;
    }
}

std::string Gradebook::report() const{
    std::string output;
    output += "Last_Name,First_Name,Student_Id";
    for (const auto &a : assignments) {
        output += "," + a.getAssignmentName();
    }
    output += "\n";

    // Rows for each student
    for (int i = 0; i < students.size(); ++i) {
        const auto &s = students[i];
        output += s.getLastName() + "," + s.getFirstName() + "," + s.getId();

        for (int j = 0; j < assignments.size(); ++j) {
            double grade = grades[i][j];
            if (grade >= 0)
                output += "," + std::to_string(static_cast<int>(grade));
            else
                output += ",NA";
        }

        output += "\n";
    }

    return output;
}
