#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

TreeNode *lastNodeInComplete(TreeNode *root){
    if(root == NULL) return root;
    TreeNode *cur = root;
    int l = 0, r = 0, rr = 0;
    while(cur){
        l++;
        cur = cur->left;
    }
    cur = root;
    TreeNode *ans = NULL;
    while(cur){
        r++;
        ans = cur;
        cur = cur->right;
    }
    if(l == r) return ans;
    cur = root->right;
    while(cur){
        rr++;
        cur = cur->left;
    }
    if((l - 1) == rr) return lastNodeInComplete(root->right);
    else return lastNodeInComplete(root->left);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    TreeNode *cur = lastNodeInComplete(root);
    return 0;
}
