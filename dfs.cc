#include "dfs.h"

#include <deque>
#include <tuple>
#include <utility>

using namespace std;

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
    _entry_tick(graph.num_nodes(), -1),
    _exit_tick(graph.num_nodes(), -1),
    _parent_node(graph.num_nodes(), -1)
{ }

void Dfs::process (const Node& start_node)
{
  deque<pair<Node,Edge>> stack;
  int tick = 0;
  const Edge null_edge{-1,-1};

  stack.push_back({start_node,null_edge});
  _is_discovered[start_node] = true;

  while (!stack.empty())
  {
    auto pair = stack.back();
    int  cur_node = pair.first;
    Edge cur_edge = pair.second;

    // Added to avoid confusion if process()
    // is called multiple times on previously
    // processed nodes.
    if (_is_processed[cur_node]) {
      stack.pop_back();
    }
    else if (_is_processing[cur_node]) {
      _node_cb_2(*this, cur_node);

      stack.pop_back();
      _exit_tick[cur_node] = tick;
      _is_processed[cur_node] = true;
    }
    else {
      _entry_tick[start_node] = tick;
      tick++;

      if (tie(cur_edge.from, cur_edge.to) != tie(null_edge.from, null_edge.to)) {
        _edge_cb(*this, cur_edge);
      }
      _node_cb_1(*this, cur_node);
      _is_processing[cur_node] = true;

      for (auto& edge : _graph.node_edges(cur_node)) {
        if (!_is_discovered[edge.to]) {
          stack.push_back({edge.to,edge});
          _is_discovered[edge.to] = true;
          _parent_node[edge.to] = cur_node;
        }
      }
    }
  }
}

Node Dfs::parent (const Node& node) const
{ return _parent_node[node]; }


