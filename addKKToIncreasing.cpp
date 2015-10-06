#include <iostream>
#include <vector>

using namespace std;
#include <iostream>
#include <vector>

using namespace std;

int addKKToIncreasing(vector<int> nums){
    int ans = 0;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i-1]) continue;
        int x = nums[i-1] + 1 - nums[i];
        nums[i] = nums[i] + x;
        ans = max(ans, x);
    }
    return (ans + 1) / 2;
}

int main()
{
    vector<int> nums = {3,5,4,2,1,7};
    cout << addKKToIncreasing(nums) << endl;
    nums = {3,5,4,2,6,7};
    cout << addKKToIncreasing(nums) << endl;
    return 0;
}
