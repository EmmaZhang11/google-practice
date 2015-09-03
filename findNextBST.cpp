// 给一个BST，并且每个节点有存父指针；给一个节点，让找到BST里值比这个节点大的最小的那个节点。

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x): val(x), left(NULL), right(NULL), parent(NULL){}
};

TreeNode *findNext(TreeNode *cur)
{
    if(cur == NULL) return NULL;
    if(cur->right){
        TreeNode *tmp = cur->right;
        while(tmp->left){
            tmp = tmp->left;
        }
        return tmp;
    }
    TreeNode *tmp = cur->parent;
    while(tmp->right == cur){
        cur = tmp;
        tmp = cur->parent;
    }
    return tmp;
}


int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(6);
    TreeNode *l = new TreeNode(2);
    l->left = new TreeNode(1);
    l->right = new TreeNode(4);
    l->right->left = new TreeNode(3);
    root->left = l;
    //set parent
    root->right->parent = root;
    l->parent = root;
    l->left->parent = l;
    l->right->parent = l;
    l->right->left->parent = l->right;
    TreeNode *test = findNext(l->right);
    return 0;
}
