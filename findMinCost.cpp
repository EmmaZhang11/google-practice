#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findMinCost(vector<vector<int>> nums){
    int m = nums.size();
    if(m == 0)return 0;
    int n = nums[0].size();
    int ans = INT_MAX;
    queue<pair<int,int>> q;
    vector<vector<bool>> v(m, vector<bool>(n,false));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(nums[i][j]){
                int id = i * n + j;
                q.push(make_pair(id,0));
                v[i][j] = true;
            }
            else break;
        }
    }
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int i = p.first / n, j = p.first % n, h = p.second;
        if(i - 1 >= 0 && nums[i-1][j] && !v[i-1][j]){
            int id = (i - 1) * n + j;
            q.push(make_pair(id, h+1));
            v[i-1][j] = true;
            for(int l = 1; j+l < n || j-l >= 0; j++){
                if(j-l >= 0 && nums[i-1][j-l] && !v[i-1][j-l]){
                    int id = (i - 1) * n + j - l;
                    q.push(make_pair(id, h+1));
                    v[i-1][j-l] = true;
                }
                if(j+l < n && nums[i-1][j+l] && !v[i-1][j+l]){
                    int id = (i - 1) * n + j + l;
                    q.push(make_pair(id, h+1));
                    v[i-1][j+l] = true;
                }
            }
            
        }
        if(i + 1 < m && nums[i+1][j] && !v[i+1][j]){
            int id = (i + 1) * n + j;
            q.push(make_pair(id, h+1));
            v[i+1][j] = true;
            for(int l = 1; j+l < n || j-l >= 0; l++){
                if(j-l >= 0 && nums[i+1][j-l] && !v[i+1][j-l]){
                    int id = (i + 1) * n + j - l;
                    q.push(make_pair(id, h+1));
                    v[i+1][j-l] = true;
                }
                if(j+l < n && nums[i+1][j+l] && !v[i+1][j+l]){
                    int id = (i + 1) * n + j + l;
                    q.push(make_pair(id, h+1));
                    v[i+1][j+l] = true;
                }
            }
        }
        
        if(j == n - 1) ans = min(ans, h);
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1,1,1,0},{0,0,1,1}};
    int c = findMinCost(nums); // c = 1
    nums = {{1,1,1,0},{0,0,1,0},{0,0,1,1}};
    c = findMinCost(nums);  // c = 2
    nums = {{1,1,1,0},{0,0,1,0},{1,1,1,0},{0,1,1,1}};
    c = findMinCost(nums);  // c = 1
    return 0;
}
