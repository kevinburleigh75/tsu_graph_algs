#include "toposort.h"
#include "dfs.h"

using namespace std;

vector<Node> Toposort::process(const Graph& graph)
{
  vector<Node> stack;
  vector<bool> is_discovered(graph.num_nodes(), false);

  Dfs::NodeCallback ncb_1 = [&](const Dfs& dfs, const Node& node) {
    is_discovered[node] = true;
  };

  Dfs::NodeCallback ncb_2 = [&](const Dfs& dfs, const Node& node) {
    stack.push_back(node);
  };

  Dfs dfs(graph, ncb_1, ncb_2, Dfs::noop_edge_callback);

  for (auto& node : graph.nodes()) {
    if (!is_discovered[node]) {
      dfs.process(node);
    }
  }
  return stack;
}