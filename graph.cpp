#include <queue>
#include "graph.hpp"
#include "mst.hpp"
#include "union_find.hpp"

using std::cerr;
using std::endl;

Weighted_Graph::Weighted_Graph(string name) : name(name), E(0), V(0), adj(1) {}


MST Weighted_Graph::kruskal() const 
{
  MST mst;

  // The priority pq stores the edges with the minimum element determined by the edge weights.
  // I'm spotting you the declaration of the priority queue since the syntax is particularly forbidding. 
  // I couldn't resist passing a lambda expression (new in C++11) to serve as the comparator in the
  // priority queue.
  auto compare = [](Edge e, Edge f) {return (e.weight() > f.weight());};
  std::priority_queue<Edge, std::vector<Edge>, decltype(compare)> pq(compare);

  // Kruskal's algorithm goes here...
  cerr << "It would help if you implemented Kruskal's algorithm!" << endl;
  
  return mst;
}

ostream &operator<<(ostream &os, const Weighted_Graph &G) 
{
  os << "graph: " << G.name << " {\n";
  os << " V: " << G.V << "\n";
  os << " E: " << G.E << "\n";
  os << " adjacency list = {" << "\n";
  for (auto v = 0; v < G.V; v++) {
    os << "  " << v << ": ";
    if (!G.adj[v].empty()) {
      for (auto &w : G.adj[v]) {
	os << w << " ";
      }
    }
    os << endl;
  }
  os << " }" << endl;
  os << "}" << endl;

  return os;
}
