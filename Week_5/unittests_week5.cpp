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
  
  delete my_student;
  free_student_data(students_list, length_student_list);
}
