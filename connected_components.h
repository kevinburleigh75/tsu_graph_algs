#ifndef __CONNECTED_COMPONENTS_H__
#define __CONNECTED_COMPONENTS_H__

#include "graph.h"

#include <vector>

class ConnectedComponents
{
private:
  ConnectedComponents ()                                           = delete;
  ConnectedComponents (const ConnectedComponents& orig)            = delete;
  ConnectedComponents& operator= (const ConnectedComponents& orig) = delete;
public:
  ~ConnectedComponents ()                                          = default;

public:
  static std::vector<int> process(const Graph& graph);

private:
  const Graph _graph;
};

#endif // __CONNECTED_COMPONENTS_H__
