#include "student.h"
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE("setinam ir getinam", "[SetinamGetinam]") {

    WARN ("REQUIRE stops at [SetinamGetinam] failure:");

    Student stud;

    // Setting values using setters
    stud.setName("vardas");
    stud.setSurname("pavarde");
    stud.setExamResult(4);
    stud.setGrades({1, 9, 8});
    stud.setFinalAvg(7);
    stud.setFinalMedian(8);

    // Checking values using getters
    CHECK(stud.getName() == "vardas");
    CHECK(stud.getSurname() == "pavarde");
    CHECK(stud.getExamResult() == 4);
    CHECK(stud.getGrades() == vector<int>({1, 9, 8}));
    CHECK(stud.getFinalAvg() == Approx(7));
    CHECK(stud.getFinalMedian() == Approx(8));

    // Clear data and check
    stud.clearData();
    CHECK(stud.getGrades().empty());
}

TEST_CASE ("kopijav konstrukt", "[KopijKonst]"){

   WARN ("REQUIRE stops at [KopijKonst] failure:");

    Student original;
    original.setName("vardas");
    original.setSurname("pavarde");
    original.setExamResult(7);
    original.setGrades({1, 5, 8});

    Student copy = original;

    CHECK(copy.getName() == "vardas");
    CHECK(copy.getSurname() == "pavarde");
    CHECK(copy.getExamResult() == 7);
    CHECK(copy.getGrades() == vector<int>({1, 5, 8}));
}

TEST_CASE ("kopijavimo assignmentas", "[CopyAssignment]"){

    WARN ("REQUIRE stops at [CopyAssignment] failure:");

     // Original student object
    Student original;
    original.setName("vardas");
    original.setSurname("pavarde");
    original.setExamResult(8);
    original.setGrades({5, 9, 7});
    original.setFinalAvg(8.2);
    original.setFinalMedian(9);

    // Copy assignment
    Student copy;
    copy = original;

    // Checking if the copied object has the same values
    CHECK(copy.getName() == "vardas");
    CHECK(copy.getSurname() == "pavarde");
    CHECK(copy.getExamResult() == 8);
    CHECK(copy.getGrades() == vector<int>({5, 9, 7}));
    CHECK(copy.getFinalAvg() == 8.2);
    CHECK(copy.getFinalMedian() == 9);
}

TEST_CASE ("Perkeliam", "[MoveConst]"){

    WARN ("REQUIRE stops at [MoveConst] failure:");


 // Create an original Student object
    Student originalStudent;
    originalStudent.setName("vardas");
    originalStudent.setSurname("pavarde");
    originalStudent.setExamResult(8);
    originalStudent.setGrades({ 5, 8, 7});

    // Move the original Student object to a new one
    Student movedStudent = move(originalStudent);

    // Check that the moved object has the correct values
    CHECK(movedStudent.getName() == "vardas");
    CHECK(movedStudent.getSurname() == "pavarde");
    CHECK(movedStudent.getExamResult() == 8);
    CHECK(movedStudent.getGrades() == vector<int>({ 5, 8, 7 }));

}


TEST_CASE ("Perkelimo priskyrim", "[MoveAssignment]") {

    WARN("REQUIRE stops at [MoveAssignment] failure:");

    Student originalStudent;
    originalStudent.setName("vardas");
    originalStudent.setSurname("pavarde");
    originalStudent.setExamResult(5);
    originalStudent.setGrades({ 7, 9, 1 });
    Student movedStudent;
    movedStudent = std::move(originalStudent);

    CHECK(movedStudent.getName() == "vardas");
    CHECK(movedStudent.getSurname() == "pavarde");
    CHECK(movedStudent.getExamResult() == 5);
    CHECK(movedStudent.getGrades() == std::vector<int>({ 7, 9, 1 }));

}
 
