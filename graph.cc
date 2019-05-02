#include "graph.h"

#include <tuple>
#include <iostream>

using namespace std;

Graph::Graph (const int num_nodes, const bool is_directed)
  : _num_nodes{num_nodes},
    _is_directed{is_directed},
    _nodes(num_nodes, 0),
    _degree(num_nodes, 0),
    _in_degree(num_nodes, 0),
    _out_degree(num_nodes, 0),
    _edges_by_node(num_nodes)
{
  for (int ii=0; ii<_num_nodes; ii++) {
    _nodes[ii] = ii;
  }

  // cout << "_edges_by_node size = " << _edges_by_node.size() << endl;
}

int Graph::num_nodes () const
{ return _num_nodes; }

int Graph::num_edges () const
{ return _edges.size(); }

bool Graph::is_directed () const
{ return _is_directed; }

const std::vector<Node>& Graph::nodes () const
{ return _nodes; }

const std::vector<Edge>& Graph::edges () const
{ return _edges; }

const std::vector<Edge>& Graph::node_edges (const Node& node) const
{ return _edges_by_node[node]; }

void Graph::add_edge(const Edge& edge)
{
  if (edge.to == edge.from) {
    throw runtime_error("no self-looping edges allowed");
  }

  for (const Edge& existing_edge : _edges) {
    if (tie(edge.from, edge.to) == tie(existing_edge.from, existing_edge.to)) {
      throw runtime_error("duplicate edge (case A)");
    }
  }

  if (!_is_directed) {
    for (const Edge& existing_edge : _edges) {
      if (tie(edge.to, edge.from) == tie(existing_edge.from, existing_edge.to)) {
        throw runtime_error("duplicate edge (case B)");
      }
    }
  }

  _edges.push_back(edge);
  _edges_by_node[edge.from].push_back(edge);

  if (_is_directed) {
    _out_degree[edge.from]++;
    _in_degree[edge.to]++;
  }
  else {
    _edges_by_node[edge.to].push_back({edge.to, edge.from, edge.weight});
    _degree[edge.from]++;
    _degree[edge.to]++;
  }
}
