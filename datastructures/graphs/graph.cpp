#include <iostream>
#include <vector>
#include <unordered_map>

//     2-----0
//   /  \
// 1------3

// ways to create a graph (JS)
// 1. edge list
// const graph = [[0,2],[2,3],[2,1],[1,3]];
// just shows the connections

// 2. adjacency list
// index of the data structure is the node,
// and the value is the connections
// const graph = [[2], [2,3], [0,1,3], [2,1]];

// 3. adjacency matrix
// 0s and 1s to indicate if y (row)
// has connection to x (col)
// const graph = [
// [0,0,1,0],
// [0,0,1,1],
// [1,1,0,1],
// [0,1,1,0]
// ]

// undirected, unweighted
class Graph {
public:
  Graph() {}

  // add a new node
  void addVertex(int node) {
    if (adjacent_list.find(node) == adjacent_list.end())
      adjacent_list[node] = {};
    else
      std::cout << "Node already exists" << std::endl;
  }

  // add a connection between two nodes
  // TODO: check if connection already exists
  void addEdge(int node1, int node2) {
    if (adjacent_list.find(node1) == adjacent_list.end() ||
	adjacent_list.find(node2) == adjacent_list.end()) {
      std::cout << "One of the nodes doesn't exist" << std::endl;
      return;
    }
    adjacent_list[node1].push_back(node2);
    adjacent_list[node2].push_back(node1);
  }

  //void addEdge(int

  void showConnections() {
    for (auto node : adjacent_list) {
      std::cout << node.first << ": ";

      if (!node.second.size()) {
	std::cout << "This node has no connections" << std::endl;
	continue;
      }
      for (auto i : node.second) {
	std::cout << i << " ";
      }
      std::cout << std::endl;
    }
  }
private:
  int num_nodes = 0;
  std::unordered_map<int, std::vector<int>> adjacent_list;
};

int main() {
  Graph graph;

  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addVertex(5);
  graph.addVertex(6);

  graph.addEdge(3, 1);
  graph.addEdge(3, 4);
  graph.addEdge(4, 2);
  graph.addEdge(4, 5);
  graph.addEdge(1, 2);
  graph.addEdge(1, 0);
  graph.addEdge(0, 2);
  graph.addEdge(6, 5);

  graph.showConnections();
}
