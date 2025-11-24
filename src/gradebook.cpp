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
    output += ",Average\n";

    // Rows for each student
    for (int i = 0; i < students.size(); ++i) {
        const auto &s = students[i];
        output += s.getLastName() + "," + s.getFirstName() + "," + s.getId();

        double earned = 0, possible = 0;

        for (int j = 0; j < assignments.size(); ++j) {
            double grade = grades[i][j];
            if (grade >= 0) {
                output += "," + std::to_string(static_cast<int>(grade));
                earned += grade;
                possible += assignments[j].getPointsPossible();
            }else{
                output += ",NA";
            }
        }

        // Compute average
        if (possible == 0) {
            output += ",none";
        } else {
            double avg = (earned / possible) * 100.0;
            output += "," + std::to_string(avg);
        }

        output += "\n";
    }

    return output;
}

std::string Gradebook::assignment_report(const std::string &assignmentName) const {
    int assignmentIndex = -1;

    // Find assignment by name
    for (int j = 0; j < assignments.size(); ++j) {
        if (assignments[j].getAssignmentName() == assignmentName) {
            assignmentIndex = j;
            break;
        }
    }

    if (assignmentIndex == -1) {
        return "Assignment not found\n";
    }

    double possible = assignments[assignmentIndex].getPointsPossible();

    std::string output = "Last_Name,First_Name,Student_Id,Score\n";
    double earnedTotal = 0;
    int count = 0;
    for (int i = 0; i < students.size(); ++i) {
        const Student &s = students[i];
        output += s.getLastName() + "," + s.getFirstName() + "," + s.getId();
        double grade = grades[i][assignmentIndex];
        if (grade >= 0) {
            output += "," + std::to_string((int)grade);
            earnedTotal += grade;
            count += 1;
        } else {
            output += ",none";
        }
        output += "\n";
    }

    // Average calculation
    if (count == 0) {
        output += "Average score: none / " + std::to_string((int)possible);
    } else {
        double avg = earnedTotal / count;
        output += "Average score: " + std::to_string(avg) +
                  " / " + std::to_string((int)possible);
    }

    return output;
}