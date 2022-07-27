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
  explicit UnionFind(int size);

  /**
   * @brief Finds the parent of a node in the set.
   *
   * @param node The node to search for its parent.
   * @return int The parent of the node.
   */
  int find(int node);

  /**
   * @brief Unites two nodes of the disjoint set
   */
  void unionSet(int src, int dest);

  /**
   * @brief Finds if two nodes are connected
   */
  bool connected(int x, int y);

protected:
  /**
   * @brief Variable containing the map from each node to its root. The node is represented by the index
   * and the root is data within that index.
   */
  vector<int> root;
};