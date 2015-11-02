#include <iostream>
#include <vector>

using namespace std;

vector<int> findmaxRect(int n, int m, vector<pair<int, int>> lines){
    //pair.first = 0表示平行线， pair.first = 1表示竖直线
    vector<int> ans;
    vector<int> x = {0, n}, y = {0, m};
    int h = n, w = m;
    for(auto p: lines){
        if(p.first == 0){
            h = 0;
            for(int i = 0; i < x.size() - 1; i++){
                if(p.second > x[i] && p.second < x[i+1])
                    x.insert(x.begin() + i + 1, p.second);
                h = max(x[i+1] - x[i], h);
            }
            ans.push_back(h * w);
        }else{
            w = 0;
            for(int i = 0; i < y.size() - 1; i++){
                if(p.second > y[i] && p.second < y[i+1])
                    y.insert(y.begin() + i + 1, p.second);
                w = max(y[i+1] - y[i], w);
            }
            ans.push_back(h * w);
        }
    }	
    return ans;
}

int main()
{
    vector<pair<int, int>> lines = {make_pair(0,1), make_pair(1,3), make_pair(1,5), make_pair(0,3)};
    vector<int> as = findmaxRect(5,6, lines);
    return 0;
}
