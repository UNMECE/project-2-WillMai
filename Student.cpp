#include "Student.h"
#include <iostream>

// Base Class Implementation
Student::Student() 
    : firstname("undefined"), lastname("undefined"), gpa(0.0), 
      graduation_year(2024), graduation_semester("undefined"), 
      enrolled_year(2024), enrolled_semester("undefined"), grad_undergrad("undefined") {}

Student::~Student() {}

void Student::setName(const std::string& first, const std::string& last) {
    firstname = first;
    lastname = last;
}

void Student::setGPA(double gpa) {
    this->gpa = gpa;
}

void Student::setGraduationInfo(int year, const std::string& semester) {
    graduation_year = year;
    graduation_semester = semester;
}

void Student::setEnrollmentInfo(int year, const std::string& semester) {
    enrolled_year = year;
    enrolled_semester = semester;
}

void Student::setGradUndergrad(const std::string& grad_undergrad) {
    this->grad_undergrad = grad_undergrad;
}

std::string Student::getName() const {
    return firstname + " " + lastname;
}

double Student::getGPA() const {
    return gpa;
}

std::string Student::getGraduationInfo() const {
    return std::to_string(graduation_year) + " " + graduation_semester;
}

std::string Student::getEnrollmentInfo() const {
    return std::to_string(enrolled_year) + " " + enrolled_semester;
}

std::string Student::getGradUndergrad() const {
    return grad_undergrad;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    student.displayInfo(os);
    return os;
}

// Art_Student Implementation
Art_Student::Art_Student() : art_emphasis("undefined") {}

Art_Student::~Art_Student() {}

void Art_Student::setArtEmphasis(const std::string& emphasis) {
    art_emphasis = emphasis;
}

std::string Art_Student::getArtEmphasis() const {
    return art_emphasis;
}

void Art_Student::displayInfo(std::ostream& os) const {
    os << "Art Student: " << getName() << ", GPA: " << getGPA() 
       << ", Graduation: " << getGraduationInfo() 
       << ", Enrollment: " << getEnrollmentInfo() 
       << ", Level: " << getGradUndergrad() 
       << ", Emphasis: " << art_emphasis;
}

// Physics_Student Implementation
Physics_Student::Physics_Student() : concentration("undefined") {}

Physics_Student::~Physics_Student() {}

void Physics_Student::setConcentration(const std::string& concentration) {
    this->concentration = concentration;
}

std::string Physics_Student::getConcentration() const {
    return concentration;
}

void Physics_Student::displayInfo(std::ostream& os) const {
    os << "Physics Student: " << getName() << ", GPA: " << getGPA() 
       << ", Graduation: " << getGraduationInfo() 
       << ", Enrollment: " << getEnrollmentInfo() 
       << ", Level: " << getGradUndergrad() 
       << ", Concentration: " << concentration;
}
