#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_


struct node {
  int number;
  struct node* next;
};

struct linked_list {
  struct node* head;
  struct node* tail;
  int length;
};

struct linked_list* build_linked_list(const int n);
void print_linked_list(struct linked_list* list);
void delete_linked_list(struct linked_list* list);
struct node**  pointer_jump(struct linked_list* list);
void print_nodes(struct node** nodes, const int length);
void delete_nodes(struct node** nodes, const int length);

#endif
