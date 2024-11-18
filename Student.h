#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

// Base Class
class Student {
protected:
    std::string firstname;
    std::string lastname;
    double gpa;
    int graduation_year;
    std::string graduation_semester;
    int enrolled_year;
    std::string enrolled_semester;
    std::string grad_undergrad; // "Grad" or "Undergrad"

public:
    Student();
    virtual ~Student(); // Virtual destructor

    // Setters
    void setName(const std::string& first, const std::string& last);
    void setGPA(double gpa);
    void setGraduationInfo(int year, const std::string& semester);
    void setEnrollmentInfo(int year, const std::string& semester);
    void setGradUndergrad(const std::string& grad_undergrad);

    // Getters
    std::string getName() const;
    double getGPA() const;
    std::string getGraduationInfo() const;
    std::string getEnrollmentInfo() const;
    std::string getGradUndergrad() const;

    virtual void displayInfo(std::ostream& os) const = 0; // Pure virtual for polymorphism
    friend std::ostream& operator<<(std::ostream& os, const Student& student); // Output operator
};

// Derived Class: Art_Student
class Art_Student : public Student {
private:
    std::string art_emphasis; // "Art Studio", "Art History", "Art Education"

public:
    Art_Student();
    ~Art_Student() override;

    void setArtEmphasis(const std::string& emphasis);
    std::string getArtEmphasis() const;

    void displayInfo(std::ostream& os) const override;
};

// Derived Class: Physics_Student
class Physics_Student : public Student {
private:
    std::string concentration; // "Biophysics" or "Earth and Planetary Sciences"

public:
    Physics_Student();
    ~Physics_Student() override;

    void setConcentration(const std::string& concentration);
    std::string getConcentration() const;

    void displayInfo(std::ostream& os) const override;
};

#endif
