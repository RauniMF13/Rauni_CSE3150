#include "queue_struct.h"
#include "my_struct.h"
#include <cstdio>
#include <iostream>
#include <stdexcept>

using namespace std;

std::queue<struct my_struct> read_queue_from_file(const char* filename) {
  FILE* input;
  input = fopen(filename, "r");
  if(input == NULL) {
    cout << "Input file is invalid." << endl;
    exit(1);
  }

  queue<my_struct> result;

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

struct my_struct pop_struct_from_queue(std::queue<struct my_struct> my_queue) {
  my_struct result = my_queue.front();
  my_queue.pop();
  return result;
}

int add_queue_elements(std::queue<struct my_struct> my_queue) {
  int result = 0;
  while(!my_queue.empty()) {
    my_struct s = my_queue.front();
    result += s.number;
    my_queue.pop();
  }

  if(result < 0) {
    throw logic_error("Sum of stack element values is negative.");
  }

  return result;
}
