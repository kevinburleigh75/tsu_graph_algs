#include "graph.h"
#include "bfs.h"
#include "connected_components.h"

#include <iostream>
#include <functional>

using namespace std;

int main ()
{
  Graph gg(13, false);

  gg.add_edge({0,1});
  gg.add_edge({1,2});
  gg.add_edge({3,4});
  gg.add_edge({4,5});
  gg.add_edge({6,7});
  gg.add_edge({7,8});
  gg.add_edge({0,3});
  gg.add_edge({1,4});
  gg.add_edge({2,5});
  gg.add_edge({3,6});
  gg.add_edge({4,7});
  gg.add_edge({5,8});
  gg.add_edge({9,10});
  gg.add_edge({9,11});

  Bfs::NodeCallback ncb_1 = [](const Node& node) {
    cout << "node " << node << " cb 1" << endl;
  };
  Bfs::NodeCallback ncb_2 = [](const Node& node) {
    cout << "node " << node << " cb 2" << endl;
  };
  Bfs::EdgeCallback ecb = [](const Edge& edge) {
    cout << "edge (" << edge.from << "," << edge.to << ") cb" << endl;
  };

  if (false) {
    Bfs bfs(gg, ncb_1, ncb_2, ecb);
    bfs.process(0);
    bfs.process(11);
    bfs.process(10);
    bfs.process(12);
  }

  auto components = ConnectedComponents::process(gg);
  for (auto& component : components) {
    cout << component << endl;
  }
}