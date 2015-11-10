#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int s = lower - 1, e = upper + 1;
        for(int i = 0; i+1 < nums.size(); i++){
            int ss = max(nums[i], s);
            int ee = min(nums[i+1], e);
            if(ss + 1 > ee - 1) continue;
            if(ss + 1 == ee - 1) ans.push_back(to_string(ss+1));
            else{
                string tmp = to_string(ss + 1) + "->" + to_string(ee - 1);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 3, 50, 75, 102};
    s.findMissingRanges(nums, 0 , 99);
    return 0;
}
