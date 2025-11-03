#ifndef HELLO_WORLD_STUDENT_H
#define HELLO_WORLD_STUDENT_H
#include <string>


class Student {
    private:
        std::string firstName;
        std::string lastName;
        std::string id;
    public:
        Student(std::string f, std::string l, std::string id);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getId() const;
};


#endif //HELLO_WORLD_STUDENT_H