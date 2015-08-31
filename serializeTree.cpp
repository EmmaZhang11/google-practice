//将多叉树序列化，通过网络传输到另一台机器，并恢复

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h> //strcpy
#include <assert.h> //assert

using namespace std;
struct TreeNode{
    int val;
    vector<TreeNode *> child;
    TreeNode(int v) : val(v){}
};


string serializeTree(TreeNode *root){
    string ans;
    if(root == NULL) return ans;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *tmp = q.front();
        q.pop();
        string s = to_string(tmp->val);
        for(auto c : tmp->child){
            q.push(c);
            s = s + "," + to_string(c->val);
        }
        ans = ans + " " + s;
    }
    return ans;
    
}

vector<string> splitNode(string node, const char *split){
    char *n = new char[node.size() + 1];
    strcpy(n, node.c_str());
    char *p = strtok(n, split);
    vector<string> ans;
    while(p){
        ans.push_back(p);
        p = strtok(NULL, split);
    }
    return ans;
}


TreeNode * deSerialize(string content){
    if(content.empty()) return NULL;
    queue<TreeNode *> q;
    vector<string> nodes = splitNode(content," ");
    vector<string> n = splitNode(nodes[0], ",");
    TreeNode *root = new TreeNode(stoi(n[0]));
    vector<TreeNode *> children;
    for(int i = 1; i < n.size(); i++){
        TreeNode *tmp = new TreeNode(stoi(n[i]));
        q.push(tmp);
        children.push_back(tmp);
    }
    root->child = children;
    for(int i = 1; i < nodes.size(); i++){
        n = splitNode(nodes[i], ",");
        TreeNode *t = q.front();
        q.pop();
        assert(t->val == stoi(n[0]));
         children.clear();
         for(int j = 1; j < n.size(); j++){
             TreeNode *tmp = new TreeNode(stoi(n[j]));
             q.push(tmp);
             children.push_back(tmp);
         }
         t->child = children;
    }
    return root;
}
    
               
int main(int argc, const char * argv[]) {
    TreeNode *n = new TreeNode(1);
    vector<TreeNode *> tmp;
    for(int i = 2; i <= 5; i++) tmp.push_back(new TreeNode(i));
    n->child = tmp;
    tmp[0]->child.push_back(new TreeNode(6));
    tmp[0]->child.push_back(new TreeNode(7));
    tmp[2]->child.push_back(new TreeNode(8));
    tmp[2]->child.push_back(new TreeNode(9));
    string content = serializeTree(n);
    cout << content << endl;
    TreeNode *root = deSerialize(content);
    return 0;
}
