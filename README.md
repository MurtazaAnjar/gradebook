<<<<<<< HEAD
=======
# Gradebook (C++)

This project implements a simple **Gradebook** system that allows you to add students, add assignments, enter grades, and generate a report of all grades.

We will use [CMake][cmake] to build executables (e.g. tests, the driver program, the benchmarks, etc.). Additionally, we will use [Catch2][catch2] for unit testing and benchmarking.

---

## 📘 Features

- Add students (first name, last name, and ID)
- Add assignments with total points possible
- Record grades for each student and assignment
- Generate a grade report showing all students and their grades

Example usage in `main.cpp`:
```cpp
#include "gradebook.h"
#include <iostream>

int main() {
    Gradebook gradebook;

    gradebook.add_student("Bob", "Bobberson", "ABC123");
    gradebook.add_student("Sam", "Sammerson", "DEF456");
    gradebook.add_student("Jess", "Jesserson", "HIJ789");

    gradebook.add_assignment("Quiz 1", 100);
    gradebook.add_assignment("Homework 1", 50);

    gradebook.enter_grade("ABC123", "Quiz 1", 95);
    gradebook.enter_grade("DEF456", "Quiz 1", 88);
    gradebook.enter_grade("HIJ789", "Homework 1", 45);

    std::cout << gradebook.report() << std::endl;
}
>>>>>>> origin/main
