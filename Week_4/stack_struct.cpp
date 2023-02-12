#include "stack_struct.h"
#include "my_struct.h"
#include <cstdio>
#include <iostream>

using namespace std;

std::stack<struct my_struct> read_stack_from_file(const char* filename) {
  FILE* input;
  input = fopen(filename, "r");
  if(input == NULL) {
    cout << "Input file is invalid." << endl;
    exit(1);
  }

  stack<my_struct> result;
  
  char* line = (char*)malloc(sizeof(int));

  int num_structs = 0;
  
  while(fscanf(input, "%[^\n] ", line) != EOF) {
    int number = atoi(line);
    my_struct s = create_struct(number, num_structs);
    result.push(s);
    num_structs++;
  }

  delete line;
  
  return result;
}

struct my_struct pop_struct_from_stack(std::stack<struct my_struct> my_stack) {
  my_struct result = my_stack.top();
  my_stack.pop();
  return result;
}

int add_stack_elements(std::stack<struct my_struct> my_stack) {
  int result = 0;
  while(!my_stack.empty()) {
    my_struct s = my_stack.top();
    result += s.number;
    my_stack.pop();
  }
  return result;
}
