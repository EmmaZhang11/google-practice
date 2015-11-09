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
        vector<int> fa(n, -1);
        for(auto p : edges){
            int x = find(fa, p.first);
            int y = find(fa, p.second);
            if(x == y) return false;
            fa[x] = y;
        }
        return n-1 == edges.size();
    }
};

int main()
{
    Solution s;
    int n = 5;
    vector<pair<int, int>> edges = {make_pair(0, 1), make_pair(0, 2), make_pair(0, 3), make_pair(1,4)};
    bool r = s.validTree(n, edges); //true
    edges = {make_pair(0, 1), make_pair(1, 2), make_pair(2, 3), make_pair(1, 3), make_pair(1, 4)};
    r = s.validTree(n, edges); // false, has cycle
    edges = {make_pair(0, 1), make_pair(1, 2), make_pair(3, 4)};
    r = s.validTree(n, edges); //false, not connected
    return 0;
}
