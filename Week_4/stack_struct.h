#include <stack>

#ifndef __STACK_STRUCT_H_
#define __STACK_STRUCT_H_

std::stack<struct my_struct> read_stack_from_file(const char* filename);
struct my_struct pop_struct_from_stack(std::stack<struct my_struct> my_stack);
int add_stack_elements(std::stack<struct my_struct> my_stack);

#endif
