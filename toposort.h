#ifndef __TOPOSORT_H__
#define __TOPOSORT_H__

#include "graph.h"

#include <vector>

class Toposort
{
private:
  Toposort ()                                = delete;
  Toposort (const Toposort& orig)            = delete;
  Toposort& operator= (const Toposort& orig) = delete;
public:
  ~Toposort ()                               = default;

public:
  static std::vector<Node> process(const Graph& graph);
};

#endif // __TOPOSORT_H__
