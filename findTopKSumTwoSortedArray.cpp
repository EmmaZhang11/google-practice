#include <iostream>
#include <cmath>
#include <algorithm> // swap
#include <map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<int> getw(vector<int> a, vector<int> b) {
    int n = a.size();
    int cnt = 0;
    vector<int> res(n);
    priority_queue<pair<int, int> > q;
    unordered_set<int> st;
    st.insert(n*n-1);
    q.push(make_pair(a[n-1] + b[n-1], n*n - 1));
    while(cnt < n) {
        auto p = q.top();
        q.pop();
        res[cnt++] = p.first;
        int index = p.second;
        int x = index / n;
        int y = index % n;
        if(st.count(index-n) == 0)
            q.push(make_pair(a[x-1] + b[y], n * (x - 1) + y));
        if(st.count(index-1) == 0)
            q.push(make_pair(a[x] + b[y-1], n * x + y - 1));
    }
    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 4, 5};
    vector<int> ans = getw(a,b);
    return 0;
}
