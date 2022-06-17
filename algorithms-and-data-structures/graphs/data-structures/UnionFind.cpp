#include "UnionFind.hpp"

/**
 * @brief Construct a new Union Find object
 *
 * @param size The size of the set
 */
UnionFind::UnionFind(int size) : root(size)
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
int UnionFind::find(int node)
{
  return root[node];
}

/**
 * @brief Unites two nodes of the disjoint set
 */
void UnionFind::unionSet(int src, int dest)
{
  int rootSrc = find(src);
  int rootDest = find(dest);

  if (rootSrc != rootDest)
  {
    // Updates all nodes with rootDest as root, because now rootDest has
    for (int i = 0; i < root.size(); ++i)
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
bool UnionFind::connected(int x, int y)
{
  return find(x) == find(y);
}