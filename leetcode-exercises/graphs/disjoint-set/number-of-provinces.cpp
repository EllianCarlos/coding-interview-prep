#include <bits/stdc++.h>

using namespace std;


// Exercise: https://leetcode.com/explore/learn/card/graph/618/disjoint-set/3845/
class MySolution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    vector<int> root(n);
    int provinces = n;
    for (int i = 0; i < n; ++i)
    {
      root[i] = i;
    }

    for (int i = 1; i < n; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        if (isConnected[i][j] == 1)
        {
          if (root[i] != root[j])
          {
            --provinces;
            for (int k = 0; k < n; ++k)
            {
              if (root[k] == root[i])
                root[k] = root[j];
            }
          }
        }
      }
    }
    return provinces;
  }
};

// LeetCode Solution:
class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};