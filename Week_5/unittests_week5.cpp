#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "students.h"
#include "../../doctest/doctest/doctest.h"

#include <iostream>

using namespace std;

TEST_CASE("Students structs and methods functionality") {
  struct student* my_student = create_student(243716, "John Smith", 80, 92);
  
  my_student->hw_grades.push_back(75);

  CHECK(my_student->grade() == 82.1);
  print_student(my_student);
  
  int length_student_list = 10;
  struct student** students_list = generate_students(length_student_list, &random_fcn);

  for(int i = 0; i < length_student_list; i++) {
    CHECK(students_list[i]->id == (i + 100000));
    CHECK(students_list[i]->final > 0);
    CHECK(students_list[i]->midterm > 0);
    CHECK(students_list[i]->grade() > 0);
  }

  int length_definite_list = 5;
  struct student** students_definite = generate_students(length_definite_list, &non_random_fcn);

  for(int i = 0; i < length_definite_list; i++) {
    CHECK(students_definite[i]->id == (i + 100000));
    CHECK(students_definite[i]->final == 75);
    CHECK(students_definite[i]->midterm == 75);
    CHECK(students_definite[i]->grade() == 75);
  }
  
  delete my_student;
  free_student_data(students_list, length_student_list);
  free_student_data(students_definite, length_definite_list);
}
