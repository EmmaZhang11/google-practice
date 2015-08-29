// 把一個不平衡的bst变平衡

#include <iostream>
#include <vector>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

vector<int> inorderTraversal(TreeNode *root){
    vector<int> ans;
    if(root == NULL) return ans;
    ans = inorderTraversal(root->left);
    ans.push_back(root->val);
    vector<int> r = inorderTraversal(root->right);
    ans.insert(ans.end(), r.begin(), r.end());
    return ans;
}

TreeNode *buildBalancedBST(vector<int> &inorder, int start, int end){
    if(start > end) return NULL;
    if(start == end) return new TreeNode(inorder[start]);
    int m = ( start + end ) / 2;
    TreeNode *root = new TreeNode(inorder[m]);
    root->left = buildBalancedBST(inorder, start, m - 1);
    root->right = buildBalancedBST(inorder, m + 1, end);
    return root;
}

TreeNode * balanceBST(TreeNode *root){
    vector<int> ans = inorderTraversal(root);
    return buildBalancedBST(ans, 0, ans.size() - 1);
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    TreeNode * test = balanceBST(root);
    return 0;
}
