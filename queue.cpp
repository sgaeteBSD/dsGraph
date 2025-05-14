#include "queue.h"

queue::queue() {
  head = NULL;
  tail = NULL;
}

queue::~queue() {
  while (isempty() == false) {
    char temp;
    dequeue(temp); //remove
  }
}

bool queue::enqueue(const char &data) {
  Node* newNode = new Node(data);

  if (isempty() == true) {
    head = newNode;
    tail = newNode;
  }
  else {
    tail->setNext(newNode);
    tail = newNode;
  }
  return true;
}

bool queue::dequeue(char &data) {
  if (isempty() == true) {
    return false;
  }

  Node* temp = head;
  data = head->getData();
  head = head->getNext();
  if (head == NULL) {
    tail = NULL;
  }
  delete temp;
  return true;
}

bool queue::peek(char &data) {
  if (isempty() == true) {
    return false;
  }
  data = head->getData();
  return true;
}

bool queue::isempty() {
  return head == NULL; //return result of that call
}
