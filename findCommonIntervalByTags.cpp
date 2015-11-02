#include <iostream>
#include <cmath>
#include <algorithm> // swap
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
struct Point{
    int x, s, tag;
    Point(int ss, int ee, int t): x(ss), s(ee), tag(t){}
};
struct Interval{
    int x, y, tag;
    Interval(int xx, int yy, int t): x(xx), y(yy), tag(t){}
};
struct compare{
    bool operator()(Point p1, Point p2){
        return p1.x < p2.x;
    }
}cmp;
vector<Interval> findCommonIntervalByTags(vector<Interval> intervals, vector<int> tags){
    vector<Interval> ans;
    vector<Point> vec;
    unordered_set<int> set;
    for(int i: tags) set.insert(i);
    for(Interval it : intervals){
        if(set.find(it.tag) != set.end()){
            vec.push_back(Point(it.x, 0, it.tag));
            vec.push_back(Point(it.y, 1, it.tag));
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    unordered_map<int, int> mp;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].s == 0){
            mp[vec[i].tag] = vec[i].x;
        }else{
            if(mp.size() == set.size()){
                ans.push_back(Interval(vec[i-1].x, vec[i].x, 0));
            }
            mp.erase(vec[i].tag);
        }
        
    }
    return ans;
}

int main()
{
    vector<Interval> intervals = {Interval(0,2,3), Interval(5,6,3), Interval(8,8,3), Interval(10,20,3),
                                Interval(0,1,4), Interval(3,6,4), Interval(12,15,4),
                                Interval(3,8,5), Interval(9,12,5), Interval(4,10,6),Interval(15,17,6)};
    vector<int> tags = {3,4,5};
    vector<Interval> ans = findCommonIntervalByTags(intervals, tags);
    return 0;
}
