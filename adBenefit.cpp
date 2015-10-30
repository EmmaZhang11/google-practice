#include <iostream>
#include <vector>

using namespace std;

double adBenefit(vector<pair<int,int>> ads, int k){
    //first: benefit second: time
    struct compare{
        bool operator()(pair<int,int> p1, pair<int,int> p2){
            return (double)p1.first/(double)p1.second > (double)p2.first/(double)p2.second;
        }
    }cmp;
    sort(ads.begin(), ads.end(), cmp);
    double ans = 0;
    for(int i = 0; i < ads.size(); i++){
        if(ads[i].second <= k)ans += ads[i].first;
        else{
            ans += k * ((double)ads[i].first/(double)ads[i].second);
            break;
        }
        k = k - ads[i].second;
    }
    return ans;
}


int main ()
{
    vector<pair<int,int>> ads {make_pair(10,1), make_pair(20,1), make_pair(30,2),make_pair(50,1),make_pair(65,3),make_pair(100,3)};
    cout << adBenefit(ads, 5);
    return 0;
}
