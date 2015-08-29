//Find a pair with given sum in a Balanced BST

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
	TreeNode *r;
	stack<TreeNode *> st1, st2;

	void init(){
		TreeNode *ln = r;
		while (ln){
			st1.push(ln);
			ln = ln->left;
		}
		TreeNode *rn = r;
		while (rn){
			st2.push(rn);
			rn = rn->right;
		}
	}

	bool hasNext(){
		return !st1.empty();
	}

	bool hasRNext(){
		return !st2.empty();
	}

	int next(){
		TreeNode *tmp = st1.top();
		st1.pop();
		TreeNode *rn = tmp->right;
		while(rn){
			st1.push(rn);
			rn = rn->left;
		}
		return tmp->val;
	}

	int rnext(){
		TreeNode *tmp = st2.top();
		st2.pop();
		TreeNode *ln = tmp->left;
		while(ln){
			st2.push(ln);
			ln = ln->right;
		}
		return tmp->val;
	}

public:
	bool findPairOfTargetSum(TreeNode *root, int target){
		r = root;
		init();
		int lVal = hasNext() ? next() : 0;
		int rVal = hasRNext() ? rnext() : 0;
		while (lVal < rVal){              //这里假设每个node的val是不一样的，所以通过大小判断lVal是否是在rVal前面
			int sum = lVal + rVal;
			if (sum == target) return true;
			else if (sum < target) lVal = hasNext() ? next() : 0;
			else rVal = hasRNext() ? rnext() : 0;
		}
		return false;
	}
};
