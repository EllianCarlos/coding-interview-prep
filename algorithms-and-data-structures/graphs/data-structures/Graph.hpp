#include "../../../easy-imports/bits.cpp"

class Graph
{
public:
  void addEdge(int, int, int);
  Graph::Graph(int);
  int getMaxGraphSize();

private:
  int maxGraphSize;
  int actualGraphSize;
  std::vector<std::pair<int, int>> *adjacencyMatrix;
};