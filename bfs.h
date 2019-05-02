#ifndef __BFH_H__
#define __BFH_H__

#include "graph.h"

#include <functional>

class Bfs
{
public:
  typedef std::function<void(const Node&)> NodeCallback;
  typedef std::function<void(const Edge&)> EdgeCallback;

  static NodeCallback noop_node_callback;
  static EdgeCallback noop_edge_callback;

public:
  Bfs ()                           = delete;
  Bfs (const Bfs& orig)            = default;
  Bfs& operator= (const Bfs& orig) = default;
  ~Bfs ()                          = default;

  Bfs(const Graph& graph,
      NodeCallback node_cb_1 = noop_node_callback,
      NodeCallback node_cb_2 = noop_node_callback,
      EdgeCallback edge_cb   = noop_edge_callback);

public:
  void process(const Node& start_node);

private:
  const Graph  _graph;
  NodeCallback _node_cb_1;
  NodeCallback _node_cb_2;
  EdgeCallback _edge_cb;

  std::vector<bool> _is_discovered;
  std::vector<bool> _is_processed;
  std::vector<Node> _parent_node;
};

#endif // __BHS_H__
