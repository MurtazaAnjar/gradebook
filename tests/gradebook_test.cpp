#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/gradebook.h"

TEST_CASE("Adding students stores them correctly") {
    Gradebook g;
    g.add_student("Bob", "Bobberson", "ABC123");
    g.add_student("Sam", "Sammerson", "DEF456");

    // Report should contain both students
    std::string report = g.report();
    REQUIRE(report.find("Bobberson") != std::string::npos);
    REQUIRE(report.find("Sammerson") != std::string::npos);
}

TEST_CASE("Adding assignments updates all student grade slots") {
    Gradebook g;
    g.add_student("Jess", "Jesserson", "HIJ789");

    g.add_assignment("Quiz_1", 100);
    g.add_assignment("Lab_1", 50);

    std::string report = g.report();

    // Header should contain both assignments
    REQUIRE(report.find("Quiz_1") != std::string::npos);
    REQUIRE(report.find("Lab_1") != std::string::npos);
}

TEST_CASE("Entering grades assigns values correctly") {
    Gradebook g;
    g.add_student("Bob", "Bobberson", "ABC123");
    g.add_assignment("Quiz_1", 100);
    g.add_assignment("Lab_1", 50);

    g.enter_grade("ABC123", "Quiz_1", 85);
    g.enter_grade("ABC123", "Lab_1", 40);

    std::string report = g.report();

    REQUIRE(report.find("85") != std::string::npos);
    REQUIRE(report.find("40") != std::string::npos);
}

TEST_CASE("Missing grades display as 'NA' in report") {
    Gradebook g;
    g.add_student("Sam", "Sammerson", "DEF456");
    g.add_assignment("Quiz_1", 100);
    g.add_assignment("Lab_1", 50);

    // Sam has only one grade entered
    g.enter_grade("DEF456", "Quiz_1", 95);

    std::string report = g.report();

    REQUIRE(report.find("NA") != std::string::npos);
}

TEST_CASE("Report format contains header and commas") {
    Gradebook g;
    g.add_student("Ali", "Ahmed", "XYZ123");
    g.add_assignment("Midterm", 100);

    std::string report = g.report();

    REQUIRE(report.find("Last_Name,First_Name,Student_Id") != std::string::npos);
    REQUIRE(report.find(",Average") != std::string::npos);
    REQUIRE(report.find(",Midterm") != std::string::npos);
    REQUIRE(report.find("Ahmed,Ali,XYZ123") != std::string::npos);
}

TEST_CASE("Gradebook generates a correct assignment report") {
    Gradebook g;

    g.add_student("Bob", "Bobberson", "ABC123");
    g.add_student("Sam", "Sammerson", "DEF456");
    g.add_student("Jess","Jesserson", "HIJ789");

    g.add_assignment("Quiz 1", 100);
    g.add_assignment("Lab 1", 50);

    g.enter_grade("DEF456", "Quiz 1", 95);
    g.enter_grade("ABC123", "Quiz 1", 85);
    g.enter_grade("HIJ789", "Lab 1", 49);
    g.enter_grade("HIJ789", "Quiz 1", 93);
    g.enter_grade("ABC123", "Lab 1", 0);

    std::string report = g.assignment_report("Lab 1");

    std::string expected =
        "Last_Name,First_Name,Student_Id,Score\n"
        "Bobberson,Bob,ABC123,0\n"
        "Sammerson,Sam,DEF456,none\n"
        "Jesserson,Jess,HIJ789,49\n"
        "\n"
        "Average score:";

    REQUIRE(report.find(expected) != std::string::npos);
}