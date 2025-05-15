#include "graph.h"
#include <algorithm>

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
  int ind = getIndex(data);
  if (ind == -1) {
    cout << "Vertex '" << data << "' was not found." << endl;
    return;
  }

  for (int a = ind; a < vertCt-1; a++) { //shift labels
    vertLbls[a] = vertLbls[a+1];
  }
  vertLbls[vertCt-1] = '\0';

  //shift table rows up
  for (int a = ind; a < vertCt-1; a++) {
    for (int b = 0; b < vertCt; b++) {
      table[a][b] = table[a+1][b];
    }
  }

  //shift table cols up
  for (int a = 0; a < vertCt-1; a++) {
    for (int b = ind; b < vertCt-1; b++) {
      table[a][b] = table[a][b+1];
    }
  }

  vertCt--;
  cout << "Vertex '" << data << "' was removed." << endl;
}

void Graph::rmEdge(char from, char to) {
  int fromID = getIndex(from);
  int toID = getIndex(to);

  if (fromID == -1 || toID == -1) {
    cout << "One or more vertices were not found!";
    return;
  }

  table[fromID][toID] = 0;
  cout << "Edge removed from '" << from << "' to '" << to << "'." << endl;
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
      cout << table[b][a] << " ";
    }
    cout << endl;
  }
}

void Graph::search(char start, char end) {
  int startID = getIndex(start);
  int endID = getIndex(end);
  if (startID == -1 || endID == -1) {
    cout << "One or more vertices were not found!";
    return;
  }

  vector<int> dist(vertCt, -1);
  vector<int> prev(vertCt, -1);
  vector<bool> visited(vertCt, false);

  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  dist[startID] = 0;
  pq.push({0, startID});
  while (!pq.empty()) {
    int u = pq.top()[1];
    pq.pop();
    /*
    if (a == endID) break;
    
    if (visited[a]) {
      continue;
    }
    visited[a] = true;
    */
    
    for (int b = 0; b < vertCt; b++) {
      int v = getIndex(table[b]); //table[b] is wrong
      int weight = table[u][v];
      if (dist[u] + weight < dist[v]) {
	dist[v] = dist[u] + weight;
	prev[v] = u;
	pq.push({dist[v], v});
      }
    }
  }
  //find the actual path
  vector<int> path;
  int c = endID;

  if (prev[c] != -1 || c == startID) {
    while (c != -1) {
      path.push_back(c);
      c = prev[c];
    }

    reverse(path.begin(), path.end());

    cout << "Shortest path from '" << start << "' to '" << end << "': ";
    for (int a = 0; a < path.size(); a++) {
      cout << vertLbls[path[a]];
      if (a < path.size()-1) {
	cout << " -> ";
      }
      cout << "\nTotal weight: " << dist[endID] << endl;
    }
  } else {
    cout << "No path exists from '" << start << "' to '" << end << "'." << endl;
  }
}

int Graph::getIndex(char lbl) {
  for (int a = 0; a < vertCt; a++) {
    if (vertLbls[a] == lbl) {
      return a;
    }
  }
  return -1; //we'll use -1 for anything not found in search
}

bool Graph::lblExists(char lbl) {
  return (getIndex(lbl) != -1); //return true if found (>-1), false if not found (-1)
}
