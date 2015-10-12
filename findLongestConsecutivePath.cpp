#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

int dfs(unordered_map<int, int> &len, DirectedGraphNode* n){
    if(len.find(n->label) != len.end()) return len[n->label];
    len[n->label] = 1;
    for(auto nb: n->neighbors){
        if(nb->label == n->label + 1)
        {
            len[nb->label] = dfs(len, nb);
            len[n->label] = len[nb->label] + 1;
        }
    }
    return len[n->label];
}

int findLongestConsecutivePath(vector<DirectedGraphNode *> g){
    unordered_map<int, int> len;
    int ans = 0;
    for(auto &n : g){
        int l = dfs(len, n);
        ans = max(ans, l);
    }
    return ans;
}

int main() {
    /* 6->7->1->2->3->5
          |
          V
          8->9
     */
    DirectedGraphNode *n1 = new DirectedGraphNode(1);
    DirectedGraphNode *n2 = new DirectedGraphNode(2);
    DirectedGraphNode *n3 = new DirectedGraphNode(3);
    DirectedGraphNode *n5 = new DirectedGraphNode(5);
    DirectedGraphNode *n6 = new DirectedGraphNode(6);
    DirectedGraphNode *n7 = new DirectedGraphNode(7);
    DirectedGraphNode *n8 = new DirectedGraphNode(8);
    DirectedGraphNode *n9 = new DirectedGraphNode(9);
    n6->neighbors = vector<DirectedGraphNode*> {n7};
    n7->neighbors = vector<DirectedGraphNode*> {n1, n8};
    n1->neighbors = vector<DirectedGraphNode*> {n2};
    n2->neighbors = vector<DirectedGraphNode*> {n3};
    n3->neighbors = vector<DirectedGraphNode*> {n5};
    n8->neighbors = vector<DirectedGraphNode*> {n9};
    
    vector<DirectedGraphNode *> g= {n1, n2, n3, n5, n6, n7, n8, n9};
    int ans = findLongestConsecutivePath(g);
    return 0;
}
