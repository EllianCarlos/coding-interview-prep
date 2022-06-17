#include "../../../easy-imports/bits.cpp"
#include "../data-structures/UnionFind.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  int numberOfNodes = 9;
  UnionFind graph(numberOfNodes);
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