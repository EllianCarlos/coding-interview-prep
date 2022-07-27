#ifndef UNION_FIND_C
#define UNION_FIND_C
#include "../../../easy-imports/bits.cpp"
using namespace std;

class UnionFind
{
public:
  /**
   * @brief Construct a new Union Find object
   *
   * @param size The size of the set
   */
  explicit UnionFind(int size) : root(size)
  {
    for (int i = 0; i < size; ++i)
    {
      root[i] = i;
    }
  }

  /**
   * @brief Finds the parent of a node in the set.
   *
   * @param node The node to search for its parent.
   * @return int The parent of the node.
   */
  virtual int find(int node)
  {
    return root[node];
  }

  /**
   * @brief Unites two nodes of the disjoint set
   */
  virtual void unionSet(int src, int dest)
  {
    int rootSrc = find(src);
    int rootDest = find(dest);

    if (rootSrc != rootDest)
    {
      // Updates all nodes with rootDest as root, because now rootDest has
      for (size_t i = 0; i < root.size(); ++i)
      {
        if (root[i] == rootDest)
        {
          root[i] = rootSrc;
        }
      }
    }
  }

  /**
   * @brief Finds if two nodes are connected
   */
  virtual bool connected(int x, int y)
  {
    return find(x) == find(y);
  }

protected:
  /**
   * @brief Variable containing the map from each node to its root. The node is represented by the index
   * and the root is data within that index.
   */
  vector<int> root;
};
#endif