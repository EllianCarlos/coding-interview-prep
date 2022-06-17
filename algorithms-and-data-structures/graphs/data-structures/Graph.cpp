#include <Graph.hpp>

Graph::Graph(int maxGraphSize)
{
  this->maxGraphSize = maxGraphSize;
  std::vector<std::pair<int, int>> createdAdjacencyMatrix[maxGraphSize];
  this->adjacencyMatrix = createdAdjacencyMatrix;
}

/**
 * @brief Connects two nodes in a direction graph given an weight.
 * 
 * If you want a bidirectional graph, extend or use this class in a class of your own
 * or just add two edges.
 * @example 
 * ```
 * // adding bidirectional edges
 * int src = 0;
 * int dest = 1;
 * graph.addEdge(src, dest);
 * graph.addEdge(dest, src);
 * ```
 * 
 * @param src - The node source
 * @param dest - The node destination
 * @param weight - Thw weight of the edge.
 */
void Graph::addEdge(int src, int dest, int weight = 0)
{
  if (this->actualGraphSize == this->maxGraphSize)
  {
    std::cout << "Tamanho máximo de grafo estourado" << std::endl;
    return;
  }

  this->adjacencyMatrix[src].emplace_back(dest, weight);
  return;
}

int Graph::getMaxGraphSize()
{
  return this->maxGraphSize;
}