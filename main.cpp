/*
 * Santiago Gaete
 * 5/15/25
 * Data Structures - Graph Creator
 * GeeksForGeeks used as reference for Dijkstra's (https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)
 */

#include "Node.h"
#include "graph.h"

using namespace std;

void quitter(bool &input);

int main() {
  Graph graph;
  bool input = true;

  cout << "This is a graph creator." << endl;
  
  while (input == true) { //command selector

    bool exist = false;
    if (graph.getIndex('A') != -1) {
      exist = true;
    }
    
    cout << "Your commands are adv: Add Vertex, ade: Add Edge, rmv: Remove Vertex, rme: Remove Edge, pr: Print, sr: Search, and qt: Quit." << endl;
    cout << endl;
    cout << "Input a command." << endl;
    char command[15] = ""; //make sure to fit chars + 1 terminating

    cin >> command; 
    cin.ignore();
    
    
    if (strcmp(command, "adv") == 0) {
	char add = '\0';
	cout << "Vertex label to add:" << endl;
	cin >> add;
	graph.addVert(add);
    }
    else if (strcmp(command, "ade") == 0) {
	char add1 = '\0';
	char add2 = '\0';
	int add3 = 0;
	cout << "Starting vertex:" << endl;
	cin >> add1;
	cout << "Ending vertex:" << endl;
	cin >> add2;
	cout << "Edge weight:" << endl;
	cin >> add3;
	graph.addEdge(add1, add2, add3);
    }
    else if (strcmp(command, "sr") == 0) {
      if (exist == true) {
	char rm1 = '\0';
	char rm2 = '\0';
	cout << "Starting vertex:" << endl;
	cin >> rm1;
	cout << "Ending vertex:" << endl;
	cin >> rm2;
	graph.search(rm1, rm2);
      }
      else { 
	cout << "Your graph has no edges!" << endl;
      }
    }
    else if (strcmp(command, "pr") == 0) {
      if (exist == true) {
	graph.print();
      }
      else {
	cout << "Your graph is empty!" << endl;
      }
    }
    else if (strcmp(command, "rmv") == 0) {
      if (exist == true) {
	char key;
	cout << "Vertex label to remove:" << endl;
	cin >> key;
	graph.rmVert(key);
      }
      else { 
	cout << "Your graph is empty!" << endl;
      }
    }
    else if (strcmp(command, "rme") == 0) {
      if (exist == true) {
	char rm1 = '\0';
	char rm2 = '\0';
	cout << "Starting vertex:" << endl;
	cin >> rm1;
	cout << "Ending vertex:" << endl;
	cin >> rm2;
	graph.rmEdge(rm1, rm2);
      }
      else { 
	cout << "Your graph has no edges!" << endl;
      }
    }
    else if (strcmp(command, "qt") == 0) {
      quitter(input);
    }
    else {
      cout << "Invalid input! Try again." << endl;
    }
  }
}

void quitter(bool &input) { //quit
  cout << "Goodbye!" << endl;
  input = false;
}
