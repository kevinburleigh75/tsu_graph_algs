#include "bfs.h"

#include <deque>

using namespace std;

Bfs::Bfs(const Graph& graph,
         NodeCallback node_cb_1,
         NodeCallback node_cb_2,
         EdgeCallback edge_cb)
  : _graph{graph},
    _node_cb_1{node_cb_1},
    _node_cb_2{node_cb_2},
    _edge_cb{edge_cb},
    _is_discovered(graph.num_nodes(), false),
    _is_processed(graph.num_nodes(), false),
    _parent_node(graph.num_nodes(), -1)
{ }

void Bfs::process(const Node& start_node)
{
  deque<int> queue;

  queue.push_back(start_node);
  _is_discovered[start_node] = true;

  while (!queue.empty())
  {
    Node cur_node = queue.front();
    queue.pop_front();

    // Added to avoid confusion if process()
    // is called multiple times on previously
    // processed nodes.
    if (_is_processed[cur_node]) {
      continue;
    }

    _node_cb_1(cur_node);
    _is_processed[cur_node] = true;

    for (auto& edge : _graph.node_edges(cur_node)) {
      if (!_is_processed[edge.to] || _graph.is_directed()) {
        _edge_cb(edge);
      }

      if (!_is_discovered[edge.to]) {
        queue.push_back(edge.to);
        _is_discovered[edge.to] = true;
        _parent_node[edge.to] = cur_node;
      }
    }

    _node_cb_2(cur_node);
  }
}
