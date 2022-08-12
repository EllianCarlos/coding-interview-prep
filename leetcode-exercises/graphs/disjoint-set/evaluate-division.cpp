#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
public:
    UnionFind(int size) : root(size), rank(size)
    {
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node)
    {
        if (node == root[node])
        {
            return node;
        }

        return root[node] = find(root[node]);
    }

    void unionSet(int src, int dest)
    {
        int rootSrc = find(src);
        int rootDest = find(dest);
        if (rootSrc != rootDest)
        {
            if (rank[rootSrc] > rank[rootDest])
            {
                root[dest] = rootSrc;
            }
            else if (rank[rootSrc] < rank[rootDest])
            {
                root[src] = rootDest;
            }
            else
            {
                root[dest] = rootSrc;
                rank[rootSrc] += 1;
            }
        }
    }

    bool isConnected(int src, int dest)
    {
        return find(src) == find(dest);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i)
        {
            uf.unionSet(pairs[i][0], pairs[i][1]);
        }
        string answer = "abc";
        return answer;
    }
};