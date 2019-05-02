#include "dfs.h"

#include <deque>
#include <tuple>
#include <utility>

using namespace std;

Dfs::NodeCallback Dfs::noop_node_callback = [](const Dfs& dfs, const Node&) { };
Dfs::EdgeCallback Dfs::noop_edge_callback = [](const Dfs& dfs, const Edge&) { };

Dfs::Dfs(const Graph& graph,
         NodeCallback node_cb_1,
         NodeCallback node_cb_2,
         EdgeCallback edge_cb)
  : _graph{graph},
    _node_cb_1{node_cb_1},
    _node_cb_2{node_cb_2},
    _edge_cb{edge_cb},
    _is_discovered(graph.num_nodes(), false),
    _is_processing(graph.num_nodes(), false),
    _is_processed(graph.num_nodes(), false),
    _tick{-1},
    _entry_tick(graph.num_nodes(), -1),
    _exit_tick(graph.num_nodes(), -1),
    _parent_node(graph.num_nodes(), -1)
{ }

void Dfs::process (const Node& start_node)
{
  if (_is_processed[start_node]) {
    return;
  }

  _process_inner(start_node);
}

void Dfs::_process_inner (const Node& cur_node)
{
  _is_discovered[cur_node] = true;

  _tick++;
  _entry_tick[cur_node] = _tick;

  _node_cb_1(*this, cur_node);

  for (auto& edge : _graph.node_edges(cur_node)) {
    if (!_is_discovered[edge.to]) {
      _parent_node[edge.to] = cur_node;
      _edge_cb(*this, edge);
      _process_inner(edge.to);
    }
    else if ( (!_is_processed[edge.to] && (_parent_node[cur_node] != edge.to)) || _graph.is_directed()) {
      _edge_cb(*this, edge);
    }
  }

  _tick++;
  _exit_tick[cur_node] = _tick;
  _node_cb_2(*this, cur_node);

  _is_processed[cur_node] = true;
}

Node Dfs::parent (const Node& node) const
{ return _parent_node[node]; }


