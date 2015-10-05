#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

bool help(vector<int> &nums, int s, int e){
    if(s + 1 >= e) return true; // zero or one or two elements return true;
    int x = nums[s];
    int i = s + 1;
    for(;i <= e; i++)
        if(nums[i] > x) break;
    int mid = i;
    for(; i <= e; i++)
        if(nums[i] < x) return false;
    return help(nums, s+1, mid-1) && help(nums, mid, e);
}

bool isBSTPreorder(vector<int> nums){
    return help(nums, 0, nums.size()-1);
}

TreeNode *reconstruct(vector<int> &nums){
    if(nums.empty()) return NULL;
    stack<TreeNode *> st;
    TreeNode *root = new TreeNode(nums[0]);
    st.push(root);
    for(int i = 1; i < nums.size(); i++){
        TreeNode *cur = new TreeNode(nums[i]);
        TreeNode *p = st.top();
        st.pop();
        if(nums[i] < p->val){
            p->left = cur;
            st.push(p);
            st.push(cur);
        }else{
            while(!st.empty() && st.top()->val < nums[i]){
                p = st.top();
                st.pop();
            }
            p->right = cur;
            //st.push(p); //pay attention to this palace
            st.push(cur);
        }
    }
    return root;
}

int main()
{
    vector<int> nums={1};
    cout << isBSTPreorder(nums) << endl;
    nums={2,0};
    cout << isBSTPreorder(nums) << endl;
    nums={2,0,1,3,7};
    cout << isBSTPreorder(nums) << endl;
    nums={2,0,1,-1,3,7};
    cout << isBSTPreorder(nums) << endl;
    
    nums= {5,3,1,4,8,6,7,9};
    TreeNode *root = reconstruct(nums);
    return 0;
}
