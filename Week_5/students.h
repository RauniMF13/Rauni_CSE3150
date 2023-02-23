#include <vector>
#include <string>
#include <numeric>

#ifndef __STUDENTS_H_
#define __STUDENTS_H_

struct student {
  int id;
  std::string name;
  int final;
  int midterm;
  std::vector<int> hw_grades;
  double grade() {
    return (0.3 * midterm) + (0.4 * final) + (0.3 * (std::accumulate(hw_grades.begin(), hw_grades.end(), 0) / hw_grades.size()));
  }
};

int non_random_fcn();
int random_fcn();
struct student* create_student(int id, std::string name, int final, int midterm);
struct student** generate_students(int num_students, int (* random_fnc)());
void print_student(struct student* input);
void free_student_data(struct student** students, int length);

#endif
