#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
public:
    UnionFind()
    {
    }

    string find(string node, int create = 1)
    {        
        if (root[node].empty() && create) 
        {
            root[node] = node;
            rank[node] = 1;
            assert(root[node] == node);
            assert(rank[node] == 1);
            values[node][node] = 1;
        }
        
        if (node == root[node])
        {
            return node;
        }
        
        string oldRoot = root[node];
        string newRoot = find(root[node]);
        root[node] = newRoot;
        
        values[node][newRoot] = values[node][oldRoot]*values[oldRoot][newRoot];
        values[newRoot][node] = 1.0/values[node][newRoot];
        
        return newRoot;
    }

    void unionSet(string src, string dest, double v, int create = 1)
    {
        values[src][dest] = v;
        values[dest][src] = 1/v;
        string rootSrc = find(src, create);
        double rootSrcToSrc = values[rootSrc][src];
        string rootDest = find(dest, create);
        double rootDestToDest = values[rootDest][dest];
        
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
            values[dest][rootSrc] = 1/(v*rootSrcToSrc);
            values[rootSrc][dest] = (v*rootSrcToSrc);
            values[src][rootDest] = v/rootDestToDest;
            values[rootDest][src] = rootDestToDest/v;
            values[rootSrc][rootDest] = (rootSrcToSrc * v)/rootDestToDest;
            values[rootDest][rootSrc] = rootDestToDest/(rootSrcToSrc * v);
        }
    }
    
    double getDiv(string a, string b) {
        if (values[a].empty() || values[b].empty()) return -1.0;
        if (a == b) return 1.0;
        if (isConnected(a, b)) {
            if (values[a][b] != 0.0 and values[a][b] < numeric_limits<double>::infinity()) return values[a][b];
            find(a);
            find(b);
            double aV = values[a][find(a)];
            double bV = values[b][find(a)];
            return aV/bV;
        }
        return -1.0;
    }
    
    bool isConnected(string src, string dest)
    {
        return find(src) == find(dest);
    }
private:
    map<string, string> root;
    map<string, int> rank;
    map<string, map<string, double>> values;
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionFind uf;
        
        for (int i = 0; i < equations.size(); ++i) {
            uf.unionSet(equations[i][0], equations[i][1], values[i]);
        }
        
        vector<double> ans;
        
        for (int i = 0; i < queries.size(); ++i) {
            ans.push_back(uf.getDiv(queries[i][0], queries[i][1]));
        }
        
        return ans;
    }
};