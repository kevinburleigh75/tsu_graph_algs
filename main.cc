#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include "connected_components.h"
#include "cycle_detection.h"
#include "toposort.h"

#include <iostream>
#include <functional>

using namespace std;

int main ()
{
  Graph ug(13, false);

  ug.add_edge({0,1});
  ug.add_edge({1,2});
  ug.add_edge({3,4});
  ug.add_edge({4,5});
  ug.add_edge({6,7});
  ug.add_edge({7,8});
  ug.add_edge({0,3});
  ug.add_edge({1,4});
  ug.add_edge({2,5});
  ug.add_edge({3,6});
  ug.add_edge({4,7});
  ug.add_edge({5,8});
  ug.add_edge({9,10});
  ug.add_edge({9,11});

  Graph dg(13, true);

  dg.add_edge({0,1});
  dg.add_edge({0,3});
  dg.add_edge({1,2});
  dg.add_edge({1,4});
  dg.add_edge({2,5});
  dg.add_edge({3,6});
  dg.add_edge({4,3});
  dg.add_edge({4,5});
  dg.add_edge({4,7});
  dg.add_edge({5,8});
  dg.add_edge({6,7});
  dg.add_edge({7,8});
  dg.add_edge({9,10});
  dg.add_edge({9,11});

  if (false) {
    Bfs::NodeCallback ncb_1 = [](const Node& node) {
      cout << "node " << node << " cb 1" << endl;
    };
    Bfs::NodeCallback ncb_2 = [](const Node& node) {
      cout << "node " << node << " cb 2" << endl;
    };
    Bfs::EdgeCallback ecb = [](const Edge& edge) {
      cout << "edge (" << edge.from << "," << edge.to << ") cb" << endl;
    };

    Bfs bfs(ug, ncb_1, ncb_2, ecb);
    bfs.process(0);
    bfs.process(11);
    bfs.process(10);
    bfs.process(12);
  }

  if (false) {
    auto components = ConnectedComponents::process(ug);
    for (auto& component : components) {
      cout << component << endl;
    }
  }

  if (false) {
    Dfs::NodeCallback ncb_1 = [](const Dfs& dfs, const Node& node) {
      cout << "node " << node << " cb 1" << endl;
    };
    Dfs::NodeCallback ncb_2 = [](const Dfs& dfs, const Node& node) {
      cout << "node " << node << " cb 2" << endl;
    };
    Dfs::EdgeCallback ecb = [](const Dfs& dfs, const Edge& edge) {
      cout << "edge (" << edge.from << "," << edge.to << ") cb" << endl;
    };

    Dfs dfs(ug, ncb_1, ncb_2, ecb);
    dfs.process(0);
    dfs.process(11);
    dfs.process(10);
    dfs.process(12);
  }

  if (false) {
    cout << "cycle starting at  0 = " << boolalpha << CycleDetection::process(ug,0) << endl;
    cout << "cycle starting at  1 = " << boolalpha << CycleDetection::process(ug,1) << endl;
    cout << "cycle starting at  9 = " << boolalpha << CycleDetection::process(ug,9) << endl;
    cout << "cycle starting at 12 = " << boolalpha << CycleDetection::process(ug,12) << endl;
  }

  if (false) {
    Dfs::NodeCallback ncb_1 = [](const Dfs& dfs, const Node& node) {
      cout << "node " << node << " cb 1" << endl;
    };
    Dfs::NodeCallback ncb_2 = [](const Dfs& dfs, const Node& node) {
      cout << "node " << node << " cb 2" << endl;
    };
    Dfs::EdgeCallback ecb = [](const Dfs& dfs, const Edge& edge) {
      cout << "edge (" << edge.from << "," << edge.to << ") cb" << endl;
    };

    Dfs dfs(dg, ncb_1, ncb_2, ecb);
    dfs.process(0);
    dfs.process(4);
    dfs.process(9);
    dfs.process(12);
  }

  if (true) {
    auto toposort = Toposort::process(dg);
    for (auto& node : toposort) {
      cout << node << " ";
    }
    cout << endl;
  }
}