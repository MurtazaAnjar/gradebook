#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/student.h"

TEST_CASE("Student constructor initializes correctly") {
    Student s("Bob", "Bobberson", "ABC123");

    REQUIRE(s.getFirstName() == "Bob");
    REQUIRE(s.getLastName() == "Bobberson");
    REQUIRE(s.getId() == "ABC123");
}

TEST_CASE("Multiple students are independent") {
    Student s1("Jess", "Jesserson", "HIJ789");
    Student s2("Sam", "Sammerson", "DEF456");

    REQUIRE(s1.getFirstName() == "Jess");
    REQUIRE(s2.getFirstName() == "Sam");
    REQUIRE(s1.getLastName() != s2.getLastName());
    REQUIRE(s1.getId() != s2.getId());
}

TEST_CASE("Student handles edge cases like empty names") {
    Student s("", "Lastname", "000");
    REQUIRE(s.getFirstName() == "");
    REQUIRE(s.getLastName() == "Lastname");
    REQUIRE(s.getId() == "000");

    Student s2("OnlyFirst", "", "");
    REQUIRE(s2.getFirstName() == "OnlyFirst");
    REQUIRE(s2.getLastName() == "");
    REQUIRE(s2.getId() == "");
}

TEST_CASE("Student getters do not modify object state") {
    const Student s("Ali", "Ahmed", "XYZ999");
    REQUIRE(s.getFirstName() == "Ali");
    REQUIRE(s.getLastName() == "Ahmed");
    REQUIRE(s.getId() == "XYZ999");
}