#ifndef __MY_STRUCT_H_
#define __MY_STRUCT_H_

struct my_struct {
  int number;
  int id;
};

struct my_struct create_struct(int number, int id);
void print_struct(my_struct s);

#endif
