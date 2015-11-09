#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int> &fa, int k){
        if(fa[k] == -1) return k;
        return find(fa, fa[k]);
    }
    bool validTree(int n, vector<pair<int, int>>& edges){
        //Union -find
        vector<int> fa(n, -1);
        for(auto p : edges){
            int x = find(fa, p.first);
            int y = find(fa, p.second);
            if(x == y) return false;
            fa[x] = y;
        }
        return n-1 == edges.size();
    }
    
    bool hasCycle(vector<vector<int>> &g, vector<int> &v, int k, int p){
        //dfs 使用后向边和parent
        if(v[k] == 1) return true;
        v[k] = 1;
        for(int i : g[k]){
            if(i != p && hasCycle(g, v, i, k))
                return true;
        }
        v[k] = 2;
        return false;
    }
    
    bool validTree2(int n, vector<pair<int, int>>& edges){
        //dfs
        vector<vector<int>> g(n);
        vector<int> v(n, 0);
        for(pair<int,int> p : edges){
            g[p.first].push_back(p.second);
            g[p.second].push_back(p.first);
        }
        
        //cycle
        if(hasCycle(g, v, 0, -1))
            return false;
        //connected
        for(int i = 0; i < n; i++)
            if(v[i] != 2)
                return false;
        return true;
    }
 
};

int main()
{
    Solution s;
    int n = 5;
    vector<pair<int, int>> edges = {make_pair(0, 1), make_pair(0, 2), make_pair(0, 3), make_pair(1,4)};
    cout << s.validTree2(n, edges); //true
    edges = {make_pair(0, 1), make_pair(1, 2), make_pair(2, 3), make_pair(1, 3), make_pair(1, 4)};
    cout << s.validTree2(n, edges); // false, has cycle
    edges = {make_pair(0, 1), make_pair(1, 2), make_pair(3, 4)};
    cout << s.validTree2(n, edges); //false, not connected
    return 0;
}
