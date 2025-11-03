#include <iostream>
#include "src/gradebook.h"

int main() {
    Gradebook gradebook;

    gradebook.add_student("Bob", "Bobberson", "ABC123");
    gradebook.add_student("Sam", "Sammerson", "DEF456");
    gradebook.add_student("Jess", "Jesserson", "HIJ789");

    gradebook.add_assignment("Quiz_1", 100);
    gradebook.add_assignment("Lab_1", 50);

    gradebook.enter_grade("ABC123", "Quiz_1", 85);
    gradebook.enter_grade("ABC123", "Lab_1", 0);
    gradebook.enter_grade("HIJ789", "Quiz_1", 93);
    gradebook.enter_grade("HIJ789", "Lab_1", 49);
    gradebook.enter_grade("DEF456", "Quiz_1", 95);

    std::cout << gradebook.report();

    return 0;
}