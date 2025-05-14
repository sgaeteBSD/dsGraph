#ifndef QUEUE_H
#define GRAPH_H

#include "Node.h"
#include <iostream>

using namespace std;

class queue {
public:
  queue();
  ~queue();
  bool enqueue(const char &data);
  bool dequeue(char &data);
  bool peek(char &data);
  bool isempty();
private:
  Node* head;
  Node* tail;
};

#endif
