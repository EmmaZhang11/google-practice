#include <iostream>
#include <cmath>
#include <algorithm> // swap
#include <map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.first > p2.first;
    }
};
vector<int> dijkstra(vector<vector<int>> matrix, int n, int start){
    vector<int> dis(n, INT_MAX);
    vector<bool> v(n,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        if(!v[p.second]){
            dis[p.second] = p.first;
            v[p.second] = true;
            for(auto k : matrix[p.second]){
                if(!v[k]){
                    pq.push(make_pair(p.first+1, k));
                }
            }
        }
    }
    return dis;
}

int main()
{
    int n = 6;
    vector<vector<int>> matrix(n);
    matrix[0] = {1, 4, 5};
    matrix[1] = {0, 2, 5};
    matrix[2] = {1, 3, 4};
    matrix[3] = {2};
    matrix[4] = {0, 2};
    matrix[5] = {0, 1};
    vector<int> ans = dijkstra(matrix, n, 2); // 2 1 0 1 1 2
    return 0;
}
