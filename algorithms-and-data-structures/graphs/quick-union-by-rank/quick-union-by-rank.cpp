#include "../../../easy-imports/bits.cpp"
#include "../data-structures/UnionFind.cpp"

using namespace std;

class QuickUnionByRank : public UnionFind
{
public:
  /**
   * @brief Construct a new Union Find object
   *
   * @param size The size of the set
   */
  QuickUnionByRank(int size) : UnionFind(size), rank(size)
  {
    for (int i = 0; i < size; ++i)
    {
      rank[i] = 1;
    }
  }
  /**
   * @brief Finds the parent of a node in the set.
   *
   * @param node The node to search for its parent.
   * @return int The parent of the node.
   */
  int find(int node) override
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
  void unionSet(int src, int dest) override
  {
    int rootSrc = find(src);
    int rootDest = find(dest);
    if (rootSrc != rootDest)
    {
      if (rank[rootSrc] > rank[rootDest])
      {
        root[rootDest] = rootSrc;
      }
      else if (rank[rootSrc] < rank[rootDest])
      {
        root[rootSrc] = rootDest;
      }
      else
      {
        root[rootDest] = rootSrc;
        rank[rootSrc] += 1;
      }
    }
  }

  /**
   * @brief Get the rank of a node
   *
   * @param node - The desired node to see the rank
   * @return int The rank of the node
   */
  int getRank(int node)
  {
    return rank[node];
  }

protected:
  /**
   * @brief Variable containing the rank of each node in its tree.
   */
  vector<int> rank;
};

int main(int argc, char *argv[])
{
  int numberOfNodes = 9;
  QuickUnionByRank graph(numberOfNodes);
  graph.unionSet(1, 2);
  graph.unionSet(1, 0);
  graph.unionSet(1, 4);

  graph.unionSet(5, 6);
  graph.unionSet(5, 7);

  /* Created Graph:
  //    __1__        5
  //   /  |  \      / \ 
  //  2   0   4    6  7
  */

  assert(graph.find(6) == 5);
  assert(graph.find(7) == 5);
  assert(graph.find(2) == 1);
  assert(graph.find(4) == 1);
  assert(graph.find(0) == 1);
  assert(graph.connected(4, 1) == true);
  assert(graph.connected(1, 5) == false);

  assert(graph.getRank(0) == 1);
  assert(graph.getRank(6) == 1);
  assert(graph.getRank(5) == 2);
  assert(graph.getRank(1) == 2);

  graph.unionSet(1, 5);

  assert(graph.find(6) == 1);
  assert(graph.find(7) == 1);
  assert(graph.find(5) == 1);
  assert(graph.connected(1, 5) == true);

  assert(graph.getRank(0) == 1);
  assert(graph.getRank(6) == 1);
  assert(graph.getRank(5) == 2);
  assert(graph.getRank(1) == 3);
}