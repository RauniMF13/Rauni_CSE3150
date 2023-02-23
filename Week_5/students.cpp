#include "students.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int non_random_fcn() {
  return 25;
}

int random_fcn() {
  return rand();
}

struct student* create_student(int id, string name, int final, int midterm) {
  struct student* result = (student*)malloc(sizeof(student));
  result->id = id;
  result->name = name;
  result->final = final;
  result->midterm = midterm;
    
  return result;
}

struct student** generate_students(int num_students, int (* random_fcn)()) {
  srand(time(nullptr));

  struct student** students = (student**)malloc(sizeof(student*) * num_students);

  for(int i = 0; i < num_students; i++) {
    string name = "Student " + to_string(i + 1);
    int final = random_fcn() % (100 - 50 + 1) + 50;
    int midterm = random_fcn() % (100 - 50 + 1) + 50;
    
    students[i] = create_student(i + 100000, name, final, midterm);
    
    for(int j = 0; j < 4; j++) {
      students[i]->hw_grades.push_back(random_fcn() % (100 - 50 + 1) + 50);
    }
  }
  
  return students;
}

void print_student(struct student* input) {
  cout << input->name << ", id: " << input->id << endl;
  cout << "Grades: " << endl;
  cout << "\tMidterm: " << input->midterm << endl;
  cout << "\tFinal: " << input->final << endl;
  cout << "\tHomework: ";
  for(int grade : input->hw_grades) {
    cout << grade << " ";
  }
  cout << endl;
  cout << "\tOverall: " << input->grade() << endl;
}

void free_student_data(struct student** students, int length) {
  for(int i = 0; i < length; i++) {
    delete students[i];
  }
}
