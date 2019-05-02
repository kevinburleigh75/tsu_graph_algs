#include "cycle_detection.h"
#include "dfs.h"

using namespace std;

bool CycleDetection::process(const Graph& graph, const Node& start_node)
{
  bool has_cycle = false;

  Dfs::EdgeCallback ecb = [&] (const Dfs& dfs, const Edge& edge) {
    if (dfs.parent(edge.to) != edge.from) {
      has_cycle = true;
    }
  };

  Dfs dfs(graph, Dfs::noop_node_callback, Dfs::noop_node_callback, ecb);
  dfs.process(start_node);

  return has_cycle;
}
