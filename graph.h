#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>

typedef int Node;

struct Edge
{
  const Node  from;
  const Node  to;
  const float weight{1.0};
};

class Graph
{
public:
  Graph ()                             = delete;
  Graph (const Graph& orig)            = default;
  Graph& operator= (const Graph& orig) = default;
  ~Graph ()                            = default;

public:
  Graph (const int num_nodes, const bool is_directed=false);

public:
  int  num_nodes () const;
  int  num_edges () const;
  bool is_directed () const;

  const std::vector<Node>& nodes () const;
  const std::vector<Edge>& edges () const;
  const std::vector<Edge>& node_edges (const Node& node) const;

  void add_edge(const Edge& edge);

private:
  const int         _num_nodes;
  const bool        _is_directed;
  std::vector<Node> _nodes;
  std::vector<Edge> _edges;
  std::vector<int>  _degree;
  std::vector<int>  _in_degree;
  std::vector<int>  _out_degree;

  std::vector<std::vector<Edge>> _edges_by_node;
};

#endif // __GRAPH_H__
