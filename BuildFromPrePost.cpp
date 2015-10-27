struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode *help(vector<int> &preorder, int s1, int e1, vector<int> &postorder, int s2, int e2){
	if(s1 == e1 && s2 == e2) return new TreeNode(preorder[s1]);
	if(preorder[s1+1] == postorder[e2-1]) return NULL;
	int i = s2;
	for(; i < e2; i++){
		if(postorder[i] == preorder[s1+1])
			break;
	}
	
	int llen = x - s2 + 1;

	TreeNode *root = new TreeNode(preorder[s1]);
	root->left = help(preorder, s1 + 1, s1 + llen, postorder, s2, i);
	if(root->left == NULL) return NULL;
	root->right = help(preorder, s1 + llen + 1, e1, i + 1, e2 - 1);
	if(root->right == NULL) return NULL;
	return root;
}

TreeNode *build(vector<int> preorder, vector<int> postorder){
	if(preorder.size() == 0 && postorder.size() == 0)return NULL;
	return help(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
}
