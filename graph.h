#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"
#include <queue> //std queue

using namespace std;

class Graph {
public:
  Graph();
  ~Graph();

  void addVert(char data);
  void addEdge(char from, char to, int weight);
  void rmVert(char data);
  void rmEdge(char from, char to);
  void print();
  void search(char start, char end);
  int getIndex(char lbl); //will map label to index
  bool lblExists(char lbl);
private:
  int table[20][20]; //fixed size limit
  char vertLbls[20]; //index to labels
  int vertCt; //count
};

#endif
