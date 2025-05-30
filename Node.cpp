#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char newData) {
  // constructor
  data = newData;
  next = NULL; // setting pointer to null
  prev = NULL;
}
Node::~Node(){
  // destructor
  next = NULL;
  prev = NULL;
}
Node*& Node::getNext() {
  return next;
}
Node*& Node::getPrev() {
  return prev;
}
char Node::getData() {
  return data;
}
int Node::getTotal() {
  return total;
}
void Node::setNext(Node* nextNode) {
  next = nextNode;
}
void Node::setPrev(Node* prevNode) {
  prev = prevNode;
}
void Node::setData(char newData) {
  data = newData;
}
void Node::setTotal(int newTotal) {
  total = newTotal;
}
