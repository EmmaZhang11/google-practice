#include <iostream>
#include <vector>

using namespace std;

int LongestInterval(vector<int> nums){
    int ans = 0;
    int n = nums.size();
    vector<int> res(n, 0);
    res[n-1] = n-1;
    for(int i = n - 2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            res[i] = res[i+1];
            ans = max(ans, res[i] - i);
        }else{
            for(int j = res[i+1]; j > i; j--){
                if(nums[j] > nums[i]){
                    res[i] = j;
                    ans = max(ans, res[i] - i);
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3,5,4,2,1,7};
    cout << LongestInterval(nums) << endl;
    nums = {8,2,2,1,7};
    cout << LongestInterval(nums) << endl;
    return 0;
}
