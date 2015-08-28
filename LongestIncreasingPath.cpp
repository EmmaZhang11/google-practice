#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


//二叉树上的最长递增路径

struct TreeNode{
	int val;
	int small;
	int big;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), small(-1), big(-1), left(NULL), right(NULL){}
};

int ans = 0;
void help(TreeNode *root){
	if (root == NULL) return;
	int sm = 0, bg = 0;
	if (root->left){
		help(root->left);	

		if (root->left->val <= root->val){
			sm = max(sm, root->left->small);
			ans = max(ans, sm + 1);
		}

		if (root->left->val >= root->val){
			bg = max(bg, root->left->big);
			ans = max(ans, bg + 1);
		}


	}
	if (root->right){
		help(root->right);	

		if (root->right->val <= root->val){
			sm = max(sm, root->right->small);
			ans = max(ans, sm + 1);
		}

		if (root->right->val >= root->val){
			bg = max(bg, root->right->big);
			ans = max(ans, bg + 1);
		}

	}

	root->small = sm + 1;
	root->big = bg + 1;

	if (root->left && root->right){
		if (root->val >= root->left->val && root->val <= root->right->val)
			ans = max(ans, root->left->small + root->right->big + 1);
		if (root->val <= root->left->val && root->val >= root->right->val)
			ans = max(ans, root->left->big + root->right->small + 1);

	}
	return;
}

int LongestIncreasingPath(TreeNode *root)
{
	help(root);
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(5); TreeNode *rr = new TreeNode(2);
	root->right = rr;
	rr->left = new TreeNode(1);
	rr->right = new TreeNode(3);
	cout << LongestIncreasingPath(root);
	return 0;
}
