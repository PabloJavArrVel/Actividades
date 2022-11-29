

// File: appGrafo.h
// Author: Pablo Javier Arreola Velasco
// Date: 09/11/22

#include <iostream>
#include "unweighted.h"
#include <vector>
#include <set>

int main()
{

  // A graph is made

  Unweighted<int> graph(5);

  // Vertex are added

  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addVertex(5);

  // Edges are added

  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  graph.addEdge(2, 4);
  graph.addEdge(3, 4);
  graph.addEdge(3, 5);
  graph.addEdge(4, 5);

  // The graph is printed

  std::cout << graph << std::endl;

  int start = 3;
  std::vector<int> dfs = graph.DFS(start, &graph);

  // The DFS result is printed

  std::cout << "DFS from " << start << ": ";
  for (auto it = dfs.begin(); it != dfs.end(); ++it)
    std::cout << ' ' << *it;

  return 0;
}