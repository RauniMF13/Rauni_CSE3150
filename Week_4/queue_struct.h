#include <queue>

#ifndef __QUEUE_STRUCT_H_
#define __QUEUE_STRUCT_H_

std::queue<struct my_struct> read_queue_from_file(const char* filename);
struct my_struct pop_struct_from_queue(std::queue<struct my_struct> my_queue);
int add_queue_elements(std::queue<struct my_struct> my_queue);

#endif
