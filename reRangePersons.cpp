// 一排人从左到右排队，每个人有个身高，根据这个身高数组，生成一个新的数组，新数组的每一位记录当前的人左边有多少人的身高大于等于当前的人。
//现在假设有个pair数组，pair的第一位是身高，第二位是上面说的那个数组的值，把它们打乱了，根据这个数组生成这些人原来的排序

#include <iostream>
#include <vector>

using namespace std;

vector<int> reRangePersons(vector<pair<int,int>> nums){
    vector<int> ans;
    int n = nums.size();
    if(n == 0) return ans;
    sort(nums.begin(), nums.end(), greater<pair<int,int>>());
    ans.push_back(nums[0].first);
    for(int i = 1; i < n; i++){
        pair<int,int> p = nums[i];
        ans.insert(ans.begin() + p.second, p.first);
    }
    return ans;
}
    
               
int main(int argc, const char * argv[]) {
    vector<pair<int,int>> nums = {make_pair(1,1),make_pair(3,1),make_pair(2,4),make_pair(8,0),make_pair(9,0),make_pair(4,2)};
    vector<int> rest = reRangePersons(nums);
    return 0;
}
