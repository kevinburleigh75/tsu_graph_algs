#ifndef __CYCLE_DETECTION_H__
#define __CYCLE_DETECTION_H__

#include "graph.h"

#include <vector>

class CycleDetection
{
private:
  CycleDetection ()                                      = delete;
  CycleDetection (const CycleDetection& orig)            = delete;
  CycleDetection& operator= (const CycleDetection& orig) = delete;
public:
  ~CycleDetection ()                                     = default;

public:
  static bool process(const Graph& graph, const Node& start_node);
};

#endif // __CYCLE_DETECTION_H__
