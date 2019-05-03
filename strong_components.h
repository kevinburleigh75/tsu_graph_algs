#ifndef __STRONG_COMPONENTS_H__
#define __STRONG_COMPONENTS_H__

#include "graph.h"

#include <vector>

class StrongComponents
{
private:
  StrongComponents ()                                        = delete;
  StrongComponents (const StrongComponents& orig)            = delete;
  StrongComponents& operator= (const StrongComponents& orig) = delete;
public:
  ~StrongComponents ()                                       = default;

public:
  static std::vector<int> process(const Graph& graph);

private:
  const Graph _graph;
};

#endif // __STRONG_COMPONENTS_H__
