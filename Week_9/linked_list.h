#include <memory>
#include <utility>

#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

struct List {
  struct Node {
    int data;
    std::unique_ptr<struct Node> next;
    
  Node(int data) : data(data), next(nullptr) {};
  };

  std::unique_ptr<Node> head;

  ~List() {
    while(head != nullptr) head = std::move(head->next);
  }
  
  void push(int data) {
    auto new_node = std::make_unique<struct Node>(data);
    if (head == nullptr) {
      head = std::move(new_node);
    } else {
      new_node->next = std::move(head);
      head = std::move(new_node);
    }
  }
};

#endif
