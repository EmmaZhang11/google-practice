/*given an array arr and an integer k, we have to generate 1 to N by adding some elements in arr. every num is only used for once when generate an specific number.
     we have to add numbers to achieve this goal. find the least add solution.
*/
    
    vector<int> addNumGenerateAll(vector<int> &nums, int k){
        vector<int> ans;
        ans.push_back(0);
        int sum = 0;
        int cur = 0;
        while(sum < k){
            if(cur >= nums.size() || (sum + 1 < nums[cur])){
                ans.push_back(sum+1);
                sum += sum + 1;
            }
            else{
                ans.push_back(nums[cur]);
                sum += nums[cur];
                cur++;
            }
        }
        ans.erase(ans.begin());
        return ans;
    }