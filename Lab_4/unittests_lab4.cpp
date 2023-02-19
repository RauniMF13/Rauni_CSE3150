#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "linked_list.h"
#include "../../doctest/doctest/doctest.h"

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

TEST_CASE("Basic linked_list functionality") {
  CHECK_THROWS_WITH(build_linked_list(0), "Trying to make a linked list with an invalid length.");

  int length_list_one = 5;
  struct linked_list* list_one = build_linked_list(length_list_one);

  CHECK(list_one->length == length_list_one);

  struct node* head_node = list_one->head;
  struct node* tail_node = list_one->tail;

  CHECK(head_node->number == 0);
  CHECK(tail_node->number == (length_list_one - 1));

  cout << "Linked list one: ";
  print_linked_list(list_one);
  
  delete_linked_list(list_one);

  int length_list_two = 1;
  struct linked_list* list_two = build_linked_list(length_list_two);

  CHECK(list_two->length == length_list_two);

  head_node = list_two->head;
  tail_node = list_two->tail;

  CHECK(head_node == tail_node);

  cout << "Linked list two: ";
  print_linked_list(list_two);

  delete_linked_list(list_two);
}

TEST_CASE("Testing pointer jumping.") {
  int length_list_three = 10;
  struct linked_list* list_three = build_linked_list(length_list_three);

  CHECK(list_three->length == length_list_three);

  cout << "Linked list three: ";
  print_linked_list(list_three);
  
  struct node** jumped_list = pointer_jump(list_three);

  cout << "Pointer jumped nodes list: ";
  print_nodes(jumped_list, length_list_three);
  
  delete_nodes(jumped_list, length_list_three);
}
