#include "students.h"
#include <iostream>

using namespace std;

int main() {
  struct student* my_student = create_student(243716, "John Doe", 80, 92);

  my_student->hw_grades.push_back(75);
  
  print_student(my_student);
  
  int length_student_list = 10;
  struct student** students_list = generate_students(length_student_list, &random_fcn);

  for (int i = 0; i < length_student_list; i++) {
    print_student(students_list[i]);
  }
  
  delete my_student;
  free_student_data(students_list, length_student_list);
}
