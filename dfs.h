#ifndef __DFS_H__
#define __DFS_H__

#include "graph.h"

#include <functional>
#include <vector>

class Dfs
{
public:
  typedef std::function<void(const Dfs& dfs, const Node&)> NodeCallback;
  typedef std::function<void(const Dfs& dfs, const Edge&)> EdgeCallback;

public:
  Dfs ()                            = delete;
  Dfs (const Dfs& orig)             = default;
  Dfs& operator= (const Dfs& orig)  = default;
  ~Dfs ()                           = default;

  Dfs(const Graph& graph,
      NodeCallback node_cb_1 = [](const Dfs& dfs, const Node&) { },
      NodeCallback node_cb_2 = [](const Dfs& dfs, const Node&) { },
      EdgeCallback edge_cb   = [](const Dfs& dfs, const Edge&) { });

public:
  void process (const Node& start_node);

  Node parent (const Node& node) const;

private:
  void _process_inner (const Node& start_node);

private:
  const Graph  _graph;
  NodeCallback _node_cb_1;
  NodeCallback _node_cb_2;
  EdgeCallback _edge_cb;

  std::vector<bool> _is_discovered;
  std::vector<bool> _is_processing;
  std::vector<bool> _is_processed;
  std::vector<Node> _parent_node;

  int               _tick;
  std::vector<int>  _entry_tick;
  std::vector<int>  _exit_tick;
};

#endif // __DFS_H__
