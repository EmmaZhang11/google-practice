Recursive Version

int findNext(TreeNode *root, int target){
  if(root == NULL) return INT_MAX;
  if(target > root->val) return findNext(root->right, target);
  int v = root->val;
  v = min(v, findNext(root->left, target));
  return v;
}


Iterative Version
int findNext(TreeNode *root, int target){
  if(root == NULL) return INT_MAX;
  int v = INT_IMAX;
  while(root){
      if(target < root->val){
          v = min(v, root->val);
          root = root->left;
      }
      else
          root = root->right;
    }
    return v;
}
