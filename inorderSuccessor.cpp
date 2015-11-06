//Recursive Version
TreeNode* inorderSuccessor(TreeNode *root, TreeNode* p){
    if(root == NULL) return NULL;
    if(p->val > root->val) return inorderSuccessor(root->right, p);
    TreeNode *l = inorderSuccessor(root->left, p);
    if(l) return l;
    else return root;
}

//Iterative Version
TreeNode* inorderSuccessor2(TreeNode *root, TreeNode* p){
    TreeNode* candidates = NULL;
    while(root){
        if(root->val > p->val){
            candidates = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return candidates;
}
