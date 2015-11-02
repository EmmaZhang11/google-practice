#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > findPartLine(vector<pair<int, int>> points){
    pair<int, int> left = points[0];
    int id = 0;
    for(int i = 1; i < points.size(); i++){
        if(points[i].first < left.first){
            left = points[i];
            id = i;
        }
    }
    vector<pair<double, int>> slope;
    int zheng = 0;
    for(int i = 0; i < points.size(); i++){
        if(i != id){
            if(points[i].first == left.first){
                if( points[i].second > left.second) zheng = i;
                else zheng = -1 * i;
            }else{
                double tmp = double(points[i].second - left.second) /  double(points[i].first - left.first);
                slope.push_back(make_pair(tmp, i));
            }
        }
    }
    sort(slope.begin(), slope.end());
    if(zheng < 0) slope.insert(slope.begin(), make_pair(-1, zheng * (-1)));
    if(zheng > 0) slope.push_back(make_pair(1, zheng));
    int t = slope[slope.size()/2].second; //可改进的地方，求中位数用quick select
    vector<pair<int,int>> ans = {left, points[t]};
    return ans;
}

int main()
{
    vector<pair<int, int>> points = {make_pair(0,0),make_pair(0,1), make_pair(1,2), make_pair(2,1),make_pair(3,3), make_pair(2,-4)};
    vector<pair<int,int>> ans = findPartLine(points); // (0,0) (3,3)
    points = {make_pair(0,0),make_pair(0,1), make_pair(1,2), make_pair(2,-4)};
    ans = findPartLine(points); // (0,0) (1,2)
    return 0;
}
