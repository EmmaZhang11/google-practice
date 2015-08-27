#include <vector>
using namespace std;

struct TreeNode{
    int len;
    bool color; // false means black, true menas white
    vector<TreeNode *> children; // four children
    TreeNode(int l, bool c) : len(l), color(c){}
    TreeNode(int l) : len(l){}
};

bool isLeaf(TreeNode *root){
    for(auto it : root->children)
        if(it != NULL) return false;
    return true;
}

int help(TreeNode *root){
    if(root == NULL) return 0;
    if(isLeaf(root)){
        if(root->color) return 0;
        else return root->len * root->len;
    }
    int k = 0;
    for(auto ch : root->children){
        if(ch != NULL){
            k += help(ch);
        }
    }
    return k;
}

double findBlackPercent(TreeNode *root){
    int square = root->len * root->len;
    int black = help(root);
    return (double)black / square;
}


TreeNode * mergeTree(TreeNode *r1, TreeNode *r2){
    if(isLeaf(r1)){
        if(r1->color) return r1;
        else return r2;
    }
    if(isLeaf(r2)){
        if(r2->color) return r2;
        else return r1;
    }
    
    TreeNode * root = new TreeNode(r1->len,root->color);
    vector<TreeNode *> ch;
    for(int i = 0; i < 4; i++){
        ch.push_back(mergeTree(r1->children[i], r2->children[i]));
    }
    root->children = ch;
    return root;
}
