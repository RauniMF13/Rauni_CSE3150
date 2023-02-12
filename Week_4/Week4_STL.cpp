#include "my_struct.h"
#include "stack_struct.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  stack<my_struct> stack_structs = read_stack_from_file("input.txt");

  my_struct s = pop_struct_from_stack(stack_structs);

  cout << "Struct at top of stack: ";
  print_struct(s);

  int sum = add_stack_elements(stack_structs);

  cout << "Stack sum: " << sum << endl;
  
  return 0;
}