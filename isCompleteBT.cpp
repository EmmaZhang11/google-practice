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
    queue<TreeNode *> q;
    q.push(root);
    bool sign = true;
    while(!q.empty()){
        TreeNode * tn = q.front();
        q.pop();
        if(tn->left) q.push(tn->left);
        if(tn->right) q.push(tn->right);
        if(sign){
            if(tn->left == NULL && tn->right != NULL) return false;
            if(tn->right == NULL) sign = false;
        }
        else{
            if(tn->left != NULL || tn->right != NULL) return false;
        }
    }
    return true;
}

int countNodes(TreeNode* root) {
	if(!root)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isCompleteTree2(TreeNode* root, int index, int num) {
	if(!root)
		return true;
	if(index >= num)
		return false;
	return isCompleteTree2(root->left, 2*index + 1, num) && isCompleteTree2(root->right, 2*index+2, num);
}
bool isCompleteTree2(TreeNode *root) {
	int num = countNodes(root);
	return isCompleteTree2(root, 0, num);

}

int main()
{
    cout << isCompleteBT(NULL);
    TreeNode *root = new TreeNode(0);
    cout << isCompleteBT(root);
    root->right = new TreeNode(2);
    cout << isCompleteBT(root);
    root->left = new TreeNode(3);
    cout << isCompleteBT(root);
    root->left->right = new TreeNode(4);
    cout << isCompleteBT(root);
    return 0;
}
