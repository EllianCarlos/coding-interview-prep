#include "../../../easy-imports/bits.cpp"
#include "../data-structures/UnionFind.hpp"

using namespace std;

class QuickUnionFind : public UnionFind
{
public:
  using UnionFind::UnionFind;
  /**
   * @brief Finds the parent of a node in the set.
   *
   * @param node The node to search for its parent.
   * @return int The parent of the node.
   */
  int find(int node)
  {
    while (node != root[node])
    {
      node = root[node];
    }

    return root[node];
  }

  /**
   * @brief Unites two nodes of the disjoint set
   * Quick union doesn't optimize the union command.
   */
  void unionSet(int src, int dest)
  {
    int rootSrc = find(src);
    int rootDest = find(dest);
    if (rootSrc != rootDest)
    {
      root[rootDest] = rootSrc;
    }
  }
};

int main(int argc, char *argv[])
{
  int numberOfNodes = 9;
  QuickUnionFind graph(numberOfNodes);
  graph.unionSet(1, 2);
  graph.unionSet(1, 0);
  graph.unionSet(1, 4);

  graph.unionSet(5, 6);
  graph.unionSet(5, 7);

  // Created Graph:
  //    __1__        5
  //   /  |  \      / \ 
  //  2   0   4    6  7
  //

  assert(graph.find(6) == 5);
  assert(graph.find(7) == 5);
  assert(graph.find(2) == 1);
  assert(graph.find(4) == 1);
  assert(graph.find(0) == 1);
  assert(graph.connected(4, 1) == true);
  assert(graph.connected(1, 5) == false);

  graph.unionSet(1, 5);

  assert(graph.find(6) == 1);
  assert(graph.find(7) == 1);
  assert(graph.find(5) == 1);
  assert(graph.connected(1, 5) == true);
}