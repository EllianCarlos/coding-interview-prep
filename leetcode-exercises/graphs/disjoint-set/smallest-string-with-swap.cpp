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

    bool isConnected(int src, int dest)
    {
        return find(src) == find(dest);
    }
    string s;
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
        int m = s.size();
        UnionFind uf(m);
        for (int i = 0; i < n; ++i)
        {
            uf.unionSet(pairs[i][0], pairs[i][1]);
        }
        
        string newStr;
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> mm; 
        
        for (int i = 0; i < m; ++i) {
            mm[uf.find(i)].push(s[i]);
        }
        
        for (int i = 0; i < m; ++i) {
            newStr += mm[uf.find(i)].top();
            mm[uf.find(i)].pop();
        }
        
        return newStr;
    }
};