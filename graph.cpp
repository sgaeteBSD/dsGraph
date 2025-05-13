#include "graph.cpp"

Graph::Graph() {
  //constructor
  vertCt = 0;
  for (int a = 0; a < 20; a++) {
    vertLbls[a] = '\0'; //null char by default
    for (int b = 0; b < 20; b++) {
      table[a][b] = 0; //init table total
    }
  }
}

Graph::~Graph() {
  //destructor
}

void Graph::addVert(char data) {
  if (vertCt >= 20) {
    cout << "Cannot add more than 20 vertices." << endl;
    return;
  }
  if (lblExists(data)) {
    cout << "Vertex '" << data << "' already exists." << endl;
    return;
  }
  
  vertLbls[vertCt] = data;
  vertCt++;
  
  cout << "Vertex '" << data << "' added." << endl;
}

void Graph::addEdge(char from, char to, int weight) {
  int fromID = getIndex(from);
  int toID = getIndex(to);

  if (fromID == -1 || toID == -1) {
    cout << "One or more vertices were not found!" << endl;
    return;
  }

  if (weight <= 0) {
    cout << "Invalid edge weight." << endl;
    return;
  }

  table[fromID][toID] = weight;
  cout << "Edge added from '" << from << "' to '" << to << "' with weight " << weight << "." << endl;
}

void Graph::rmVert(char data) {
  
}

void Graph::rmEdge(char from, char to) {
  
}

void Graph::print() {
  cout << "   ";
  for (int a = 0; a < vertCt; a++) {
    cout << vertLbls[a] << " ";
  }
  cout << endl;

  for (int a = 0; a < vertCt; a++) {
    cout << vertLbls[a] << ": ";
    for (int b = 0; b < vertCt; b++) {
      cout << table[a][b] << " ";
    }
    cout << endl;
  }
}

void search(char start, char end) {
  
}

int getIndex(char lbl) {
  for (int a = 0; a < vertCt; a++) {
    if (vertLbls[a] == lbl) {
      return a;
    }
  }
  return -1; //we'll use -1 for anything not found in search
}

bool lblExists(char lbl) {
  return (getIndex(lbl) != -1); //return true if found (>-1), false if not found (-1)
}
