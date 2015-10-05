#include <iostream>
#include <vector>

using namespace std;

bool help(vector<int> &nums, int s, int e){
    if(s + 1 >= e) return true; // zero or one or two elements return true;
    int x = nums[s];
    int i = s + 1;
    for(;i <= e; i++)
        if(nums[i] > x) break;
    int mid = i;
    for(; i <= e; i++)
        if(nums[i] < x) return false;
    return help(nums, s+1, mid-1) && help(nums, mid, e);
}

bool isBSTPreorder(vector<int> nums){
    return help(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> nums={1};
    cout << isBSTPreorder(nums) << endl;
    nums={2,0};
    cout << isBSTPreorder(nums) << endl;
    nums={2,0,1,3,7};
    cout << isBSTPreorder(nums) << endl;
    nums={2,0,1,-1,3,7};
    cout << isBSTPreorder(nums) << endl;
    return 0;
}
