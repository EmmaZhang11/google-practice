#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x){}
};

class solution{
public:
    //recursive
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(!root || !root->left) return root;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        TreeNode *nroot = upsideDownBinaryTree(root->left);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return nroot;
    }
    
    //iterative
    TreeNode *upsideDownBinaryTree2(TreeNode *root) {
        TreeNode* l;
        TreeNode* r;
        TreeNode* pleft = NULL;
        TreeNode* proot = NULL;
        
        while(root){
            l = root->left;
            r = root->right;
            root->left = pleft;
            root->right = proot;
            pleft = r;
            proot = root;
            root = l;
        }
        return proot;
    }
};

int main()
{
    TreeNode* tn = new TreeNode(1);
    tn->left = new TreeNode(2);
    tn->right = new TreeNode(3);
    tn->left->left = new TreeNode(4);
    tn->left->right = new TreeNode(5);
    solution s;
    //TreeNode* x = s.upsideDownBinaryTree(tn);
    TreeNode* y = s.upsideDownBinaryTree2(tn);
    return 0;
}
