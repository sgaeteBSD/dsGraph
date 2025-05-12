#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(char newData);
  ~Node();

  Node* &getNext();
  char getData();
  Node* &getPrev();
  int getTotal();

  void setNext(Node* nextNode);
  void setData(char newData);
  void setPrev(Node* prevNode);
  void setTotal(int newTotal);
  
 private:
  char data;
  Node* next;
  Node* prev;
  int total;
};

#endif
