#include <iostream>

using namespace std;

struct IntervalTree{
    int start;
    int end;
    IntervalTree *left;
    IntervalTree *right;
    IntervalTree(int s, int e): start(s), end(e), left(NULL), right(NULL){}
};

class Solution {
public:
    IntervalTree *root;
    int cnt;
    
    Solution(){
        root = NULL;
    }
    
    IntervalTree * insert(IntervalTree *root, int start, int end){
        if(root == NULL){
            root = new IntervalTree(start, end);
            return root;
        }
        if(start < root->start)
            root->left = insert(root->left, start, end);
        else
            root->right = insert(root->right, start, end);
        return root;
    }
    
    void help(IntervalTree *root, int idx){
        if(root == NULL) return;
        if(idx >= root->start){
            if(idx <= root->end) cnt ++;
            help(root->left, idx);
            help(root->right, idx);
        }
        else
            help(root->left, idx);
    }
    
    bool isToggle(int idx){
        cnt = 0;
        help(this->root, idx);
        return cnt % 2;
    }
    
    void Toggle(int start, int end){
        root = insert(root, start, end);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.Toggle(2, 5);
    s.Toggle(6, 9);
    s.Toggle(1, 8);
    s.Toggle(7, 10);
    for(int i = 0 ; i <= 10; i++){
        bool rs = s.isToggle(i);
        if(rs) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
