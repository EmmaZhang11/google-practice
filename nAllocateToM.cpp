// 有n个item要分给m個人，item无区别，可以有人沒有，可以不分完, 求所有Solution

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> nAllocateToM(int n, int m){
    vector<vector<int>> ans;
    if(m == 0) {
        ans.push_back(vector<int>());
        return ans;
    }
    if(n == 0){
        vector<int> tmp(m, 0);
        ans.push_back(tmp);
        return ans;
    }
    for(int i = 0; i <= n; i++){
        vector<vector<int>> tmp = nAllocateToM(n - i, m - 1);
        for(auto vec : tmp){
            vec.insert(vec.begin(), i);
            ans.push_back(vec);
        }
        
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> c  = nAllocateToM(3,4);
    return 0;
}
