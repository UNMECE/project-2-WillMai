#include "Student.h"
#include <vector>
#include <fstream>

int main() {
    std::vector<Art_Student*> artStudents;
    std::vector<Physics_Student*> physicsStudents;

    // Create Art Students
    for (int i = 0; i < 2; ++i) {
        auto* student = new Art_Student();
        student->setName("ArtFirst" + std::to_string(i), "ArtLast" + std::to_string(i));
        student->setGPA(3.5 + i * 0.1);
        student->setGraduationInfo(2025, "Spring");
        student->setEnrollmentInfo(2021, "Fall");
        student->setGradUndergrad("Undergrad");
        student->setArtEmphasis("Art Studio");
        artStudents.push_back(student);
    }
    for (int i = 0; i < 3; ++i) {
        auto* student = new Art_Student();
        student->setName("ArtFirst" + std::to_string(i), "ArtLast" + std::to_string(i));
        student->setGPA(3.3 + i * 0.1);
        student->setGraduationInfo(2025, "Spring");
        student->setEnrollmentInfo(2021, "Fall");
        student->setGradUndergrad("Grad");
        student->setArtEmphasis("Art Education");
        artStudents.push_back(student);
    }

    // Create Physics Students
    for (int i = 0; i < 2; ++i) {
        auto* student = new Physics_Student();
        student->setName("PhysicsFirst" + std::to_string(i), "PhysicsLast" + std::to_string(i));
        student->setGPA(3.7 + i * 0.05);
        student->setGraduationInfo(2024, "Fall");
        student->setEnrollmentInfo(2020, "Spring");
        student->setGradUndergrad("Grad");
        student->setConcentration("Biophysics");
        physicsStudents.push_back(student);
    }

    for (int i = 0; i < 2; ++i) {
        auto* student = new Physics_Student();
        student->setName("PhysicsFirst" + std::to_string(i), "PhysicsLast" + std::to_string(i));
        student->setGPA(3.5 + i * 0.05);
        student->setGraduationInfo(2024, "Fall");
        student->setEnrollmentInfo(2020, "Spring");
        student->setGradUndergrad("Undergrad");
        student->setConcentration("Earth and Planetary Sciences");
        physicsStudents.push_back(student);
    }

    // Write to File
    std::ofstream outFile("student_info.dat");
    if (outFile.is_open()) {
        for (const auto& student : artStudents) {
            outFile << *student << "\n";
        }
        for (const auto& student : physicsStudents) {
            outFile << *student << "\n";
        }
        outFile.close();
    }

    // Clean Up Memory
    for (auto* student : artStudents) {
        delete student;
    }
    for (auto* student : physicsStudents) {
        delete student;
    }

    return 0;
}
