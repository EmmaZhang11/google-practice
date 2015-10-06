#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

TreeNode *treeToList(TreeNode *root){
    if(root == NULL) return NULL;
    stack<TreeNode *> st;
    while(root){
        st.push(root);
        root = root->left;
    }
    TreeNode *head = NULL, *pre = head;
    while(!st.empty()){
        TreeNode *tn = st.top();
        st.pop();
        if(pre == NULL) {pre = tn;head = pre;}
        else{
            pre->right = tn;
            tn->left = pre;
            pre = tn;
        }
        TreeNode *r = tn->right;
        while(r){
            st.push(r);
            r = r->left;
        }
    }
    return head;
}


int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    TreeNode *nr = treeToList(root);
    return 0;
}
