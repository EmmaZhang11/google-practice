/*找出missing number 范围. 
number范围[0,99]

input: [0, 1, 2,50 , 52, 75]
output: "3-49,51,53-74,76-99"
*/


string missingRange(vector<int> &nums){
        int n = nums.size();
        string ans;
        for(int i = 0; i <= n; i++){
            int start = 0;
            if(i > 0) start = nums[i-1] + 1;
            int end = 100;
            if(i < n) end = nums[i];
            if(start + 1 <= end){
                if(start + 1 == end){
                    ans += ",";
                    ans += to_string(start);
                }
                else{
                    string tmp = "," + to_string(start) + "-" + to_string(end - 1);
                    ans += tmp;
                }
            }
        }
        if(ans[0] == ',')
            ans = ans.substr(1);
        return ans;

    }