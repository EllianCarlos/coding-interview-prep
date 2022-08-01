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
        
        string r = find(root[node]);
        
        root[node] = r;
        
        return r;
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
        if (isConnected(a, b)) {
            double result = values[a][b];
            if (result == 0.0) {
                double aV = values[a][find(a)];
                double bV = values[b][find(a)];
                result = aV/bV;
            }
            return result;
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