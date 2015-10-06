#include <iostream>
#include <vector>

using namespace std;

int LongestSequenceI(vector<int> nums){
    // time O(n^2) space O(n)
    int n = nums.size();
    if(n == 0) return 0;
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i ; j++){
            if(nums[j] < nums[i])
                dp[i] = max(dp[j]+1, dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int LongestSequenceII(vector<int> nums){
    // time O(nlgn) space O(n)
    int n = nums.size();
    if(n == 0) return 0;
    vector<int> hash(n + 1, -1);
    hash[1] = 0;
    int ans = 1;
    for(int i = 1; i < n; i++){
        int s = 0, e = i+1;
        while(s+1 < e){
            int m = (s + e) / 2;
            if(hash[m] == -1) e = m - 1;
            else{
                int x = nums[hash[m]];
                if(nums[i] > x){
                    if(nums[i] < nums[hash[m+1]])
                        s = m;
                    else s = m+1;
                }
                else e = m - 1;
            }
        }
        s++;
        ans = max(ans, s);
        if(hash[s] == -1)hash[s] = i;
    }
    return ans;
}

int main()
{
    vector<int> nums = {3,5,4,2,1,7};
    cout << LongestSequenceI(nums) << endl;
    cout << LongestSequenceII(nums) << endl;
    nums = {3,5,4,2,6,7};
    cout << LongestSequenceI(nums) << endl;
    cout << LongestSequenceII(nums) << endl;
    return 0;
}
