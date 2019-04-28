#ifndef __BFH_H__
#define __BFH_H__

#include "graph.h"

#include <functional>

class Bfs
{
public:
  typedef std::function<void(const Node&)> NodeCallback;
  typedef std::function<void(const Edge&)> EdgeCallback;

public:
  Bfs ()                           = delete;
  Bfs (const Bfs& orig)            = default;
  Bfs& operator= (const Bfs& orig) = default;
  ~Bfs ()                          = default;

  Bfs(const Graph& graph,
      NodeCallback node_cb_1 = [](const Node&) { },
      NodeCallback node_cb_2 = [](const Node&) { },
      EdgeCallback edge_cb   = [](const Edge&) { });

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
