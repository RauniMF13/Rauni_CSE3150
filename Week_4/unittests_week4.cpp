#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "my_struct.h"
#include "stack_struct.h"
#include "../../doctest/doctest/doctest.h"

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

TEST_CASE("Testing the reading of stacks from input files, sums of struct elements, and negative sums throwing exceptions.") {
  stack<my_struct> stack_structs = read_stack_from_file("input.txt");

  CHECK(stack_structs.top().id > 0);
  
  my_struct s = pop_struct_from_stack(stack_structs);

  CHECK(s.id > 0);
    
  cout << "Struct at top of stack: ";
  print_struct(s);

  int sum = add_stack_elements(stack_structs);
  
  cout << "Stack sum: " << sum << endl;

  CHECK(sum > 0);
  
  stack<my_struct> negative_stack_structs = read_stack_from_file("input_negative.txt");

  CHECK(negative_stack_structs.top().id > 0);
  
  
  CHECK_THROWS_WITH(add_stack_elements(negative_stack_structs), "Sum of stack element values is negative.");
}
