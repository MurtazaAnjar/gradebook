#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/assignment.h"

TEST_CASE("Assignment constructor initializes correctly") {
    Assignment a("Quiz 1", 100.0);

    REQUIRE(a.getAssignmentName() == "Quiz 1");
    REQUIRE(a.getPointsPossible() == 100.0);
}

TEST_CASE("Multiple assignments are independent") {
    Assignment a1("Lab 1", 50.0);
    Assignment a2("Project", 200.0);

    REQUIRE(a1.getAssignmentName() == "Lab 1");
    REQUIRE(a2.getAssignmentName() == "Project");
    REQUIRE(a1.getPointsPossible() == 50.0);
    REQUIRE(a2.getPointsPossible() == 200.0);
    REQUIRE(a1.getAssignmentName() != a2.getAssignmentName());
    REQUIRE(a1.getPointsPossible() != a2.getPointsPossible());
}

TEST_CASE("Assignments handle zero or fractional points correctly") {
    Assignment a1("Extra Credit", 0.0);
    Assignment a2("Half Quiz", 12.5);

    REQUIRE(a1.getPointsPossible() == 0.0);
    REQUIRE(a2.getPointsPossible() == 12.5);
    REQUIRE(a1.getAssignmentName() == "Extra Credit");
    REQUIRE(a2.getAssignmentName() == "Half Quiz");
}

TEST_CASE("Assignment getters do not modify object state") {
    const Assignment a("Final Exam", 150.0);
    REQUIRE(a.getAssignmentName() == "Final Exam");
    REQUIRE(a.getPointsPossible() == 150.0);
}