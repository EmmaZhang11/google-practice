#include <iostream>
#include <queue>

using namespace std;
struct HeapNode{
    int val;
    HeapNode* left;
    HeapNode* right;
    HeapNode(int x): val(x), left(NULL), right(NULL){}
};

class Heap{
public:
    HeapNode* top();
    void pop();
};

struct cmp{
    bool operator()(HeapNode *h1, HeapNode *h2){
        return h1->val < h2->val;   //定义最大堆
    }
};
vector<int> findTopkWithoutChangeHeap(Heap h, int k){
    priority_queue<HeapNode *, vector<HeapNode *>, cmp> pq;
    vector<int> ans;
    HeapNode* hn = h.top();
    pq.push(hn);
    for(int i = 0; i < k; i++){
        HeapNode* tmp = h.top();
        h.pop();
        ans.push_back(tmp->val);
        HeapNode* l = tmp->left;
        HeapNode* r = tmp->right;
        pq.push(l);
        pq.push(r);
    }
    return ans;
}
