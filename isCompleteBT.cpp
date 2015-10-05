#include <iostream>
#include <vector>
#include <queue>
#include <cmath> //pow

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

bool isCompleteBT(TreeNode *root){
    if(root == NULL) return true;
    queue<pair<TreeNode *,int>> q;
    q.push(make_pair(root,0));
    int pre = 0;
    int curCnt = 0;
    while(!q.empty()){
        pair<TreeNode *, int> p = q.front();
        q.pop();
        if(p.second == pre) curCnt++;
        else{
            if(curCnt != pow(2, pre)) return false;
            pre = p.second;
            curCnt = 1;
        }
        TreeNode *tn = p.first;
        if(tn->left) q.push(make_pair(tn->left, p.second+1));
        if(tn->right) q.push(make_pair(tn->right, p.second+1));
    }
    if(curCnt == pow(2, pre)) return true; // don't forget this
    else return false;
}

int main()
{
    cout << isCompleteBT(NULL);
    TreeNode *root = new TreeNode(0);
    cout << isCompleteBT(root);
    root->left = new TreeNode(2);
    cout << isCompleteBT(root);
    root->right = new TreeNode(3);
    cout << isCompleteBT(root);
    return 0;
}
