#include "connected_components.h"
#include "bfs.h"

using namespace std;

vector<int> ConnectedComponents::process(const Graph& graph)
{
  int comp_counter = 0;

  vector<bool> is_discovered(graph.num_nodes(), false);
  vector<Node> components(graph.num_nodes(), 0);

  Bfs::NodeCallback cb_1 = [&] (const Node& cur_node) {
    is_discovered[cur_node] = true;
    components[cur_node]    = comp_counter;
  };

  Bfs bfs(graph, cb_1);

  for (const Node& node : graph.nodes()) {
    if (!is_discovered[node]) {
      comp_counter++;
      bfs.process(node);
    }
  }

  return components;
}
