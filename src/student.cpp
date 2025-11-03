#include "student.h"
#include <string>

Student::Student(std::string f, std::string l, std::string id) : firstName(f), lastName(l), id(id) {};
std::string Student::getFirstName() const{
    return this->firstName;
};
std::string Student::getLastName() const{
    return this->lastName;
};
std::string  Student::getId() const{
    return this->id;
};