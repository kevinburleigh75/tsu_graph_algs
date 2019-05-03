#include "strong_components.h"

#include "dfs.h"
#include "toposort.h"

#include <iostream>

using namespace std;

vector<int> StrongComponents::process(const Graph& graph)
{
  vector<Node> stack;

  {
    Graph rev_graph(graph.num_nodes(), true);
    for (auto& edge : graph.edges()) {
      rev_graph.add_edge({edge.to, edge.from});
    }

    vector<bool> is_discovered(graph.num_nodes(), false);

    Dfs::NodeCallback cb_1 = [&] (const Dfs& dfs, const Node& cur_node) {
      is_discovered[cur_node] = true;
    };

    Dfs::NodeCallback cb_2 = [&] (const Dfs& dfs, const Node& cur_node) {
      stack.push_back(cur_node);
    };

    Dfs dfs(rev_graph, cb_1, cb_2);

    for (auto& node : rev_graph.nodes()) {
      if (!is_discovered[node]) {
        dfs.process(node);
      }
    }
  }

  vector<Node> components(graph.num_nodes(), 0);

  {
    int comp_counter = 0;

    vector<bool> is_discovered(graph.num_nodes(), false);

    Dfs::NodeCallback cb_1 = [&] (const Dfs& dfs, const Node& cur_node) {
      is_discovered[cur_node] = true;
      components[cur_node]    = comp_counter;
    };

    Dfs dfs(graph, cb_1);

    while (!stack.empty()) {
      auto node = stack.back();
      stack.pop_back();

      if (!is_discovered[node]) {
        comp_counter++;
        dfs.process(node);
      }
    }
  }

  return components;
}
