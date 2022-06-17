quick_find: union-find.a
	g++ algorithms-and-data-structures/graphs/quick-find/quick-find.cpp dist/union-find.a -o dist/quick-find.o

graph.a:
	g++ -c algorithms-and-data-structures/graphs/data-structures/Graph.cpp  -o dist/Graph.a

union-find.a:
	g++ -c algorithms-and-data-structures/graphs/data-structures/UnionFind.cpp -o dist/union-find.a

clean:
	$(RM) *.o *.out *.a